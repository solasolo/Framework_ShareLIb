using GLEO.MES.Sys;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class DataGridViewCloumnButton : DataGridViewCloumnFx
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

        public DataGridViewCloumnButton(string name)
            : base(name)
        {
            this.Name = name;
            this.HeaderText = name;
            DefaultName = name;
            this.CellTemplate = new DataGridViewButtonCell();
        }

        public DataGridViewCloumnButton()
        {
            this.CellTemplate = new DataGridViewButtonCell();
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

