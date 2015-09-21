namespace PictureLib
{
    partial class FrmMultilang
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
            this.OriginalName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Chinese = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.English = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Germany = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewFx1
            // 
            this.dataGridViewFx1.AllowUserToAddRows = false;
            this.dataGridViewFx1.AllowUserToResizeRows = false;
            this.dataGridViewFx1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("SimHei", 11F);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewFx1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewFx1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFx1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.OriginalName,
            this.Chinese,
            this.English,
            this.Germany});
            this.dataGridViewFx1.Dock = System.Windows.Forms.DockStyle.Left;
            this.dataGridViewFx1.Location = new System.Drawing.Point(0, 0);
            this.dataGridViewFx1.Name = "dataGridViewFx1";
            this.dataGridViewFx1.RowHeadersVisible = false;
            this.dataGridViewFx1.RowTemplate.Height = 23;
            this.dataGridViewFx1.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewFx1.Size = new System.Drawing.Size(824, 845);
            this.dataGridViewFx1.TabIndex = 0;
            this.dataGridViewFx1.CellEndEdit += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewFx1_CellEndEdit);
            // 
            // OriginalName
            // 
            this.OriginalName.DataPropertyName = "origenalName";
            this.OriginalName.HeaderText = "OriginalName";
            this.OriginalName.Name = "OriginalName";
            this.OriginalName.Width = 200;
            // 
            // Chinese
            // 
            this.Chinese.DataPropertyName = "chinese";
            this.Chinese.HeaderText = "Chinese";
            this.Chinese.Name = "Chinese";
            this.Chinese.Width = 200;
            // 
            // English
            // 
            this.English.DataPropertyName = "english";
            this.English.HeaderText = "English";
            this.English.Name = "English";
            this.English.Width = 200;
            // 
            // Germany
            // 
            this.Germany.DataPropertyName = "germany";
            this.Germany.HeaderText = "Germany";
            this.Germany.Name = "Germany";
            this.Germany.Width = 200;
            // 
            // FrmMultilang
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.dataGridViewFx1);
            this.Name = "FrmMultilang";
            this.Size = new System.Drawing.Size(1780, 845);
            this.Load += new System.EventHandler(this.FrmMultilang_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private GLEO.MES.UI.DataGridViewFx dataGridViewFx1;
        private System.Windows.Forms.DataGridViewTextBoxColumn OriginalName;
        private System.Windows.Forms.DataGridViewTextBoxColumn Chinese;
        private System.Windows.Forms.DataGridViewTextBoxColumn English;
        private System.Windows.Forms.DataGridViewTextBoxColumn Germany;



    }
}
