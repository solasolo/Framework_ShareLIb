using System;
using System.Collections.Generic;
using GLEO.DBUtility;
using GLEO.MES.Sys;
using System.Windows.Forms;

namespace PictureLib
{
    public partial class FrmOperationHistory : BaseControl, INavigation
    {
        public FrmOperationHistory(Form owner)
            : base(owner)
        {
            InitializeComponent();

            this.dataGridViewFx1.AutoGenerateColumns = false;
        }

        public void Up()
        {
        }

        public new void Right()
        {
        }

        public void Down()
        {
        }

        public new void Left()
        {
        }

        private void OpenList()
        {
            OperationCondition cond = new OperationCondition();
            if(this.comboBoxFx2.SelectedIndex > -1)
            {
                cond.Operation = (string)this.comboBoxFx2.SelectedItem;
            }
            else
            {
                cond.Operation = null;
            }

            if(this.comboBoxFx1.SelectedIndex > -1)
            {
                cond.UserID = (int)this.comboBoxFx1.Value;
            }
            else
            {
                cond.UserID = -1;
            }

            cond.StartTime = this.dateTimePicker1.Value.Date;
            cond.EndTime = cond.StartTime.AddDays(1);

            List<OperationAction> OperationList = (this.Db as IDBAction).QueryOperation(cond);
            this.dataGridViewFx1.DataSource = OperationList;
        }

        private void FrmOperationHistory_Load(object sender, EventArgs e)
        {
            this.LoadOperator();
            this.LoadOperateType();

            this.StandardDatePicker(this.dateTimePicker1);
        }

        private void LoadOperateType()
        {
            string sqls = "select distinct action from operation_log";
            ProxyDataReader readers = this.Db.ExecuteReader(sqls);

            using (readers)
            {
                while (readers.Read())
                {
                    string action = readers["action"].ToString();
                    comboBoxFx2.Items.Add(action);
                }
            }
            
            //this.comboBoxFx2.Items.AddRange(new object[] { "USER_LOGIN" });
        }

        private void LoadOperator()
        {
            string sql = "select id, name from operator";
            ProxyDataReader reader = this.Db.ExecuteReader(sql);

            using (reader)
            {
                while (reader.Read())
                {
                    string user = reader["name"].ToString();
                    int id = Convert.ToInt32(reader["id"]);
                    comboBoxFx1.SetItem(user, id);
                }
            }
        }

        private void comboBoxFx1_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.OpenList();
        }

        private void comboBoxFx2_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.OpenList();
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            this.OpenList();
        }
    }
}
