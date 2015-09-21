using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using GLEO.MES.Sys;
using Data;
using GLEO.MES.UI;


namespace TestMutiLang
{
    public partial class Form1 : Form
    {
        //[System.Runtime.InteropServices.DllImport("user32")]
        //private static extern IntPtr GetDC(IntPtr hWnd);

        //[DllImport("Unused", EntryPoint = "sethook")]
        //private static extern void sethook(IntPtr hwndParent);

        public Form1()
        {
            InitializeComponent();
            string s = DateTime.Now.ToString("yyyy-MM-dd  hh:mm:ss");
            textBoxFx1.Text = "2013-12-21";

            //创建contentProvider
            DBAssess db = new DBAssess();

            //初始化TranslateLanguage
            TranslateLanguage.Instance.SetContentProvider(db);

            IntPtr  handle= this.Handle;
            //Unused.Unused un = new Unused.Unused();
            //un.sethook(handle);//禁用ALT+F4等

            DataGridViewCell cell1 = new DataGridViewTextBoxCell();
            DataGridViewCell cell2 = new DataGridViewButtonCell();
            DataGridViewCell cell3 = new DataGridViewCheckBoxCell();
            DataGridViewCell cell4 = new DataGridViewLinkCell();

            //dataGridViewFx2.Columns.Add(DataGridViewCloumnFx.GetNewCloum("Login", cell1));
            //dataGridViewFx2.Columns.Add(DataGridViewCloumnFx.GetNewCloum("Exit", cell2));
            //dataGridViewFx2.Columns.Add(DataGridViewCloumnFx.GetNewCloum("User", cell3));
            //dataGridViewFx2.Columns.Add(DataGridViewCloumnFx.GetNewCloum("Pwd", cell4));

        }

        private void button1_Click(object sender, EventArgs e)
        {
            GLEO.MES.Sys.TranslateLanguage.Instance.CurrentLang = LanguageType.Chinese;
            this.Refresh();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            GLEO.MES.Sys.TranslateLanguage.Instance.CurrentLang = LanguageType.English;
            this.Refresh();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            GLEO.MES.Sys.TranslateLanguage.Instance.CurrentLang = LanguageType.Germany;
            this.Refresh();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            GLEO.MES.Sys.TranslateLanguage.Instance.CurrentLang = LanguageType.Japanese;
            this.Refresh();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //if (this.WindowState == FormWindowState.Maximized) 
            //{        
            //    this.WindowState = FormWindowState.Normal; 
            //} 
            //else 
            //{ 
            //    this.FormBorderStyle = FormBorderStyle.None; 
            //    this.WindowState = FormWindowState.Maximized; 
            //} 
        }

        private void buttonFx1_Click(object sender, EventArgs e)
        {
        }

        private void textBoxFx1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxFx1_TextChanged_1(object sender, EventArgs e)
        {

        }
    }
}
