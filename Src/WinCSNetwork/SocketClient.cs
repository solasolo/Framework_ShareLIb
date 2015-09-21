using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Xml;

namespace GLEO.MES.Network
{
    // State object for receiving data from remote device.
    public class StateObject
    {
        public const int BUFFER_SIZE = 1024;

        public Socket workSocket = null;
        public byte[] Buffer = new byte[BUFFER_SIZE];
    }

    public class SocketMessageEventArgs : EventArgs
    {
        private short _Code;
        private MessageParser _Parser;

        public short Code
        {
            get 
            { 
                return _Code; 
            }
        }

        public MessageParser Parser
        {
            get 
            {
                return _Parser;
            }
        }

        public SocketMessageEventArgs(MessageEnity msg)
        {
            _Code = msg.Code;

            _Parser = new MessageParser(msg.Data);
        }
    }

    public class SocketErrorEventArgs : EventArgs
    {
        private string _Message;

        public string Message
        {
            get
            {
                return _Message;
            }
        }

        public SocketErrorEventArgs(string msg)
        {
            _Message = msg;

        }    
    }

    //
    public delegate void SocketMessageDelegate(Object sender, SocketMessageEventArgs e);
    public delegate void SocketErrorDelegate(Object sender, SocketErrorEventArgs e);

    public class SocketClient
    {
        public const short HEART_BEAT_CMD = 9999;

        public event SocketMessageDelegate OnDataReceived;
        public event SocketErrorDelegate OnError;

        private Socket socket = null;
        private IPAddress ip = null;
        private IPEndPoint ipp = null;

        private bool _IsOnline;
        private bool Running = true;
        private DateTime WatchDogTime;
        private int HeartRate;
        private int ConnectRetryTime = 500;

        MessageParser Parser;

        //private object locker = new object();

        private SimpleProtocolEncoder encoder;
        private SimpleProtocolDecoder decoder;
        private StreamBuffer IncommingBuffer;
        private StreamBuffer buffer_de;

        private Queue<MessageEnity> MessageListRev;

        private Thread ReceiveThread;

        public bool IsOnline
        {
            get
            {
                return _IsOnline;
            }
        }

        public SocketClient()
        {
            this._IsOnline = false;

            //
            this.IncommingBuffer = new StreamBuffer();
            this.buffer_de = new StreamBuffer();

            this.encoder = new SimpleProtocolEncoder(buffer_de);
            this.decoder = new SimpleProtocolDecoder(IncommingBuffer);
            this.MessageListRev = new Queue<MessageEnity>();

            this.WatchDogTime = DateTime.Now;
            this.HeartRate = 20;

            this.Running = true;
            this.Init();

            this.ReceiveThread = new Thread(new ThreadStart(this.ReceiveProc));
        }

        ~SocketClient()
        {
            //
            this.Running = false;

            this.Dispose();
        }

        private void Dispose()
        {
            if (this.socket != null)
            {
                try
                {
                    this.socket.Shutdown(SocketShutdown.Both);
                    this.socket.Close();
                }
                catch (SocketException ex)
                {
                    //throw;
                }
            }
        }

        private void Init()
        {
            XmlDocument doc = new XmlDocument();
            string Path = AppDomain.CurrentDomain.BaseDirectory + "..\\Data\\L2ServiceConfig.xml";
            string host = "127.0.0.1";
            string portStr = "8888";

            doc.Load(Path);
            XmlElement root = doc.DocumentElement;
            XmlNodeList nodelist = root.ChildNodes;
            foreach (XmlNode node in nodelist)
            {
                if (node.Name.Equals("Server"))
                {
                    XmlNodeList list = node.ChildNodes;
                    foreach (XmlNode N in list)
                    {
                        switch (N.Name)
                        {
                            case "HMIIP":
                                host = N.InnerText;
                                break;

                            case "HMIPort":
                                portStr = N.InnerText;
                                break;

                            default:
                                break;
                        }
                    }
                }
            }


            // read ip, port

            int port = Convert.ToInt32(portStr);

            if (!IPAddress.TryParse(host, out ip))
            {
                IPHostEntry iphost = Dns.GetHostEntry(host);
                foreach (IPAddress addr in iphost.AddressList)
                {
                    if (addr.AddressFamily == AddressFamily.InterNetwork)
                    {
                        ip = addr;
                        break;
                    }
                }
            }

            if (ip != null)
            {
                ipp = new IPEndPoint(ip, port);
            }
            else
            {
                throw new Exception("无法定位服务器地址");
            }
        }

        private void SendHearBeat()
        {
            this.Send(HEART_BEAT_CMD, null);
        }

        public void Start()
        {
            this.ReceiveThread.Start();
        }

        public void AsyncStart()
        {
            this.Connect();

            this.AsyncReceive();
        }

