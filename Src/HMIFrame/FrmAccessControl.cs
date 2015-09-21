using System;
using GLEO.DBUtility;
using GLEO.MES.Sys;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;

namespace PictureLib
{
    public partial class FrmAccessControl : BaseControl, IEdit
    {
        private string pramaryPerfix;
        private DataSet DataSet;
        private DataTable RoleTable;

        public FrmAccessControl()
        {
            InitializeComponent();

            this.dataGridViewFx1.AutoGenerateColumns = false;
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

        private void FrmAccessControl_Load(object sender, EventArgs e)
        {
            this.LoadRole();
            this.LoadData();
        }

        public void LoadRole()
        {
            List<int> roilid = OptionControl.Instance.LoadRoles();

            int id = Global.LoginUser.Role;
            foreach (int role in roilid)
            {
                if (role > id)
                {
                    string sql = "select role,id from role where id >= " + this.pramaryPerfix + "id";

                    Db.SetParameter("id", role);
                    DataTable table = Db.RetrieveDataTable(sql);
                    this.comboBoxFx1.DataSource = table;
                    this.comboBoxFx1.DisplayMember = "role";
                    this.comboBoxFx1.ValueMember = "id";
                    if (table.Rows.Count > 0)
                    {
                        this.comboBoxFx1.SelectedIndex = 0;
                    }
                    break;
                }
            }
        }
        public void LoadData()
        {
            //string sqlss = "select * from permission";
            //RoleTable = Db.RetrieveDataTable(sqlss);

            string sql = "select p.permissions, o.optioninterface, r.Role, o.roleid, p.rwableid from options o, role r, permission p where o.roleid = r.id and p.Rwableid = o.Rwable and o.roleid = " + this.pramaryPerfix + "id";
            Db.SetParameter("id", this.comboBoxFx1.SelectedValue);
            DataSet = Db.RetrieveDataSet(sql);
            DataTable dt = DataSet.Tables[0];

            string sqls = "select Rwableid, permissions from permission";
            DataSet = Db.RetrieveDataSet(sqls);
            //DataTable dt = DataSet.Tables[0];
            DataGridViewComboBoxColumn colRole = new DataGridViewComboBoxColumn();
            colRole.DataSource = DataSet.Tables[0].DefaultView;
            colRole.Name = "permissions";
            colRole.DataPropertyName = "Rwableid";
            colRole.HeaderText = "权限";
            colRole.DisplayMember = "permissions";
            colRole.ValueMember = "Rwableid";
            colRole.DisplayStyle = DataGridViewComboBoxDisplayStyle.ComboBox;
            dataGridViewFx1.Columns.Add(colRole);
            this.dataGridViewFx1.DataSource = dt;
        }


        private void dataGridViewFx1_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            EditCtrl.EditEnd();
        }

        #region Interface IEdit

        public void Add()
        {
            throw new NotImplementedException();
        }

        public void Delete()
        {
            throw new NotImplementedException();
        }

        public void Save()
        {
            DataTable dt = dataGridViewFx1.DataSource as DataTable;
            for(int i = 0; i < dt.Rows.Count; i++)
            {
                string str = dt.Rows[i]["optioninterface"].ToString();
                int rw = int.Parse(dt.Rows[i]["rwableid"].ToString());
                int roleid = int.Parse(dt.Rows[i]["roleid"].ToString());
                //DataRow[] drs = RoleTable.Select("permissions = '" + rw +"'");
                //int pmid = 0;
                //if (drs.Length == 1)
                //{
                //    pmid = int.Parse(drs[0]["Rwableid"].ToString());
                //}
                string sql = "Update options set Rwable = " + this.pramaryPerfix + "Rwable where roleid = " + this.pramaryPerfix + "roleid and optioninterface = " + this.pramaryPerfix + "optioninterface";
                Db.SetParameter("Rwable", rw);
                Db.SetParameter("roleid", roleid);
                Db.SetParameter("optioninterface", str);
                Db.ExecuteNonQuery(sql);
            }
        }

        public void Alter()
        {
        }

        #endregion
    }
}
