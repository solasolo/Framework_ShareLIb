namespace TestMutiLang
{
    partial class Form1
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
            this.dataGridViewFx2 = new GLEO.MES.UI.DataGridViewFx();
            this.Language = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewFx1 = new GLEO.MES.UI.DataGridViewFx();
            this.User = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Pwd = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Login = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Exit = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.textBoxFx1 = new GLEO.MES.UI.TextBoxFx();
            this.buttonFx2 = new GLEO.MES.UI.ButtonFx();
            this.buttonFx1 = new GLEO.MES.UI.ButtonFx();
            this.panelFx1 = new GLEO.MES.UI.PanelFx();
            this.button1 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).BeginInit();
            this.panelFx1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewFx2
            // 
            this.dataGridViewFx2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFx2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Language});
            this.dataGridViewFx2.Location = new System.Drawing.Point(426, 91);
            this.dataGridViewFx2.Name = "dataGridViewFx2";
            this.dataGridViewFx2.RowTemplate.Height = 23;
            this.dataGridViewFx2.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx2.Size = new System.Drawing.Size(448, 419);
            this.dataGridViewFx2.TabIndex = 13;
            // 
            // Language
            // 
            this.Language.HeaderText = "Column1";
            this.Language.Name = "Language";
            // 
            // dataGridViewFx1
            // 
            this.dataGridViewFx1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFx1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.User,
            this.Pwd,
            this.Login,
            this.Exit});
            this.dataGridViewFx1.Location = new System.Drawing.Point(3, 91);
            this.dataGridViewFx1.Name = "dataGridViewFx1";
            this.dataGridViewFx1.RowTemplate.Height = 23;
            this.dataGridViewFx1.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx1.Size = new System.Drawing.Size(417, 419);
            this.dataGridViewFx1.TabIndex = 12;
            // 
            // User
            // 
            this.User.HeaderText = "Column1";
            this.User.Name = "User";
            // 
            // Pwd
            // 
            this.Pwd.HeaderText = "Column1";
            this.Pwd.Name = "Pwd";
            // 
            // Login
            // 
            this.Login.HeaderText = "Column1";
            this.Login.Name = "Login";
            // 
            // Exit
            // 
            this.Exit.HeaderText = "Column1";
            this.Exit.Name = "Exit";
            // 
            // textBoxFx1
            // 
            this.textBoxFx1.DataFiled = null;
            this.textBoxFx1.ForeColor = System.Drawing.Color.LightGray;
            this.textBoxFx1.Location = new System.Drawing.Point(200, 46);
            this.textBoxFx1.Name = "textBoxFx1";
            this.textBoxFx1.Size = new System.Drawing.Size(141, 21);
            this.textBoxFx1.TabIndex = 11;
            this.textBoxFx1.Text = "日期时间";
            this.textBoxFx1.Verifytype = GLEO.MES.UI.VerifyType.DateTime;
            this.textBoxFx1.TextChanged += new System.EventHandler(this.textBoxFx1_TextChanged_1);
            // 
            // buttonFx2
            // 
            this.buttonFx2.DefaultText = "Pwd";
            this.buttonFx2.Location = new System.Drawing.Point(104, 46);
            this.buttonFx2.Name = "buttonFx2";
            this.buttonFx2.Size = new System.Drawing.Size(75, 23);
            this.buttonFx2.TabIndex = 10;
            this.buttonFx2.Text = "密码";
            this.buttonFx2.UseVisualStyleBackColor = true;
            // 
            // buttonFx1
            // 
            this.buttonFx1.DefaultText = "Exit";
            this.buttonFx1.Location = new System.Drawing.Point(3, 46);
            this.buttonFx1.Name = "buttonFx1";
            this.buttonFx1.Size = new System.Drawing.Size(75, 23);
            this.buttonFx1.TabIndex = 9;
            this.buttonFx1.Text = "退出";
            this.buttonFx1.UseVisualStyleBackColor = true;
            this.buttonFx1.Click += new System.EventHandler(this.buttonFx1_Click);
            // 
            // panelFx1
            // 
            this.panelFx1.Controls.Add(this.button1);
            this.panelFx1.Controls.Add(this.button4);
            this.panelFx1.Controls.Add(this.button3);
            this.panelFx1.Controls.Add(this.button2);
            this.panelFx1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelFx1.Location = new System.Drawing.Point(0, 0);
            this.panelFx1.Name = "panelFx1";
            this.panelFx1.Size = new System.Drawing.Size(921, 29);
            this.panelFx1.TabIndex = 6;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(3, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "中文";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(84, 3);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 23);
            this.button4.TabIndex = 4;
            this.button4.Text = "日语";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(248, 3);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 3;
            this.button3.Text = "德语";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(165, 3);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 2;
            this.button2.Text = "英文";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // labelFx1
            // 
            this.labelFx1.DefaultText = "Login";
            this.labelFx1.Location = new System.Drawing.Point(374, 46);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(77, 18);
            this.labelFx1.TabIndex = 0;
            this.labelFx1.Text = "确定";
            this.labelFx1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(921, 557);
            this.Controls.Add(this.dataGridViewFx2);
            this.Controls.Add(this.dataGridViewFx1);
            this.Controls.Add(this.textBoxFx1);
            this.Controls.Add(this.buttonFx2);
            this.Controls.Add(this.buttonFx1);
            this.Controls.Add(this.panelFx1);
            this.Controls.Add(this.labelFx1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).EndInit();
            this.panelFx1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private GLEO.MES.UI.LabelFx labelFx1;
        private GLEO.MES.UI.ButtonFx buttonFx1;
        private GLEO.MES.UI.PanelFx panelFx1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private GLEO.MES.UI.ButtonFx buttonFx2;
        private GLEO.MES.UI.TextBoxFx textBoxFx1;
        private GLEO.MES.UI.DataGridViewFx dataGridViewFx1;
        private System.Windows.Forms.DataGridViewTextBoxColumn User;
        private System.Windows.Forms.DataGridViewTextBoxColumn Pwd;
        private System.Windows.Forms.DataGridViewTextBoxColumn Login;
        private System.Windows.Forms.DataGridViewTextBoxColumn Exit;
        private GLEO.MES.UI.DataGridViewFx dataGridViewFx2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Language;
    }
}

