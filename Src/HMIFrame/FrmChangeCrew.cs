using System;
using System.Windows.Forms;

namespace PictureLib
{
    public partial class FrmChangeCrew : Form
    {
        public FrmChangeCrew()
        {
            InitializeComponent();
        }

        private void cmdOk_Click(object sender, EventArgs e)
        {
        }

        private void cmdCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
