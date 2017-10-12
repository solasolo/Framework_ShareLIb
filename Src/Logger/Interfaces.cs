using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GLEO.OA.System
{
    public enum MessageType
    {
        Information,
        Message,
        Warning,
        Error,
        Critical,
        Trace,
        Debug,
    }

    [Serializable]
    public class LogInfo
    {
        public DateTime Time;
        public string ModuleName;
        public MessageType Type;
        public string Message;
        public string Computer;

        public override string ToString()
        {
            return String.Format("{1:HH:mm:ss.fff} [{0}] [{2}] {3}", this.Type.ToString(), this.Time, this.ModuleName, this.Message);
        }
    }

    public interface ILogger
    {
        string ModuleName { get; }

        void Log(MessageType type, string msg);
        void Log(Exception e);
    }

    public interface ILoggerManager
    {
        ILogger RegisterLogger(string module_name);

        void AppendWriter(ILoggerWriter writer);
    }

    public interface ILoggerWriter
    {
        void Log(LogInfo[] infos);
    }
}
