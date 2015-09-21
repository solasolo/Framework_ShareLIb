using System;
using GLEO.MES.Sys;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class DataGridViewCloumnCheckBox : DataGridViewCloumnFx
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

        public DataGridViewCloumnCheckBox(string name)
            : base(name)
        {
            this.Name = name;
            this.HeaderText = name;
            DefaultName = name;
            this.CellTemplate = new DataGridViewCheckBoxCell();
        }

        public DataGridViewCloumnCheckBox()
        {
            this.CellTemplate = new DataGridViewCheckBoxCell();
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
