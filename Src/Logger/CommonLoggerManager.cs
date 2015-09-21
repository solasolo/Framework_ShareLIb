using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Diagnostics;
using System.Net;

namespace GLEO.OA.System
{
    public abstract class LoggerWriter : ILoggerWriter
    {
        #region ILoggerWriter Members

        public abstract void Log(LogInfo[] infos);

        #endregion
    }

    public class BaseLogger : ILogger
    {
        private string _ModuleName = String.Empty;
        protected ILoggerManager Manager;
        private string ComputerName;

        public BaseLogger(ILoggerManager man, string module)
        {
            this.Manager = man;
            this._ModuleName = module;
            this.ComputerName = Dns.GetHostName();
        }

        #region ILogger Members

        public string ModuleName
        {
            get
            {
                return _ModuleName;
            }
        }

        public void Log(MessageType type, string msg)
        {
            LogInfo li = new LogInfo();

            li.Time = DateTime.Now;
            li.Type = type;
            li.Message = msg;
            li.ModuleName = this.ModuleName;
            li.Computer = this.ComputerName;

            (Manager as CommonLoggerManager).WriteLog(li);
        }

        public void Log(Exception e)
        {
            string Text = String.Empty;
            Exception ie = e.InnerException;

            Text = e.Message + "\nSource: " + e.Source + "\nTrace: " + e.StackTrace;

            if (ie != null)
            {
                Text += "\n" + ie.Message + "\nSource: " + ie.Source + "\nTrace: " + ie.StackTrace;
            }

            this.Log(MessageType.Error, Text);
        }
        
        #endregion
    }

    public class CommonLoggerManager : ILoggerManager, IDisposable
    {
        private bool Disposed;
        private Thread LogThread;

        private ManualResetEvent LogEvent;
        private ManualResetEvent QuittingEvent;
        private Queue<LogInfo> WorkingQueue;
        private Queue<LogInfo> WaitingQueue;

        private List<ILoggerWriter> Writers;
        private IDictionary<string, ILogger> ModuleLoggers;
        private LoggerWriter BackupWriter;

        static public CommonLoggerManager operator +(CommonLoggerManager me, ILoggerWriter writer)
        {
            me.AppendWriter(writer);

            return me;
        }

        public CommonLoggerManager()
        {
            this.LogThread = new Thread(new ThreadStart(LogThreadProc));
            this.LogEvent = new ManualResetEvent(false);
            this.QuittingEvent = new ManualResetEvent(false);

            this.WorkingQueue = new Queue<LogInfo>();
            this.WaitingQueue = new Queue<LogInfo>();

            this.Writers = new List<ILoggerWriter>();
            this.ModuleLoggers = new Dictionary<string, ILogger>();
            this.BackupWriter = new EventLoggerWriter();

            LogThread.Start();
        }

        ~CommonLoggerManager()
        {
            this.Shutdown();
        }

        public virtual void Shutdown()
        {
            this.QuittingEvent.Set();
        }

        internal void WriteLog(LogInfo info)
        {
            this.DoLog(info);
        }

        #region ILoggerManager Members

        public ILogger RegisterLogger(string module)
        {
            return GetLoggerByModule(module);
        }

        public void AppendWriter(ILoggerWriter writer)
        {
            this.Writers.Add(writer);
        }

        #endregion

        private void LogThreadProc()
        {
            while (!QuittingEvent.WaitOne(100, false))
            {
                try
                {
                    if (LogEvent.WaitOne(1000, false))
                    {
                        BatchLog();
                        LogEvent.Reset();
                    }
                    else
                    {
                        DoLog(null);
                    }
                }
                catch
                {

                }
            }
        }

        private ILogger GetLoggerByModule(string module)
        {
            ILogger Result = null;

            if (this.ModuleLoggers.ContainsKey(module))
            {
                Result = this.ModuleLoggers[module];
            }
            else
            {
                Result = this.CreateLogger(module);
                this.ModuleLoggers[module] = Result;
            }

            return Result;
        }

        protected virtual ILogger CreateLogger(string module)
        {
            return new BaseLogger(this, module);
        }

        protected virtual void DoLog(LogInfo info)
        {
            try
            {
                lock (WaitingQueue)
                {
                    if (info != null)
                    {
                        WaitingQueue.Enqueue(info);
                    }

                    if (!LogEvent.WaitOne(0, false))
                    {
                        if (WorkingQueue.Count == 0)
                        {
                            Queue<LogInfo> Temp;

                            Temp = WaitingQueue;
                            WaitingQueue = WorkingQueue;
                            WorkingQueue = Temp;
                        }

                        LogEvent.Set();
                    }
                }
            }
            catch
            {
                //TODO: Do Nothing
            }
        }

        protected virtual void BatchLog()
        {
            if (WorkingQueue.Count > 0)
            {
                LogInfo[] Infos = WorkingQueue.ToArray();
                WorkingQueue.Clear();

                foreach (ILoggerWriter writer in Writers)
                {
                    try
                    {
                        writer.Log(Infos);
                    }
                    catch (Exception ex)
                    {
                        try
                        {
                            LogInfo ErrorInfo = new LogInfo();

                            ErrorInfo.Type = MessageType.Error;
                            ErrorInfo.Message = "Error in Write Log: " + ex.Message;
                            ErrorInfo.Time = DateTime.Now;
                            ErrorInfo.ModuleName = Process.GetCurrentProcess().MainModule.ModuleName;

                            BackupWriter.Log(new LogInfo[1] { ErrorInfo });
                            // BackupWriter.Log(li);
                        }
                        catch
                        {
                            //
                        }
                    }
                }
            }
        }

        #region IDisposable Members

        public void Dispose()
        {
            this.Shutdown();
        }

        #endregion
    }
}
