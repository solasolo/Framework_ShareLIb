using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PictureLib;
using GLEO.MES.Sys;
using GLEO.DBUtility;

namespace PictureLib
{
    public partial class FrmMultilang : BaseControl, IEdit
    {
        private DataSet LanguageDataSet;

        public FrmMultilang()
        {
            InitializeComponent();
        }

        private void Savedata()
        {
            string sql = "select origenalName,chinese,english,germany from multiylang";
            this.Db.Update(sql, LanguageDataSet);

            TranslateLanguage.Instance.Reload(); 
        }

        private void FrmMultilang_Load(object sender, EventArgs e)
        {
            string sql = "select origenalName,chinese,english,germany from multiylang";

            LanguageDataSet = this.Db.RetrieveDataSet(sql);
            DataTable dt = LanguageDataSet.Tables[0];
            this.dataGridViewFx1.DataSource = dt;
            this.dataGridViewFx1.AllowUserToAddRows = false;
        }

        private void dataGridViewFx1_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            EditCtrl.EditEnd();
        }

        #region Interface IEdit

        public void Add()
        {
        }

        public void Delete()
        {
        }

        public void Save()
        {
            this.Savedata();
        }

        public void Alter()
        {
        }

        #endregion

    }
}
