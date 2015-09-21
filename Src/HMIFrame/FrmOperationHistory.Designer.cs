using GLEO.MES.UI;
using GLEO.UI;
namespace PictureLib
{
    partial class FrmOperationHistory
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            this.dataGridViewFx1 = new GLEO.MES.UI.DataGridViewFx();
            this.labelFx3 = new GLEO.MES.UI.LabelFx();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.comboBoxFx2 = new GLEO.MES.UI.ComboBoxFx();
            this.labelFx2 = new GLEO.MES.UI.LabelFx();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.comboBoxFx1 = new GLEO.UI.IntMapComboBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.operation_time = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.user = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.action = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.data = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewFx1
            // 
            this.dataGridViewFx1.AllowUserToAddRows = false;
            this.dataGridViewFx1.AllowUserToResizeRows = false;
            this.dataGridViewFx1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("SimSun", 11F);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewFx1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewFx1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFx1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.operation_time,
            this.user,
            this.action,
            this.Column1,
            this.data});
            this.dataGridViewFx1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewFx1.Location = new System.Drawing.Point(0, 46);
            this.dataGridViewFx1.MultiSelect = false;
            this.dataGridViewFx1.Name = "dataGridViewFx1";
            this.dataGridViewFx1.ReadOnly = true;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("SimSun", 11F);
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewFx1.RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridViewFx1.RowHeadersVisible = false;
            this.dataGridViewFx1.RowTemplate.Height = 23;
            this.dataGridViewFx1.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewFx1.Size = new System.Drawing.Size(1780, 799);
            this.dataGridViewFx1.TabIndex = 7;
            // 
            // labelFx3
            // 
            this.labelFx3.AutoSize = true;
            this.labelFx3.DefaultText = null;
            this.labelFx3.Font = new System.Drawing.Font("SimSun", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelFx3.Location = new System.Drawing.Point(533, 16);
            this.labelFx3.Name = "labelFx3";
            this.labelFx3.Size = new System.Drawing.Size(77, 14);
            this.labelFx3.TabIndex = 6;
            this.labelFx3.Text = "操作日期：";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(616, 12);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(138, 20);
            this.dateTimePicker1.TabIndex = 5;
            this.dateTimePicker1.ValueChanged += new System.EventHandler(this.dateTimePicker1_ValueChanged);
            // 
            // comboBoxFx2
            // 
            this.comboBoxFx2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxFx2.FormattingEnabled = true;
            this.comboBoxFx2.Location = new System.Drawing.Point(349, 12);
            this.comboBoxFx2.Name = "comboBoxFx2";
            this.comboBoxFx2.Size = new System.Drawing.Size(138, 21);
            this.comboBoxFx2.TabIndex = 4;
            this.comboBoxFx2.SelectedIndexChanged += new System.EventHandler(this.comboBoxFx2_SelectedIndexChanged);
            // 
            // labelFx2
            // 
            this.labelFx2.AutoSize = true;
            this.labelFx2.DefaultText = null;
            this.labelFx2.Font = new System.Drawing.Font("SimSun", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelFx2.Location = new System.Drawing.Point(266, 16);
            this.labelFx2.Name = "labelFx2";
            this.labelFx2.Size = new System.Drawing.Size(77, 14);
            this.labelFx2.TabIndex = 3;
            this.labelFx2.Text = "操作类型：";
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Font = new System.Drawing.Font("SimSun", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelFx1.Location = new System.Drawing.Point(9, 16);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(63, 14);
            this.labelFx1.TabIndex = 2;
            this.labelFx1.Text = "操作员：";
            // 
            // comboBoxFx1
            // 
            this.comboBoxFx1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxFx1.FormattingEnabled = true;
            this.comboBoxFx1.Location = new System.Drawing.Point(75, 12);
            this.comboBoxFx1.Name = "comboBoxFx1";
            this.comboBoxFx1.Size = new System.Drawing.Size(138, 21);
            this.comboBoxFx1.TabIndex = 1;
            this.comboBoxFx1.Value = 0;
            this.comboBoxFx1.SelectedIndexChanged += new System.EventHandler(this.comboBoxFx1_SelectedIndexChanged);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.dateTimePicker1);
            this.panel1.Controls.Add(this.comboBoxFx1);
            this.panel1.Controls.Add(this.labelFx3);
            this.panel1.Controls.Add(this.labelFx1);
            this.panel1.Controls.Add(this.labelFx2);
            this.panel1.Controls.Add(this.comboBoxFx2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1780, 46);
            this.panel1.TabIndex = 8;
            // 
            // operation_time
            // 
            this.operation_time.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.operation_time.DataPropertyName = "Time";
            this.operation_time.HeaderText = "操作时间";
            this.operation_time.Name = "operation_time";
            this.operation_time.ReadOnly = true;
            this.operation_time.Width = 150;
            // 
            // user
            // 
            this.user.DataPropertyName = "UserName";
            this.user.HeaderText = "用户";
            this.user.Name = "user";
            this.user.ReadOnly = true;
            // 
            // action
            // 
            this.action.DataPropertyName = "ActionName";
            this.action.HeaderText = "操作";
            this.action.Name = "action";
            this.action.ReadOnly = true;
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "Key";
            this.Column1.HeaderText = "操作对象";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            // 
            // data
            // 
            this.data.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.data.DataPropertyName = "data";
            this.data.HeaderText = "操作记录";
            this.data.Name = "data";
            this.data.ReadOnly = true;
            // 
            // FrmOperationHistory
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.dataGridViewFx1);
            this.Controls.Add(this.panel1);
            this.Name = "FrmOperationHistory";
            this.Size = new System.Drawing.Size(1780, 845);
            this.Load += new System.EventHandler(this.FrmOperationHistory_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private IntMapComboBox comboBoxFx1;
        private LabelFx labelFx1;
        private LabelFx labelFx2;
        private ComboBoxFx comboBoxFx2;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private LabelFx labelFx3;
        private DataGridViewFx dataGridViewFx1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.DataGridViewTextBoxColumn operation_time;
        private System.Windows.Forms.DataGridViewTextBoxColumn user;
        private System.Windows.Forms.DataGridViewTextBoxColumn action;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn data;

    }
}
