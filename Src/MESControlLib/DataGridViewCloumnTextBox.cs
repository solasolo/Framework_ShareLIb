using System;
using GLEO.MES.Sys;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class DataGridViewCloumnTextBox : DataGridViewCloumnFx
    {
        //private string _DefaultName;

        //public string DefaultName
        //{
        //    get { return _DefaultName; }
        //    set 
        //    { 
        //        _DefaultName = value;
        //        TransText();
        //    }
        //}

        public DataGridViewCloumnTextBox(string name)
            : base(name)
        {
            this.Name = name;
            this.HeaderText = name;
            DefaultName = name;
            this.CellTemplate = new DataGridViewTextBoxCell();
        }

        public DataGridViewCloumnTextBox()
        {
            this.CellTemplate = new DataGridViewTextBoxCell();
        }

        public override void TransText()
        {
            string temp = TranslateLanguage.Instance.doTranslate(DefaultName);
            if (!String.IsNullOrEmpty(temp))
            {
                this.HeaderText = temp;
            }
        }
    }
}
