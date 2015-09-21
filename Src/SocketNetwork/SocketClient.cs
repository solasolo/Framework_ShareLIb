using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Xml;

namespace GLEO.MES.Network
{
    public class SocketClient : BaseSocket
    {
        private int ConnectRetryTime = 500;

        MessageBuffer Buffer;

        public SocketClient(string host, int port)
            : base()
        {
            if(host == "0.0.0.0")
            {
                host = "127.0.0.1";
            }

            this.EndPoint = BaseSocket.MakeEndPoint(host, port);

            this.Buffer = new MessageBuffer();
        }

        public bool GetData(out int cmd, out MessageParser parser)
        {
            return this.Buffer.GetMessage(out cmd, out parser);    
        }

        protected override void DoReceivedData(MessageEnity msg)
        {
            this.Buffer.SetMessage(msg);

            base.DoReceivedData(msg);
        }

        override protected void ResetConnection()
        {
            this._IsOnline = false;

            while (!this._IsOnline)
            {
                try
                {
                    this.ReleaseConnection();

                    this.InnerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    this.InnerSocket.Connect(EndPoint);

                    this._IsOnline = true;
                }
                catch (Exception ex)
                {
                    DoException(ex);
                }

                if (!this._IsOnline)
                {
                    Thread.Sleep(this.ConnectRetryTime);
                }
            }
        }
    }
}
