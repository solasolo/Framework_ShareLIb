using System;
using System.Collections.Generic;
using System.Text;
using System.ServiceProcess;
using System.Diagnostics;
using System.Threading;
using System.Runtime.InteropServices;

namespace GLEO.OA.System
{
    public abstract class ConsoleService
    {
        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool AllocConsole();

        [DllImport("kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool FreeConsole();

        public abstract string ServiceName { get; }
        public abstract string DisplayName { get; }

        public ConsoleService()
        {
        }

        public void Run()
        { 
            string[] cmd_str = Environment.GetCommandLineArgs();

            if (cmd_str.Length > 1)
            {
                string path = cmd_str[0];

                if (cmd_str[1] == "/console")
                {
                    RunConsole();
                }
                else if (cmd_str[1] == "/install")
                {
                    ServiceInstall install = new ServiceInstall();

                    install.InstallService(path, this.ServiceName, this.DisplayName);
                }
                else if (cmd_str[1] == "/uninstall")
                {
                    ServiceInstall install = new ServiceInstall();

                    install.UnInstallService(this.ServiceName);
                }
            }
            else
            {
                RunService();
            }
        }

        private void RunService()
        {
            try
            {
                ServiceBase service = this.CreateService();
                service.ServiceName = ServiceName;

                ServiceBase.Run(service);
            }
            catch (Exception e)
            {
                EventLog.WriteEntry("Service[" + this.ServiceName + "]", e.Message, EventLogEntryType.Error);
                throw e;
            }
        }

        private void RunConsole()
        {
            AllocConsole();
            Console.WriteLine("Console Started");

            try
            {
                this.CreateConsole();
                while (true)
                {
                    Thread.Sleep(100);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.ReadKey();

            FreeConsole();
        }

        protected abstract ServiceBase CreateService();

        protected abstract void CreateConsole();
    }
}