        public MessageEnity GetData()
        {
            MessageEnity Result = null;

            lock (this.MessageListRev)
            {
                if (this.MessageListRev.Count > 0)
                {
                    Result = this.MessageListRev.Dequeue();
                }
            }

            return Result;
        }

        public void Send(short cmd, params object[] data)
        {
            SimpleProtocolEncoder encode = new SimpleProtocolEncoder();

            if (data != null)
            {
                foreach (object d in data)
                {
                    Type t = d.GetType();
                    if(typeof(String) == t)
                    {
                        encode.Add((string)d);
                    }
                    else if (typeof(Int32) == t)
                    {
                        encode.Add((Int32)d);
                    }
                }
            }

            byte[] str = encode.GetData(cmd);

            this.Send(str);
        }

        private void Send(byte[] data)
        {
            lock (this)
            {
                if (this.Running)
                {
                    try
                    {
                        if (this.socket != null && this._IsOnline)
                        {
                            this.socket.Send(data, 0, data.Length, SocketFlags.None);
                        }
                        else
                        {
                            //
                        }

                        this.WatchDogTime = DateTime.Now;
                    }
                    catch (SocketException ex)
                    {
                        this._IsOnline = false;

                        this.DoException(ex);
                    }
                    catch (Exception ex)
                    {
                        this.DoException(ex);
                    }
                }
            }
        }

        private void HandleReceivedData(byte[] data)
        {
            this.IncommingBuffer.SetData(data);

            MessageEnity msg = new MessageEnity();

            bool ret;
            do
            {
                ret = this.decoder.CheckData(ref msg);

                if (ret)
                {
                    if (this.OnDataReceived != null)
                    {
                        this.OnDataReceived(this, new SocketMessageEventArgs(msg));
                    }

                    //lock (this.MessageListRev)
                    //{
                    //    this.MessageListRev.Enqueue(msg);
                    //}
                }
            }
            while(ret);
        }

        private void ReceiveProc()
        { 
            while(Running)
            {
                if (!this._IsOnline)
                {
                    this.Connect();
                }

                int Count = this.socket.Available;
                
                if (Count > 0)
                { 
                    byte[] buf = new byte[Count];
                    this.socket.Receive(buf);

                    this.HandleReceivedData(buf);
                }

                if ((DateTime.Now - this.WatchDogTime).Seconds > this.HeartRate)
                {
                    this.SendHearBeat();
                }

                Thread.Sleep(ConnectRetryTime);
            }
        }

        private void AsyncReceive()
        {
            if (this.Running)
            {

                if (!this._IsOnline)
                {
                    this.Connect();
                }

                try
                {
                    if (this.socket != null && this._IsOnline)
                    {
                        StateObject state = new StateObject();
                        state.workSocket = this.socket;

                        // Begin receiving the data from the remote device.
                        this.socket.BeginReceive(state.Buffer, 0, StateObject.BUFFER_SIZE, 0, new AsyncCallback(ReceiveCallback), state);
                    }
                }
                catch (SocketException ex)
                {
                    this._IsOnline = false;

                    this.DoException(ex);
                }
                catch (Exception ex)
                {
                    this.DoException(ex);
                }
            }
        }

        private void ReceiveCallback(IAsyncResult ar)
        {
            // Retrieve the state object and the client socket from the asynchronous state object.
            StateObject state = (StateObject)ar.AsyncState;
            Socket client = state.workSocket;

            try
            {
                int bytesRead = client.EndReceive(ar);

                if (bytesRead > 0)
                {
                    byte[] data = new byte[bytesRead];
                    Array.Copy(state.Buffer, data, bytesRead);

                    this.HandleReceivedData(data);
                }
            }
            catch (SocketException ex)
            {
                this._IsOnline = false;
                this.DoException(ex);
            }
            catch (Exception ex)
            {
                // log and notify error
                this.DoException(ex);
            }
            finally
            {
                //
                while (!this._IsOnline)
                {
                    this.Connect();
                    Thread.Sleep(1000);
                    if (_IsOnline)
                    {
                        state.workSocket = this.socket;
                        client = this.socket;
                        break;
                    }
                }

                client.BeginReceive(state.Buffer, 0, StateObject.BUFFER_SIZE, 0, new AsyncCallback(ReceiveCallback), state);
            }
        }

        private void Connect()
        {
            this._IsOnline = false;

            while (!this._IsOnline)
            {
                try
                {
                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(ipp);

                    this._IsOnline = true;
                }
                catch (Exception ex)
                {
                    DoException(ex);
                }

                Thread.Sleep(this.ConnectRetryTime);
            }
        }

        private void DoException(Exception ex)
        {
            this.OnError(this, new SocketErrorEventArgs(ex.Message));
        }

    }
}
