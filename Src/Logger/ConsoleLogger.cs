using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace GLEO.OA.System
{
    public class ConsoleLoggerWriter : LoggerWriter
    {
        [DllImport("Kernel32.dll")]
        private static extern IntPtr GetConsoleWindow();

        [DllImport("Kernel32.dll")]
        private static extern bool AllocConsole();

        static private IDictionary<MessageType, ConsoleColor> _EventColorMap;

        static private void BuildColorMap()
        {
            if (ConsoleLoggerWriter._EventColorMap == null)
            {
                ConsoleLoggerWriter._EventColorMap = new Dictionary<MessageType, ConsoleColor>();

                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Information, ConsoleColor.DarkGray);
                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Message, ConsoleColor.White);
                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Warning, ConsoleColor.Yellow);
                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Error, ConsoleColor.Red);
                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Trace, ConsoleColor.Cyan);
                ConsoleLoggerWriter._EventColorMap.Add(MessageType.Debug, ConsoleColor.Green);
            }
        }

        static public IDictionary<MessageType, ConsoleColor> EventColorMap
        {
            get
            {
                ConsoleLoggerWriter.BuildColorMap();

                return ConsoleLoggerWriter._EventColorMap;
            }
        }

        public ConsoleLoggerWriter()
        {
            ConsoleLoggerWriter.BuildColorMap();

            this.OpenConsole();
        }

        public override void Log(LogInfo[] infos)
        {
            foreach (LogInfo li in infos)
            {
                Console.ForegroundColor = ConsoleLoggerWriter._EventColorMap[li.Type];
                Console.WriteLine(li.ToString());
            }
        }

        private void OpenConsole()
        {
            IntPtr ConsoleHandle = GetConsoleWindow();
            if (ConsoleHandle.ToInt32() == 0)
            {
                if (AllocConsole())
                {
                    StreamWriter standardOutput = new StreamWriter(Console.OpenStandardOutput());
                    Console.SetOut(standardOutput);

                    StreamReader standardInput = new StreamReader(Console.OpenStandardInput());
                    Console.SetIn(standardInput);

                    StreamWriter standardError = new StreamWriter(Console.OpenStandardError());
                    Console.SetError(standardError);
                }
            }
        }
    }
}
