using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GLEO.OA.System
{
    public class FileLoggerWriter : LoggerWriter
    {
        private string BasePath = String.Empty;

        public FileLoggerWriter(string path)
        {
            BasePath = path;
        }

        public override void Log(LogInfo[] infos)
        {
            foreach (LogInfo li in infos)
            {
                StreamWriter sr = new StreamWriter(this.BasePath + li.ModuleName + li.Time.ToString(" yyyy-MM-dd") + ".log", true);

                sr.WriteLine(li.ToString());
                sr.Flush();
                sr.Close();

            }
        }
    }
}
