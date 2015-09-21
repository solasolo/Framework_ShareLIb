using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace GLEO.OA.System
{
    public class UDPLoggerWriter : ILoggerWriter
    {
        static byte[] RTLF;

        UdpClient Sender;
        IPEndPoint Address;
        Stream Buffer;
        byte[] TypeBuffer;

        public UDPLoggerWriter(string host, int port)
        {
            if (UDPLoggerWriter.RTLF == null)
            {
                UDPLoggerWriter.RTLF = new byte[2] { 0x0a, 0x0d };
            }

            this.Buffer = new MemoryStream();
            this.TypeBuffer = new byte[1];

            IPHostEntry iphost = Dns.GetHostEntry(host);
            foreach (IPAddress addr in iphost.AddressList)
            {
                if (addr.AddressFamily == AddressFamily.InterNetwork)
                {
                    this.Address = new IPEndPoint(addr, port);
                }
            }

            this.Sender = new UdpClient();
            this.Sender.Connect(this.Address);
        }

        public void Log(LogInfo[] infos)
        {
            byte[] stream = null;

            foreach (LogInfo info in infos)
            {
                this.TypeBuffer[0] = (byte)info.Type;
                Buffer.Write(this.TypeBuffer, 0, 1);

                stream = Encoding.UTF8.GetBytes(info.ToString());
                Buffer.Write(stream, 0, stream.Length);
                Buffer.Write(UDPLoggerWriter.RTLF, 0, 2);
            }

            stream = new byte[Buffer.Length];
            Buffer.Seek(0, SeekOrigin.Begin);
            Buffer.Read(stream, 0, (int)Buffer.Length);
            Buffer.SetLength(0);
            this.Sender.Send(stream, stream.Length);
        }
    }
}
