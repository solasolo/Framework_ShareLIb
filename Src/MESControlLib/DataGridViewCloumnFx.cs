using GLEO.MES.Sys;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public  class DataGridViewCloumnFx : DataGridViewColumn
    {
        private string _DefaultName;

        public string DefaultName
        {
            get 
            {
                return _DefaultName;
            }

            set 
            { 
                _DefaultName = value;

                TransText();
            }
        }

        public DataGridViewCloumnFx(string name)
        {
            this.Name = name;
            this.CellTemplate = new DataGridViewTextBoxCell();
        }

        public DataGridViewCloumnFx()
        {
            this.CellTemplate = new DataGridViewTextBoxCell();
        }

        public virtual void TransText() 
        {
            string temp = TranslateLanguage.Instance.doTranslate(_DefaultName);

            if (!String.IsNullOrEmpty(temp))
            {
                this.HeaderText = temp;
            }
        }
    }
}
