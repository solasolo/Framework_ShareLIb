using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace GLEO.UI
{
    public interface IExceptionHandle
    {
        void HandleException(Exception ex);
    }

    abstract public class SafeApplication
    {
        private Mutex InstanceMutex;

        protected Form MainForm;

        public bool SingleInstance;

        public SafeApplication()
        {
            this.MainForm = null;
            this.SingleInstance = true;

            Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);

            Application.ThreadException += new ThreadExceptionEventHandler(Application_ThreadException);
            AppDomain.CurrentDomain.UnhandledException += new UnhandledExceptionEventHandler(Domain_UnhandledException);

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
        }

        private void Domain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            if (e.ExceptionObject is Exception)
            {
                Exception ex = e.ExceptionObject as Exception;

                if (!e.IsTerminating)
                {
                    this.HandleException(ex);
                }
            }
        }

        private void Application_ThreadException(object sender, ThreadExceptionEventArgs e)
        {
            Exception ex = e.Exception;

            this.HandleException(ex);
        }

        private bool DoesAnInstanceRunning(string Identify)
        {
            bool Result = true;

            try
            {
                Mutex.OpenExisting(Identify);
            }
            catch
            {
                this.InstanceMutex = new Mutex(true, Identify);

                Result = false;
            }

            return Result;
        }

        protected virtual void HandleException(Exception ex)
        {
            WriteLog log = WriteLog.Instance;
            log.Write(ex);

            if (this.MainForm != null && this.MainForm is IExceptionHandle)
            {
                (this.MainForm as IExceptionHandle).HandleException(ex);
            }
            else
            {
                string message = ex.Message + "\t";

                MessageBox.Show(message, "程序错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void Run(string identify)
        {
            string home = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            WriteLog.Path = home + "\\" +identify + "\\ExceptionLog\\";

            bool HasInstance = this.DoesAnInstanceRunning(identify);

            if (!this.SingleInstance || !HasInstance)
            {
                try
                {
                    this.Start();
                }
                catch (Exception ex)
                {
                    this.HandleException(ex);
                }

                Environment.Exit(0);

                this.InstanceMutex.Close();
            }
            else
            {
                MessageBox.Show("系统已启动", "提示", MessageBoxButtons.OK);
            }
        }

        protected virtual void Prepare()
        {
        }

        protected virtual void Cleanup()
        {
        }

        protected abstract bool Start();
    }
}
