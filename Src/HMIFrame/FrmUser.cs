using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GLEO.DBUtility;
using System.Data.Common;
using GLEO.MES.UI;
using GLEO.MES.Sys;
using GLEO.UI;

namespace PictureLib
{
    public partial class FrmUser : BaseControl, IEdit
    {
        private string LoadUser;
        private DataSet OperatorDataSet;
        private DataGridViewFx dgv;

        private string pramaryPerfix;

        public FrmUser(MainFrame Owner)
        {
            this.SetOwner(Owner);

            InitializeComponent();

            dgv = this.dataGridViewFx1;
            setpramaryPerfix();
        }

        private void setpramaryPerfix()
        {
            if (this.Db is MsSqlDbSupport)
                pramaryPerfix = "@";
            if (this.Db is OracleDbSupport)
                pramaryPerfix = ":";
            if (this.Db is OleDbSupport)
                pramaryPerfix = "?";
            if (this.Db is FirebirdDbSupport)
                pramaryPerfix = "@";
        }

        private void loadOperator()
        {
            string sql = "select l.id,l.name,l.crew,l.code,r.role,r.id from operator l, role r where r.id = l.role and not name = 'admin'";

            OperatorDataSet = Db.RetrieveDataSet(sql);

            if (OperatorDataSet != null && OperatorDataSet.Tables.Count > 0)
            {
                DataTable dt = OperatorDataSet.Tables[0];
                if (dt != null)
                {
                    this.dataGridViewFx1.DataSource = dt;
                }
            }
        }

        public void Add()
        {
            DataTable dt = this.dataGridViewFx1.DataSource as DataTable;
            DataRow dr = dt.NewRow();
            dr["userid"] = (int)dt.Rows[dt.Rows.Count - 1]["userid"] + 1;
            dt.Rows.Add(dr);

            //OperationRecorder.Record("Add_Operator", null);
        }

        public void Delete()
        {
            DataRowView dav = (DataRowView)this.dataGridViewFx1.CurrentRow.DataBoundItem;
            string name = (string)dav["name"];

            string sql = "Delete from loginuser where username = " + this.pramaryPerfix + "username and not username = 'admin'";

            Db.SetParameter("username", name, CommonDBType.String);
            Db.ExecuteNonQuery(sql);
            this.loadOperator();

            //OperationRecorder.Record("Alter_Operator", null);
        }

        public bool Checkdata()
        {
            bool flag = true;
            DataTable tb = this.dataGridViewFx1.DataSource as DataTable;
            for (int i = 0; i < tb.Rows.Count; i++)
            {
                if (tb.Rows[i]["name"].ToString() == null || tb.Rows[i]["name"].ToString() == "")
                {
                    flag = false;
                    break;
                }
                //if (tb.Rows[i]["pwd"].ToString() == null || tb.Rows[i]["pwd"].ToString() == "")
                //{
                //    flag = false;
                //    break;
                //}
                if (tb.Rows[i]["code"].ToString() == null || tb.Rows[i]["code"].ToString() == "")
                {
                    flag = false;
                    break;
                }
                if (tb.Rows[i]["role"].ToString() == null || tb.Rows[i]["role"].ToString() == "")
                {
                    flag = false;
                    break;
                }
                if (tb.Rows[i]["crew"].ToString() == null || tb.Rows[i]["crew"].ToString() == "")
                {
                    flag = false;
                    break;
                }
            }

            return flag;
        }

        public void Save()
        {
            if (Checkdata())
            {
                DataTable dt = dataGridViewFx1.DataSource as DataTable;
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    string name = this.txtName.Text;
                    string code = this.txtCode.Text;
                    string crew = this.cbCrew.Text;
                    string role = this.cbRole.SelectedItem.ToString();

                    string sql = "Update operator set name = " + this.pramaryPerfix + "name, code = " + this.pramaryPerfix + "code, crew = " + this.pramaryPerfix + "crew, role = " + this.pramaryPerfix + "role where id = " + this.pramaryPerfix + "id";

                    Db.SetParameter("name", name, CommonDBType.String);
                    Db.SetParameter("role", role);
                    Db.SetParameter("code", code, CommonDBType.String);
                    Db.SetParameter("crew", crew);

                    Db.ExecuteNonQuery(sql);

                    this.loadOperator();
                }
            }
            else
            {
                MessageBox.Show("数据非法！");
            }
        }

