namespace PictureLib
{
    partial class FrmAccessControl
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.dataGridViewFx1 = new GLEO.MES.UI.DataGridViewFx();
            this.comboBoxFx1 = new GLEO.MES.UI.ComboBoxFx();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewFx1
            // 
            this.dataGridViewFx1.AllowUserToAddRows = false;
            this.dataGridViewFx1.AllowUserToResizeRows = false;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("SimSun", 11F);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewFx1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewFx1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFx1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column4,
            this.Column1,
            this.Column3,
            this.Column2});
            this.dataGridViewFx1.Location = new System.Drawing.Point(0, 50);
            this.dataGridViewFx1.Name = "dataGridViewFx1";
            this.dataGridViewFx1.RowHeadersVisible = false;
            this.dataGridViewFx1.RowTemplate.Height = 23;
            this.dataGridViewFx1.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx1.Size = new System.Drawing.Size(1777, 730);
            this.dataGridViewFx1.TabIndex = 0;
            this.dataGridViewFx1.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewFx1_CellEndEdit);
            // 
            // comboBoxFx1
            // 
            this.comboBoxFx1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxFx1.FormattingEnabled = true;
            this.comboBoxFx1.Location = new System.Drawing.Point(61, 14);
            this.comboBoxFx1.Name = "comboBoxFx1";
            this.comboBoxFx1.Size = new System.Drawing.Size(121, 20);
            this.comboBoxFx1.TabIndex = 1;
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Font = new System.Drawing.Font("SimSun", 11F);
            this.labelFx1.Location = new System.Drawing.Point(3, 17);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(52, 15);
            this.labelFx1.TabIndex = 2;
            this.labelFx1.Text = "角色：";
            // 
            // Column4
            // 
            this.Column4.HeaderText = "id";
            this.Column4.Name = "Column4";
            this.Column4.Visible = false;
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "optioninterface";
            this.Column1.HeaderText = "功能界面";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            this.Column1.Width = 150;
            // 
            // Column3
            // 
            this.Column3.DataPropertyName = "Role";
            this.Column3.HeaderText = "角色";
            this.Column3.Name = "Column3";
            this.Column3.ReadOnly = true;
            this.Column3.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            // 
            // Column2
            // 
            this.Column2.DataPropertyName = "roleid";
            this.Column2.HeaderText = "roleid";
            this.Column2.Name = "Column2";
            this.Column2.Visible = false;
            // 
            // FrmAccessControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.labelFx1);
            this.Controls.Add(this.comboBoxFx1);
            this.Controls.Add(this.dataGridViewFx1);
            this.Name = "FrmAccessControl";
            this.Size = new System.Drawing.Size(1780, 780);
            this.Load += new System.EventHandler(this.FrmAccessControl_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private GLEO.MES.UI.DataGridViewFx dataGridViewFx1;
        private GLEO.MES.UI.ComboBoxFx comboBoxFx1;
        private GLEO.MES.UI.LabelFx labelFx1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
    }
}
