using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using System.Net;
using System.Net.Sockets;
using System.Threading;

using GLEO.OA.System;

namespace RemoteLogConsole
{
    public class RemoteConsole : MarshalByRefObject, ILoggerWriter
    {
        ILoggerWriter Writer;

        public RemoteConsole(ILoggerManager logger)
        {
            Writer = new ConsoleLoggerWriter();
        }

        #region ILoggerWriter Members

        public void Log(LogInfo[] info)
        {
            lock (this)
            {
                this.Writer.Log(info);
            }
        }

        #endregion
    }

    class Program
    {
        private Queue<byte[]> MessageQueue;
        private ManualResetEvent MessageNotify;
        private Thread LogThread;

        static void Main(string[] args)
        {
            string IP = "127.0.0.1";
            int LogPort = 1111;

            if (args.Length > 0)
            {
                LogPort = Int32.Parse(args[0]);
            }

            Program prog = new Program();
            prog.Run(IP, LogPort);
        }

        public Program()
        {
            this.MessageNotify = new ManualResetEvent(false);
            this.MessageQueue = new Queue<byte[]>();
        }

        private void Run(string ip, int port)
        {
            IPEndPoint EndPoint;
		    UdpClient Client;
		    byte[] Buffer;

            Console.Title = "Logger Console";
            Console.WriteLine("Waitting for Log Message ...");

            TcpChannel tcpChan = new TcpChannel(port);
            ChannelServices.RegisterChannel(tcpChan, true);

            RemotingConfiguration.RegisterWellKnownServiceType(typeof(RemoteConsole), typeof(RemoteConsole).FullName, WellKnownObjectMode.Singleton);

            try
            {
                //IPAddress addr = IPAddress.Parse(ip);
                IPAddress addr = IPAddress.Any;

                EndPoint = new IPEndPoint(addr, port);
                Client = new UdpClient();
                Client.EnableBroadcast = true;
                Client.Client.Bind(EndPoint);

                this.LogThread = new Thread(new ThreadStart(this.LogProcess));
                this.LogThread.Start();

                while (true)
                {
                    Buffer = Client.Receive(ref EndPoint);

                    lock(this)
                    {
                        this.MessageQueue.Enqueue(Buffer);
                        this.MessageNotify.Set();
                    }

                    if (Console.KeyAvailable)
                    {
                        ConsoleKeyInfo ki = Console.ReadKey();
                        if (ki.Key == ConsoleKey.Escape) break;
                    }
                }

                this.LogThread.Abort();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                Console.WriteLine("\r\nPress any key to close...");
                Console.ReadLine();
            }
       }

        private void DoLog(byte[] buffer)
        {
            MessageType Type = MessageType.Information;
            string Msg = String.Empty;

            int Pos = 0;
            int StartPos = 0;
            int EndPos = -1;

            while (Pos < buffer.Length - 1)
            {
                if (buffer[Pos] < 0x0a)
                {
                    EndPos = Pos;
                    if (EndPos > StartPos)
                    {
                        Console.Write(Encoding.UTF8.GetString(buffer, StartPos, EndPos - StartPos));
                    }

                    Type = (MessageType)Enum.ToObject(typeof(MessageType), buffer[Pos]);
                    Console.ForegroundColor = ConsoleLoggerWriter.EventColorMap[Type];

                    Pos++;
                    StartPos = Pos;
                }
                else
                {
                    Pos++;
                }
            }

            EndPos = buffer.Length;
            if (EndPos > StartPos)
            {
                Console.Write(Encoding.UTF8.GetString(buffer, StartPos, EndPos - StartPos));
            }
        }

        private void LogProcess()
        {
            while(this.MessageNotify.WaitOne())
            {
                byte[] Buffer = null;

                try
                {
                    lock(this)
                    {
                        if(this.MessageQueue.Count > 0)
                        {
                            Buffer = this.MessageQueue.Dequeue();
                        }
                        else
                        {
                            this.MessageNotify.Reset();
                        }
                    }

                    if(Buffer != null)
                    {
                        this.DoLog(Buffer);
                    }
                }
                catch(Exception ex)
                {
                    Console.WriteLine(ex);
                }
            }
        }
    }

}
