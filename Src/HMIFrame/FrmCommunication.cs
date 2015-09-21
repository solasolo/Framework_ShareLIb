using GLEO.MES.Network;
using System;
using System.Drawing;
using System.Windows.Forms;

namespace PictureLib
{
    public partial class FrmCommunication : Form
    {
        public FrmCommunication()
        {
            InitializeComponent();
        }

        public void Setdata(MessageEnity msg)
        {
            if (msg != null)
            {
                this.richTextBox1.ForeColor = Color.Green;

                int MID = msg.Code;
                byte[] Data = msg.Data;

                if (MID == 2003)
                {
                    MessageParser parser = new MessageParser(msg.Data);
                    this.richTextBox1.AppendText(msg.Code.ToString() + " id:" + parser.GetString() + " 参数 " + parser.GetString() + "\n");
                }
                else
                {
                    this.richTextBox1.AppendText(msg.Code.ToString() + "\n");
                }
            }
        }

        public void Setdata(string msg)
        {
            this.richTextBox1.ForeColor = Color.Red;

            this.richTextBox1.AppendText(msg + "\n");
        }
    }
}
