using System;
using System.Windows.Forms;
using GLEO.MES.UI;
using PictureLib;
using System.Data;
using GLEO.DBUtility;
using GLEO.MES.Sys;

namespace PictureLib
{
    public partial class FrmUserManager : BaseControl, IEdit
    {
        private IDBInterface Db;
        private string User;
        private DataGridViewFx dgv;
        private DataSet DS;
        private int Index;

        public FrmUserManager()
        {
            InitializeComponent();

            Index = 0;
            User = Global.SuperUser;
            dgv = this.dgvUser;

            Inint(); 
        }

        private void Inint()
        {
            DataGridViewFx dgv = this.dgvUser;
            dgv.ColumnHeadersDefaultCellStyle.Font = new System.Drawing.Font("SimHei", 11F);
            dgv.ColumnHeadersDefaultCellStyle.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;

            dgv.RowHeadersVisible = false;
            DataGridViewCloumnFx ID = new DataGridViewCloumnTextBox("ID");
            DataGridViewCloumnFx IDclom = new DataGridViewCloumnTextBox("SerialNumber");
            DataGridViewCloumnFx Userclom = new DataGridViewCloumnTextBox("User");
            DataGridViewCloumnFx Pwdclom = new DataGridViewCloumnTextBox("Pwd");

            ID.Visible = false;
            //IDclom.Visible = false;
            Userclom.Width = (dgv.Width/2)-1;
            Pwdclom.Width = (dgv.Width / 2) - 1;

            IDclom.DataPropertyName = "UserID";
            Userclom.DataPropertyName = "UserName";
            Pwdclom.DataPropertyName = "Pwd";

            dgv.Columns.Clear();
            dgv.Columns.Add(ID);
            dgv.Columns.Add(IDclom);
            dgv.Columns.Add(Userclom);
            dgv.Columns.Add(Pwdclom);

            
            #region 直接绑定
            //ProxyDataReader reader = db.ExecuteReader(Sql);
            //using (reader)
            //{
            //    while (reader.Read())
            //    {
            //        string UID = reader.GetString("UserID", "");
            //        string UName = reader.GetString("UserName", "");
            //        string Pd = reader.GetString("Pwd", "");
            //        dgv.Rows.Add(new object[] {UID, UName,Pd});
            //    }
            //} 
            #endregion
        }
        
        private void LoadData()
        {
            string Sql = "";
            if (User == Global.SuperUser)
            {
                Sql = "select UserID,UserName,Pwd from LoginUser";

                ToolButton toolbutton = new ToolButton();
                toolbutton.Add(ToolButton.ToolButtonType.NEW);
                toolbutton.Add(ToolButton.ToolButtonType.DELETE);
            }
            else
            {
                Sql = "select UserID,UserName,Pwd from LoginUser " + "where  UserName = '" + User + "'";
            }
            DS = this.Db.RetrieveDataSet(Sql);
            if (DS != null && DS.Tables.Count > 0)
            {
                if (DS.Tables[0] != null)
                    dgv.DataSource = DS.Tables[0];
            }
        }

        private void bt_Search_Click(object sender, EventArgs e)
        {
            string Condition = SearchCondition.Text;
            if (!string.IsNullOrEmpty(Condition))
            {
                if (User == Global.SuperUser)
                {
                    string Sql = "select UserID,UserName,Pwd from LoginUser where UserName Like '" + Condition + "%'";
                    DS = this.Db.RetrieveDataSet(Sql);
                    if (DS != null && DS.Tables.Count > 0)
                    {
                        if (DS.Tables[0] != null)
                            dgv.DataSource = DS.Tables[0];
                    }
                }
            }
            else 
            {
                this.LoadData();
            }
        }

        private void dgvUser_CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
        {
            if (e.ColumnIndex == 3)
            {
                if (e.Value != null && e.Value.ToString().Length > 0)
                {
                    e.Value = new string('*', 12);
                }
            }
        }

        private void dgvUser_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            EditCtrl.EditEnd();
        }

        private void FrmUserManager_Load(object sender, EventArgs e)
        {
            this.LoadData();
        }

        private bool CheckData() 
        {
           bool result = true;
           DataTable dt = this.DS.Tables[0];
           if (dt != null) 
           {
               foreach (DataRow dr in dt.Rows) 
               {
                   string id = dr["UserID"].ToString();
                   string name = dr["UserName"].ToString();
                   string pwd = dr["Pwd"].ToString();
                   if (string.IsNullOrEmpty(id) || string.IsNullOrEmpty(name) || string.IsNullOrEmpty(pwd)) 
                   {
                       //TODO: 输入错误
                       result = false;
                   }
               }
           }
           return result;
        }

        private void dgvUser_CellEndEdit_1(object sender, DataGridViewCellEventArgs e)
        {
            EditCtrl.EditEnd();
        }

        #region Interface IEdit

        public void Add()
        {
            if (User == Global.SuperUser)
            {
                if (Index > 0)
                {
                    this.Index = Index + 1;
                }
                DataTable dt = dgv.DataSource as DataTable;
                DataRow dr = dt.NewRow();
                DataTable MaxID = this.Db.RetrieveDataTable("select Max(UserID) as ID from LoginUser");
                if (MaxID != null)
                {
                    if (Index == 0)
                    {
                        dr["UserID"] = (int)MaxID.Rows[0]["ID"] + 1;
                        Index = 1;
                    }
                    else
                    {
                        dr["UserID"] = (int)MaxID.Rows[0]["ID"] + Index;
                    }
                    dt.Rows.Add(dr);
                }
            }
        }

        public void Delete()
        {
            if (User == Global.SuperUser)
            {
                if (dgv.CurrentRow != null)
                {

                    string Sql = "Delete from LoginUser where UserID = @id and not UserName = '" + User + "'";
                    string prams = dgv.CurrentRow.Cells[0].Value.ToString();
                    this.Db.SetParameter("id", prams);
                    int result = this.Db.ExecuteNonQuery(Sql);
                    if (result == 1)
                    {
                        dgv.Rows.RemoveAt(dgv.CurrentRow.Index);
                    }
                }
            }
            this.LoadData();
        }

        public void Save()
        {
            string Sql = "select UserID, UserName, Pwd from LoginUser";
            if (CheckData())
            {
                this.Db.Update(Sql, DS);
                Index = 0;
                this.LoadData();
            }
        }

        public void Alter()
        {
            Save();
        }

        #endregion

        public void SetDb(IDBInterface db)
        {
            this.Db = db;
        }
    }
}
