using System;
using System.Windows.Forms;
using GLEO.MES.Sys;

namespace GLEO.MES.UI
{
    /// <summary>
    /// Author Ls
    /// Date   UnKnown
    /// Version 1.0
    /// 
    /// EditBy Gk
    /// Date   2013.10.23
    /// Support I18N
    /// </summary>
    public class LabelFx : ThreadLabel
    {
        private string _DefaultText;

        public string DefaultText
        {
            get { return _DefaultText; }
            set { _DefaultText = value; }
        }

        public LabelFx()
        {

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            TransText();

            base.OnPaint(e);
        }


        protected void TransText() 
        {
            string temp = TranslateLanguage.Instance.doTranslate(this._DefaultText);

            if (!String.IsNullOrEmpty(temp))
            {
                this.Text = temp;
            }
        }
    }
}
