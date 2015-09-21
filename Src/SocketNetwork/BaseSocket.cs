using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GLEO.MES.Network
{
    public interface IMessageBuffer
    {
        
    }

    public class StateObject
    {
        public const int BUFFER_SIZE = 1024;

        public Socket workSocket = null;
        public byte[] Buffer = new byte[BUFFER_SIZE];
    }

    public class SocketMessageEventArgs : EventArgs
    {
        public SocketMessageEventArgs()
        {
        }
    }

    public class SocketErrorEventArgs : EventArgs
    {
        private Exception _Exception;

        public Exception Exception
        {
            get
            {
                return _Exception;
            }
        }

        public SocketErrorEventArgs(Exception ex)
        {
            _Exception = ex;

        }
    }

    public delegate void SocketMessageDelegate(Object sender, SocketMessageEventArgs e);
    public delegate void SocketErrorDelegate(Object sender, SocketErrorEventArgs e);

    public class MessageBuffer 
    {
        private Queue<MessageEnity> MessageQueue;
        private object QueueLocker;

        public MessageBuffer()
        {
            this.MessageQueue = new Queue<MessageEnity>();

            this.QueueLocker = new Object();
        }

        public bool GetMessage(out int cmd, out MessageParser parser)
        {
            bool Result = false;

            cmd = 0;
            parser = null;

            lock (this.QueueLocker)
            {
                if (this.MessageQueue.Count > 0)
                {
                    MessageEnity enity = this.MessageQueue.Dequeue();
                    cmd = enity.Code;
                    parser = new MessageParser(enity.Data);

                    Result = true;
                }
            }

            return Result;
        }

        public void SetMessage(MessageEnity msg)
        {
            lock (this.QueueLocker)
            {
                this.MessageQueue.Enqueue(msg);
            }
        }
    }

    abstract public class BaseSocket
    {
        public const short HEART_BEAT_CMD = 9999;

        protected bool _IsOnline;
        private bool Running;
        private int HeartRate;
        private int ReceiveRate = 10;

        public event SocketMessageDelegate OnDataReceived;
        public event SocketErrorDelegate OnError;

        protected Socket InnerSocket;
        protected IPEndPoint EndPoint;

        private DateTime WatchDogTime;

        //MessageParser Parser;

        //private object locker = new object();

        private SimpleProtocolEncoder encoder;
        private IProtocolDecoder Decoder;
        private StreamBuffer IncommingBuffer;

        private Thread ReceiveThread;
        private object SendLocker;

        public bool IsOnline
        {
            get
            {
                return _IsOnline;
            }
        }

        public BaseSocket()
        {
            this._IsOnline = false;
            this.InnerSocket = null;
            this.EndPoint = null;

            this.Init();
        }

        public BaseSocket(Socket socket)
        {
            this._IsOnline = true;
            this.InnerSocket = socket;
            this.EndPoint = null;

            this.Init();
        }

        ~BaseSocket()
        {
            //
            this.Running = false;

            this.Dispose();
        }
        
        private void Init()
        {
            this.HeartRate = 20;

            this.IncommingBuffer = new StreamBuffer();
            this.Decoder = new SimpleProtocolDecoder();

            this.WatchDogTime = DateTime.Now;

            this.Running = true;
            this.SendLocker = new Object();
            this.ReceiveThread = new Thread(new ThreadStart(this.ReceiveProc));
        }

        public void SetDecoder(IProtocolDecoder decoder)
        {
            this.Decoder = decoder;
        }

        public void Start()
        {
            this.ReceiveThread.Start();
        }
        
        abstract protected void ResetConnection();

        protected void ReleaseConnection()
        {
             if (this.InnerSocket != null)
            {
                try
                {
                    this.InnerSocket.Shutdown(SocketShutdown.Both);
                    this.InnerSocket.Close();
                }
                catch (Exception ex)
                {
                    try
                    {
                        this.DoException(ex);
                    }
                    catch (Exception)
                    { 
                    }
                }
            }
       }

        private void Dispose()
        {
            this.ReleaseConnection();
        }

        protected virtual void DoException(Exception ex)
        {
            if (this.OnError != null)
            {
                this.OnError(this, new SocketErrorEventArgs(ex));
            }
        }

        protected virtual void DoReceivedData(MessageEnity msg)
        {
            if (this.OnDataReceived != null)
            {
                this.OnDataReceived(this, new SocketMessageEventArgs());
            }
        }
        
        private void SendHearBeat()
        {
            this.Send(HEART_BEAT_CMD, null);
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
            lock (this.SendLocker)
            {
                if (this.Running)
                {
                    try
                    {
                        if (this.InnerSocket != null && this._IsOnline)
                        {
                            this.InnerSocket.Send(data, 0, data.Length, SocketFlags.None);
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

            bool ret = true;
            do
            {
                ret = this.Decoder.CheckData(this.IncommingBuffer, ref msg);

                if (ret)
                {                   
                    this.DoReceivedData(msg);
                }
            }
            while(ret);
        }

        private void ReceiveProc()
        { 
            while(Running)
            {
                try
                {
                    if (!this._IsOnline)
                    {
                        this.ResetConnection();
                    }

                    int Count = this.InnerSocket.Available;

                    if (Count > 0)
                    {
                        byte[] buf = new byte[Count];
                        this.InnerSocket.Receive(buf);

                        this.HandleReceivedData(buf);
                    }

                    if ((DateTime.Now - this.WatchDogTime).Seconds > this.HeartRate)
                    {
                        this.SendHearBeat();
                    }
                }
                catch (Exception ex)
                {
                    try
                    {
                        this.DoException(ex);
                    }
                    catch (Exception)
                    {
                    }
                }

                Thread.Sleep(this.ReceiveRate);
            }
        }

        public void AsyncStart()
        {
            this.AsyncReceive();
        }

        private void AsyncReceive()
        {
            if (this.Running)
            {
                if (!this._IsOnline)
                {
                    this.ResetConnection();
                }

                try
                {
                    if (this.InnerSocket != null && this._IsOnline)
                    {
                        StateObject state = new StateObject();
                        state.workSocket = this.InnerSocket;

                        // Begin receiving the data from the remote device.
                        this.InnerSocket.BeginReceive(state.Buffer, 0, StateObject.BUFFER_SIZE, 0, new AsyncCallback(ReceiveCallback), state);
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
                    this.ResetConnection();

                    if (_IsOnline)
                    {
                        state.workSocket = this.InnerSocket;
                        client = this.InnerSocket;
                        break;
                    }
                }

                client.BeginReceive(state.Buffer, 0, StateObject.BUFFER_SIZE, 0, new AsyncCallback(ReceiveCallback), state);
            }
        }

        static public IPEndPoint MakeEndPoint(string host, int port)
        {
            IPEndPoint Result = null;
            IPAddress ip;

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
                Result = new IPEndPoint(ip, port);
            }
            else
            {
                throw new Exception("无法定位服务器地址");
            }

            return Result;
        }
    }
}
