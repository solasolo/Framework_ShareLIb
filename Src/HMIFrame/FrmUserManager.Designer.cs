namespace PictureLib
{
    partial class FrmUserManager
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.bt_Search = new GLEO.MES.UI.ButtonFx();
            this.dgvUser = new GLEO.MES.UI.DataGridViewFx();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.SearchCondition = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dgvUser)).BeginInit();
            this.SuspendLayout();
            // 
            // bt_Search
            // 
            this.bt_Search.DefaultText = "Search";
            this.bt_Search.Location = new System.Drawing.Point(400, 3);
            this.bt_Search.Name = "bt_Search";
            this.bt_Search.Size = new System.Drawing.Size(79, 23);
            this.bt_Search.TabIndex = 1;
            this.bt_Search.Text = "查询";
            this.bt_Search.UseVisualStyleBackColor = true;
            this.bt_Search.Click += new System.EventHandler(this.bt_Search_Click);
            // 
            // dgvUser
            // 
            this.dgvUser.AllowUserToAddRows = false;
            this.dgvUser.AllowUserToDeleteRows = false;
            this.dgvUser.AllowUserToResizeRows = false;
            this.dgvUser.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.dgvUser.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.DisableResizing;
            this.dgvUser.Location = new System.Drawing.Point(20, 32);
            this.dgvUser.Name = "dgvUser";
            this.dgvUser.RowTemplate.Height = 23;
            this.dgvUser.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.dgvUser.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvUser.Size = new System.Drawing.Size(497, 748);
            this.dgvUser.TabIndex = 0;
            this.dgvUser.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvUser_CellEndEdit_1);
            this.dgvUser.CellFormatting += new System.Windows.Forms.DataGridViewCellFormattingEventHandler(this.dgvUser_CellFormatting);
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = "User";
            this.labelFx1.Location = new System.Drawing.Point(28, 8);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(41, 12);
            this.labelFx1.TabIndex = 3;
            this.labelFx1.Text = "用户名";
            // 
            // SearchCondition
            // 
            this.SearchCondition.Location = new System.Drawing.Point(75, 5);
            this.SearchCondition.Name = "SearchCondition";
            this.SearchCondition.Size = new System.Drawing.Size(319, 21);
            this.SearchCondition.TabIndex = 4;
            // 
            // FrmUserManager
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.SearchCondition);
            this.Controls.Add(this.labelFx1);
            this.Controls.Add(this.bt_Search);
            this.Controls.Add(this.dgvUser);
            this.Name = "FrmUserManager";
            this.Size = new System.Drawing.Size(1780, 780);
            this.Load += new System.EventHandler(this.FrmUserManager_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvUser)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private GLEO.MES.UI.DataGridViewFx dgvUser;
        private GLEO.MES.UI.ButtonFx bt_Search;
        private GLEO.MES.UI.LabelFx labelFx1;
        private System.Windows.Forms.TextBox SearchCondition;
    }
}
