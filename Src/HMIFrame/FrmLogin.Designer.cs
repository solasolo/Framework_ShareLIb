namespace PictureLib
{
    partial class FrmLogin
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panelFx1 = new GLEO.MES.UI.PanelFx();
            this.label1 = new System.Windows.Forms.Label();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.panelFx2 = new GLEO.MES.UI.PanelFx();
            this.lbLanguage = new GLEO.MES.UI.LabelFx();
            this.cbLanguage = new GLEO.MES.UI.ComboBoxFx();
            this.btnQuit = new GLEO.MES.UI.ButtonFx();
            this.btnLogin = new GLEO.MES.UI.ButtonFx();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.txtUser = new System.Windows.Forms.TextBox();
            this.labelFx3 = new GLEO.MES.UI.LabelFx();
            this.labelFx2 = new GLEO.MES.UI.LabelFx();
            this.panelFx1.SuspendLayout();
            this.panelFx2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelFx1
            // 
            this.panelFx1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(92)))), ((int)(((byte)(130)))), ((int)(((byte)(193)))));
            this.panelFx1.Controls.Add(this.label1);
            this.panelFx1.Controls.Add(this.labelFx1);
            this.panelFx1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelFx1.Location = new System.Drawing.Point(0, 0);
            this.panelFx1.Name = "panelFx1";
            this.panelFx1.Size = new System.Drawing.Size(457, 76);
            this.panelFx1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 9F);
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.label1.Location = new System.Drawing.Point(412, 59);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(33, 14);
            this.label1.TabIndex = 3;
            this.label1.Text = "V1.0";
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Font = new System.Drawing.Font("SimHei", 18F);
            this.labelFx1.ForeColor = System.Drawing.Color.White;
            this.labelFx1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelFx1.Location = new System.Drawing.Point(23, 23);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(58, 24);
            this.labelFx1.TabIndex = 2;
            this.labelFx1.Text = "Name";
            // 
            // panelFx2
            // 
            this.panelFx2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelFx2.Controls.Add(this.lbLanguage);
            this.panelFx2.Controls.Add(this.cbLanguage);
            this.panelFx2.Controls.Add(this.btnQuit);
            this.panelFx2.Controls.Add(this.btnLogin);
            this.panelFx2.Controls.Add(this.txtPassword);
            this.panelFx2.Controls.Add(this.txtUser);
            this.panelFx2.Controls.Add(this.labelFx3);
            this.panelFx2.Controls.Add(this.labelFx2);
            this.panelFx2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelFx2.Location = new System.Drawing.Point(0, 76);
            this.panelFx2.Name = "panelFx2";
            this.panelFx2.Size = new System.Drawing.Size(457, 222);
            this.panelFx2.TabIndex = 1;
            // 
            // lbLanguage
            // 
            this.lbLanguage.AutoSize = true;
            this.lbLanguage.DefaultText = "Language";
            this.lbLanguage.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lbLanguage.Location = new System.Drawing.Point(108, 115);
            this.lbLanguage.Name = "lbLanguage";
            this.lbLanguage.Size = new System.Drawing.Size(43, 13);
            this.lbLanguage.TabIndex = 16;
            this.lbLanguage.Text = "语言：";
            // 
            // cbLanguage
            // 
            this.cbLanguage.FormattingEnabled = true;
            this.cbLanguage.Location = new System.Drawing.Point(179, 112);
            this.cbLanguage.Name = "cbLanguage";
            this.cbLanguage.Size = new System.Drawing.Size(157, 21);
            this.cbLanguage.TabIndex = 15;
            this.cbLanguage.SelectedIndexChanged += new System.EventHandler(this.cbLanguage_SelectedIndexChanged);
            // 
            // btnQuit
            // 
            this.btnQuit.DefaultText = "Exit";
            this.btnQuit.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnQuit.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btnQuit.Location = new System.Drawing.Point(261, 163);
            this.btnQuit.Name = "btnQuit";
            this.btnQuit.PromissionId = 0;
            this.btnQuit.Size = new System.Drawing.Size(75, 25);
            this.btnQuit.TabIndex = 14;
            this.btnQuit.Text = "退出";
            this.btnQuit.UseVisualStyleBackColor = true;
            this.btnQuit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // btnLogin
            // 
            this.btnLogin.DefaultText = "Login";
            this.btnLogin.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnLogin.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btnLogin.Location = new System.Drawing.Point(179, 163);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.PromissionId = 0;
            this.btnLogin.Size = new System.Drawing.Size(75, 25);
            this.btnLogin.TabIndex = 13;
            this.btnLogin.Text = "登录";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.Login_Click);
            // 
            // txtPassword
            // 
            this.txtPassword.BackColor = System.Drawing.SystemColors.Window;
            this.txtPassword.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtPassword.ForeColor = System.Drawing.SystemColors.WindowText;
            this.txtPassword.Location = new System.Drawing.Point(179, 70);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.Size = new System.Drawing.Size(157, 20);
            this.txtPassword.TabIndex = 12;
            this.txtPassword.Text = "admin";
            this.txtPassword.UseSystemPasswordChar = true;
            this.txtPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtPassword_KeyDown);
            // 
            // txtUser
            // 
            this.txtUser.BackColor = System.Drawing.SystemColors.Window;
            this.txtUser.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtUser.ForeColor = System.Drawing.SystemColors.WindowText;
            this.txtUser.Location = new System.Drawing.Point(179, 31);
            this.txtUser.Name = "txtUser";
            this.txtUser.Size = new System.Drawing.Size(157, 20);
            this.txtUser.TabIndex = 11;
            this.txtUser.Text = "admin";
            // 
            // labelFx3
            // 
            this.labelFx3.AutoSize = true;
            this.labelFx3.DefaultText = "Pwd";
            this.labelFx3.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelFx3.Location = new System.Drawing.Point(108, 74);
            this.labelFx3.Name = "labelFx3";
            this.labelFx3.Size = new System.Drawing.Size(43, 13);
            this.labelFx3.TabIndex = 10;
            this.labelFx3.Text = "密码：";
            // 
            // labelFx2
            // 
            this.labelFx2.AutoSize = true;
            this.labelFx2.DefaultText = "User";
            this.labelFx2.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelFx2.Location = new System.Drawing.Point(108, 35);
            this.labelFx2.Name = "labelFx2";
            this.labelFx2.Size = new System.Drawing.Size(55, 13);
            this.labelFx2.TabIndex = 9;
            this.labelFx2.Text = "用户名：";
            // 
            // FrmLogin
            // 
            this.AcceptButton = this.btnLogin;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnQuit;
            this.ClientSize = new System.Drawing.Size(457, 298);
            this.ControlBox = false;
            this.Controls.Add(this.panelFx2);
            this.Controls.Add(this.panelFx1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FrmLogin";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "WeiQiao";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FrmLogin_FormClosing);
            this.Load += new System.EventHandler(this.FrmLogin_Load);
            this.panelFx1.ResumeLayout(false);
            this.panelFx1.PerformLayout();
            this.panelFx2.ResumeLayout(false);
            this.panelFx2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private GLEO.MES.UI.LabelFx lbLanguage;
        private GLEO.MES.UI.ButtonFx btnQuit;
        private GLEO.MES.UI.ButtonFx btnLogin;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.TextBox txtUser;
        private GLEO.MES.UI.LabelFx labelFx3;
        private GLEO.MES.UI.LabelFx labelFx2;
        private System.Windows.Forms.Label label1;
        private GLEO.MES.UI.LabelFx labelFx1;
        private GLEO.MES.UI.PanelFx panelFx1;
        private GLEO.MES.UI.PanelFx panelFx2;
        private GLEO.MES.UI.ComboBoxFx cbLanguage;
    }
}