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
    class ServerConnection : BaseSocket
    {
        private SocketServer Server;

        public ServerConnection(SocketServer server, Socket socket, IProtocolDecoder decoder)
            : base(socket)
        {
            this.Server = server;
            this.SetDecoder(decoder);

            this.Start();
        }

        protected override void DoException(Exception ex)
        {
            this.Server.DoException(ex);
        }

        protected override void DoReceivedData(MessageEnity msg)
        {
            this.Server.DoReceivedData(msg);
        }

        protected override void ResetConnection()
        {
            this.Server.CleanSocket(this);
        }
    }

    public class SocketServer
    {
        private int ConnectRetryTime = 500;
        private bool Running;

        private Thread AcceptThread;
        private Socket InnerSocket;
        private IPEndPoint EndPoint;
        private IProtocolDecoder Decoder;
        private MessageBuffer Buffer;

        private List<BaseSocket> Connections;
        private object ListLocker;

        public event SocketMessageDelegate OnDataReceived;
        public event SocketErrorDelegate OnError;
        
        public SocketServer(string host, int port)
            : base()
        {
            this.ListLocker = new Object();

            this.EndPoint = BaseSocket.MakeEndPoint(host, port);
            this.Decoder = new SimpleProtocolDecoder();
            this.Buffer = new MessageBuffer();
            this.Connections = new List<BaseSocket>();

            this.AcceptThread = new Thread(new ThreadStart(this.AcceptProc));
        }

        public void Listen()
        {
            this.InnerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            this.InnerSocket.Bind(this.EndPoint);
            this.InnerSocket.Listen(10);

            this.Running = true;
            this.AcceptThread.Start();
        }

        public void AcceptProc()
        {
            while(this.Running)
            {
                Socket socket = this.InnerSocket.Accept();

                BaseSocket bs = new ServerConnection(this, socket, this.Decoder);

                lock (this.ListLocker)
                {
                    this.Connections.Add(bs);
                }
            }        
        }

        public bool Connected
        {
            get 
            {
                return this.Connections.Count > 0;
            }
        }

        public void SetDecoder(IProtocolDecoder decoder)
        {
            this.Decoder = decoder;
        }

        public bool GetData(out int cmd, out MessageParser parser)
        {
            return this.Buffer.GetMessage(out cmd, out parser);
        }

        internal void DoException(Exception ex)
        {
            if (this.OnError != null)
            {
                this.OnError(this, new SocketErrorEventArgs(ex));
            }
        }

        internal void DoReceivedData(MessageEnity msg)
        {
            this.Buffer.SetMessage(msg);

            if (this.OnDataReceived != null)
            {
                this.OnDataReceived(this, new SocketMessageEventArgs());
            }
        }

        internal void CleanSocket(BaseSocket socket)
        {
            lock (this.ListLocker)
            {
                this.Connections.Remove(socket);
            }
        }
    }
}
