using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;

namespace GLEO.OA.System
{
    public class RemoteLoggerWriter : LoggerWriter
    {
        ILoggerWriter RemoteLogger;

        public RemoteLoggerWriter(string url)
        {
            if (ChannelServices.GetChannel("LoggerChannel") == null)
            {
                TcpClientChannel channel = new TcpClientChannel("LoggerChannel", null);
                ChannelServices.RegisterChannel(channel, true);
            }

            RemoteLogger = (ILoggerWriter)Activator.GetObject(typeof(ILoggerWriter), url);
        }

        public override void Log(LogInfo[] infos)
        {
            if (RemoteLogger != null)
            {
                RemoteLogger.Log(infos);
            }
        }
    }

}
