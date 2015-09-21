using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GLEO.UI
{
    public class WriteLog
    {
        private static volatile WriteLog _Instance;
        private static object Refer = new Object();

        private WriteLog()
        {
            GetDirPath();
        }

        public static string Path = string.Empty;

        public static WriteLog Instance
        {
            get
            {
                lock (Refer)
                {
                    if (_Instance == null)
                    {
                        _Instance = new WriteLog();
                    }
                }
                return _Instance;
            }
        }

        public void Write(string msg)
        {
            string fileName = DateTime.Now.ToString("yyMMdd") + ".log";
            string FullName = string.Empty;
            FullName = WriteLog.Path + fileName;

            try
            {
                FileStream stream = new FileStream(FullName, FileMode.Append, FileAccess.Write);
                StreamWriter write = new StreamWriter(stream);
                string content = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + "    " + msg;
                write.WriteLine(content);

                write.Close();
                stream.Close();
            }
            catch
            { 
            }
        }

        public void Write(Exception ex) 
        {
            Exception inner = ex.InnerException;

            this.Write("Message: " + ((inner == null) ? ex.Message : inner.Message));
            this.Write("StackTrace: " + ((inner == null) ? ex.StackTrace : inner.StackTrace));
        }

        private void GetDirPath()
        {
            string home = Environment.GetFolderPath(Environment.SpecialFolder.Personal);

            if (!Directory.Exists(WriteLog.Path))
            {
                Directory.CreateDirectory(WriteLog.Path);
            }
        }
    }
}