        private void Close()
        {
            throw new NotImplementedException();
        }

        public void Alter()
        {
            UIFunctions.ReadOnly(panelFx1, false);
        }

        private void FrmUser_Load(object sender, EventArgs e)
        {
            this.loadOperator();

            string sqlss = "select distinct crew from operator";

            ProxyDataReader readerss = Db.ExecuteReader(sqlss);
            using (readerss)
            {
                while (readerss.Read())
                {
                    this.comboBoxFx1.Items.Add(readerss["crew"].ToString());
                }
            }


            string sql = "select * from role where not id = '0'";

            ProxyDataReader reader = Db.ExecuteReader(sql);
            using (reader)
            {
                while (reader.Read())
                {
                    this.cbRole.SetItem(reader["role"].ToString(), (Int32)reader["id"]);
                }
            }
            
            /*
            string sqls = "select * from crew";

            ProxyDataReader readers = Db.ExecuteReader(sqls);
            using (readers)
            {
                while (readers.Read())
                {
                    this.cbCrew.SetItem(readers["crew"].ToString(), (Int32)readers["id"]);
                }
            }
            */
        }

        private void comboBoxFx1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string sql = "select id,name,role,crew,code from operator where crew = " + this.pramaryPerfix + "crew and not name = 'admin'";
            string team = (string)this.comboBoxFx1.SelectedItem;
            Db.SetParameter("crew", team);
            OperatorDataSet = Db.RetrieveDataSet(sql);
            DataTable dt = OperatorDataSet.Tables[0];
            this.dataGridViewFx1.DataSource = dt.DefaultView;
        }

        private void dataGridViewFx1_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            EditCtrl.EditEnd();

            //string str = this.dataGridViewFx1.Columns[e.ColumnIndex].Name;

            //if (str == "password")
            //{
            //    DataGridViewRow dc = dgv.Rows[e.RowIndex];
            //    if (dc.Cells[e.ColumnIndex].Value != null && dc.Cells[e.ColumnIndex].Value.ToString().Length > 0)
            //    {
            //        dc.Cells[e.ColumnIndex].Value = UserManager.GetMD5Hash(dc.Cells[e.ColumnIndex].Value.ToString());
            //    }
            //}
        }

        private void dataGridViewFx1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            string id = this.dataGridViewFx1.SelectedCells[0].Value.ToString();
            this.Loaduser(id);
            UIFunctions.ReadOnly(panelFx1, true);
        }

        public void Loaduser(string id)
        {
            string sql = "select l.id,l.name,l.crew,l.code,l.role,r.id from operator l, role r where r.id = l.role and l.id = @id and not l.id = '0'";

            Db.SetParameter("@id", id);
            ProxyDataReader reader = Db.ExecuteReader(sql);

            using (reader)
            {
                if (reader.Read())
                {
                    this.txtName.Text = reader["name"].ToString();
                    this.txtCode.Text = reader["code"].ToString();
                    this.cbRole.Value = (Int32)reader["role"];
                    //this.cbCrew.Value = (Int32)reader["crew"];
                }
            }
        }

        //private void dataGridViewFx1_CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
        //{
        //    string str = this.dataGridViewFx1.Columns[e.ColumnIndex].Name;

        //    if (str == "password")
        //    {
        //        if (e.Value != null && e.Value.ToString().Length > 0)
        //        {
        //            e.Value = new string('*', 12);
        //        }
        //    }
        //}
    }
}
