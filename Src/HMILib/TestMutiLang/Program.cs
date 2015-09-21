using GLEO.DBUtility;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestMutiLang
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //未处理的异常集中处理
            Application.ThreadException += new ThreadExceptionEventHandler(UnhandleException_TE);
            Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);


            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        static void UnhandleException_TE(object sender, ThreadExceptionEventArgs t)
        {
            if (t.Exception is Exception)
            {
                MessageBox.Show("系统对象出错,请联系软件开发商!");
            }
        }
    }
}
