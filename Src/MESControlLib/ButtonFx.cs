using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GLEO.MES.Sys;

namespace GLEO.MES.UI
{
    public class ButtonFx : Button
    {
        private string _DefaultText;

        public string DefaultText
        {
            get { return _DefaultText; }
            set { _DefaultText = value; }
        }

        public ButtonFx()
        {

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            TransText();

            base.OnPaint(e);
        }

        protected void TransText()
        {
            string temp = TranslateLanguage.Instance.doTranslate(_DefaultText);
            if (!String.IsNullOrEmpty(temp))
            {
                this.Text = temp;
            }
        }

        public int PromissionId
        {
            get;
            set;
        }

    }
}
