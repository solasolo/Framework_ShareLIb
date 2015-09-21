using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GLEO.DBUtility;
using GLEO.UI;
using GLEO.MES.Sys;

namespace PictureLib
{
    public partial class FrmChangePwd : Form
    {
        //const int WM_SELF_LOAD = WinAPIs.WM_USER + 100;
        private string pramaryPerfix;
        private BaseDbSupport _Db;

        private void setpramaryPerfix()
        {
            if (this._Db is MsSqlDbSupport)
                pramaryPerfix = "@";
            if (this._Db is OracleDbSupport)
                pramaryPerfix = ":";
            if (this._Db is OleDbSupport)
                pramaryPerfix = "?";
            if (this._Db is FirebirdDbSupport)
                pramaryPerfix = "@";
        }

        public FrmChangePwd(BaseDbSupport db)
        {
            InitializeComponent();
            this._Db = db;
            this.setpramaryPerfix();
        }

        private void buttonFx2_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
        }

        private void FrmChangePwd_Load(object sender, EventArgs e)
        {
            this.textName.Text = Global.LoginUser.Name;
            this.textName.Enabled = false;

            string sql = "select r.id, r.role from loginuser l, role r where l.role = r.id and id = " + this.pramaryPerfix + "id";
            _Db.SetParameter("id", Global.LoginUser.ID);
            DataTable dt = _Db.RetrieveDataSet(sql).Tables[0];
            this.comboRol.DataSource = dt;
            this.comboRol.DisplayMember = "role";
            this.comboRol.ValueMember = "id";
        }

        //确认按钮
        private void buttonFx1_Click(object sender, EventArgs e)
        {
            string sql = "select pwd from LoginUser where userid = " + this.pramaryPerfix + "id";
            _Db.SetParameter("id", Global.LoginUser.ID);
            ProxyDataReader reader = _Db.ExecuteReader(sql);

            using (reader)
            {
                if (reader.Read())
                {
                    string pwdDb = reader.GetString("pwd", "");
                    string pwdOld = GetMD5Hash(this.textOld.Text);
                    if (pwdDb != pwdOld)
                    {
                        MessageBox.Show("原密码错误!");
                        return;
                    }
                    else
                    {
                        string sqls = "update loginuser set pwd = " + this.pramaryPerfix + "pwd where username = " + this.pramaryPerfix + "username";
                        _Db.SetParameter("pwd", GetMD5Hash(this.textPwd.Text));
                        _Db.SetParameter("username", Global.LoginUser.Name);
                        _Db.ExecuteNonQuery(sqls);
                        this.Close();
                        //this.DialogResult = DialogResult.OK;
                        
                        WinAPIs.PostMessage(this.Handle, WinAPIs.WM_SELF_LOAD, new IntPtr(0), new IntPtr(0));
                    }
                }
            }
        }

        public static string GetMD5Hash(String input)
        {
            MD5 md5 = new MD5CryptoServiceProvider();
            byte[] res = md5.ComputeHash(Encoding.Default.GetBytes(input), 0, input.Length);

            string temp = Convert.ToBase64String(res);

            return temp;
        }
    }
}
