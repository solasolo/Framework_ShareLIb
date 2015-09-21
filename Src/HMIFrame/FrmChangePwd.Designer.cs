namespace PictureLib
{
    partial class FrmChangePwd
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
            this.buttonFx1 = new GLEO.MES.UI.ButtonFx();
            this.buttonFx2 = new GLEO.MES.UI.ButtonFx();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.labelFx2 = new GLEO.MES.UI.LabelFx();
            this.labelFx3 = new GLEO.MES.UI.LabelFx();
            this.textName = new GLEO.MES.UI.TextBoxFx();
            this.textPwd = new GLEO.MES.UI.TextBoxFx();
            this.comboRol = new GLEO.MES.UI.ComboBoxFx();
            this.labelFx4 = new GLEO.MES.UI.LabelFx();
            this.textOld = new GLEO.MES.UI.TextBoxFx();
            this.SuspendLayout();
            // 
            // buttonFx1
            // 
            this.buttonFx1.DefaultText = null;
            this.buttonFx1.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonFx1.Location = new System.Drawing.Point(83, 231);
            this.buttonFx1.Name = "buttonFx1";
            this.buttonFx1.Size = new System.Drawing.Size(74, 23);
            this.buttonFx1.TabIndex = 0;
            this.buttonFx1.Text = "确定";
            this.buttonFx1.UseVisualStyleBackColor = true;
            this.buttonFx1.Click += new System.EventHandler(this.buttonFx1_Click);
            // 
            // buttonFx2
            // 
            this.buttonFx2.DefaultText = null;
            this.buttonFx2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonFx2.Location = new System.Drawing.Point(215, 231);
            this.buttonFx2.Name = "buttonFx2";
            this.buttonFx2.Size = new System.Drawing.Size(75, 23);
            this.buttonFx2.TabIndex = 1;
            this.buttonFx2.Text = "取消";
            this.buttonFx2.UseVisualStyleBackColor = true;
            this.buttonFx2.Click += new System.EventHandler(this.buttonFx2_Click);
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Location = new System.Drawing.Point(81, 34);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(53, 12);
            this.labelFx1.TabIndex = 2;
            this.labelFx1.Text = "用户名：";
            // 
            // labelFx2
            // 
            this.labelFx2.AutoSize = true;
            this.labelFx2.DefaultText = null;
            this.labelFx2.Location = new System.Drawing.Point(81, 132);
            this.labelFx2.Name = "labelFx2";
            this.labelFx2.Size = new System.Drawing.Size(53, 12);
            this.labelFx2.TabIndex = 3;
            this.labelFx2.Text = "新密码：";
            // 
            // labelFx3
            // 
            this.labelFx3.AutoSize = true;
            this.labelFx3.DefaultText = null;
            this.labelFx3.Location = new System.Drawing.Point(81, 187);
            this.labelFx3.Name = "labelFx3";
            this.labelFx3.Size = new System.Drawing.Size(41, 12);
            this.labelFx3.TabIndex = 4;
            this.labelFx3.Text = "角色：";
            // 
            // textName
            // 
            this.textName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textName.DataFiled = null;
            this.textName.Enabled = false;
            this.textName.ForeColor = System.Drawing.SystemColors.WindowText;
            this.textName.Location = new System.Drawing.Point(169, 32);
            this.textName.Name = "textName";
            this.textName.Size = new System.Drawing.Size(121, 21);
            this.textName.TabIndex = 5;
            // 
            // textPwd
            // 
            this.textPwd.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textPwd.DataFiled = null;
            this.textPwd.ForeColor = System.Drawing.SystemColors.WindowText;
            this.textPwd.Location = new System.Drawing.Point(169, 130);
            this.textPwd.Name = "textPwd";
            this.textPwd.Size = new System.Drawing.Size(121, 21);
            this.textPwd.TabIndex = 6;
            // 
            // comboRol
            // 
            this.comboRol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboRol.FormattingEnabled = true;
            this.comboRol.Location = new System.Drawing.Point(169, 184);
            this.comboRol.Name = "comboRol";
            this.comboRol.Size = new System.Drawing.Size(121, 20);
            this.comboRol.TabIndex = 7;
            // 
            // labelFx4
            // 
            this.labelFx4.AutoSize = true;
            this.labelFx4.DefaultText = null;
            this.labelFx4.Location = new System.Drawing.Point(81, 81);
            this.labelFx4.Name = "labelFx4";
            this.labelFx4.Size = new System.Drawing.Size(53, 12);
            this.labelFx4.TabIndex = 8;
            this.labelFx4.Text = "原密码：";
            // 
            // textOld
            // 
            this.textOld.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.textOld.DataFiled = null;
            this.textOld.ForeColor = System.Drawing.SystemColors.WindowText;
            this.textOld.Location = new System.Drawing.Point(169, 79);
            this.textOld.Name = "textOld";
            this.textOld.Size = new System.Drawing.Size(121, 21);
            this.textOld.TabIndex = 9;
            // 
            // FrmChangePwd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(400, 294);
            this.Controls.Add(this.textOld);
            this.Controls.Add(this.labelFx4);
            this.Controls.Add(this.comboRol);
            this.Controls.Add(this.textPwd);
            this.Controls.Add(this.textName);
            this.Controls.Add(this.labelFx3);
            this.Controls.Add(this.labelFx2);
            this.Controls.Add(this.labelFx1);
            this.Controls.Add(this.buttonFx2);
            this.Controls.Add(this.buttonFx1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FrmChangePwd";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "密码修改";
            this.Load += new System.EventHandler(this.FrmChangePwd_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private GLEO.MES.UI.ButtonFx buttonFx1;
        private GLEO.MES.UI.ButtonFx buttonFx2;
        private GLEO.MES.UI.LabelFx labelFx1;
        private GLEO.MES.UI.LabelFx labelFx2;
        private GLEO.MES.UI.LabelFx labelFx3;
        private GLEO.MES.UI.TextBoxFx textName;
        private GLEO.MES.UI.TextBoxFx textPwd;
        private GLEO.MES.UI.ComboBoxFx comboRol;
        private GLEO.MES.UI.LabelFx labelFx4;
        private GLEO.MES.UI.TextBoxFx textOld;
    }
}