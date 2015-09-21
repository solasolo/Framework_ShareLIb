using GLEO.MES.Sys;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class DataGridViewCloumnLink : DataGridViewCloumnFx
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

        public DataGridViewCloumnLink(string name)
            : base(name)
        {
            this.Name = name;
            this.HeaderText = name;
            DefaultName = name;
            this.CellTemplate = new DataGridViewLinkCell();
        }

        public DataGridViewCloumnLink()
        {
            this.CellTemplate = new DataGridViewLinkCell();
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
