using GLEO.DBUtility;
using GLEO.MES.Sys;
using PictureLib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PictureLib
{
    public partial class FrmLogin : Form
    {
        public bool LoginSuccess;
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

        public FrmLogin(BaseDbSupport db)
        {
            InitializeComponent();

            this._Db = db;

            this.Text = Global.AppTitle;
            this.labelFx1.Text = Global.AppName;

            Global.LoginUser = null;
        }

        private void Login_Click(object sender, EventArgs e)
        {
            string UName = this.txtUser.Text;
            string Pwd = this.txtPassword.Text;

            UserBean user = (this._Db as IDBUserManager).Login(UName, Pwd);

            Global.LoginUser = user;

            if (user != null)
            {
                this.DialogResult = DialogResult.OK;
            }
            else
            {
                MessageBox.Show("用户名密码错误！");
                this.txtPassword.Text = null;
            }

            // 登录判定
            //TODO 登录判定
            //UserManager Manager = new UserManager();
            //LoginSuccess = Manager.Login(UName, Pwd);
            //if (LoginSuccess == true)
            //{
            //    Global.LoginUser = UName;
            //    this.DialogResult = DialogResult.OK;
            //}
            //else 
            //{
            //    this.txtPassword.Text = null;
            //}
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            LoginSuccess = false;
        }

        private void FrmLogin_FormClosing(object sender, FormClosingEventArgs e)
        {
            //e.Cancel = (Global.LoginUser == null);
        }

        private void FrmLogin_Load(object sender, EventArgs e)
        {
            foreach (string Item in Enum.GetNames(typeof(LanguageType)))
            {

                switch (Item)
                {

                    case "Chinese":
                        cbLanguage.Items.Add("中文");
                        break;

                    case "English":
                        cbLanguage.Items.Add("English");
                        break;

                    case "Germany":
                        cbLanguage.Items.Add("Deutsch");
                        break;

                    case "Japanese":
                        cbLanguage.Items.Add("日本语");
                        break;
                }
            }
            cbLanguage.SelectedItem = cbLanguage.Items[0];
        }

        private void cbLanguage_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbLanguage.SelectedItem.ToString())
            {
                case "中文":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.Chinese;
                    break;
                case "English":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.English;
                    break;
                case "Deutsch":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.Germany;
                    break;
                case "日本语":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.Japanese;
                    break;
            }

            this.Refresh();
        }

        private void txtPassword_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            {
                Login_Click(null, null);
            }
        }
    }
}
