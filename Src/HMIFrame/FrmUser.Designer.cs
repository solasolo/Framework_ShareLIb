using GLEO.MES.UI;
using GLEO.UI;
namespace PictureLib
{
    partial class FrmUser
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
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.code = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.角色 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.crew = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.comboBoxFx1 = new GLEO.MES.UI.ComboBoxFx();
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.panelFx1 = new GLEO.MES.UI.PanelFx();
            this.txtCode = new GLEO.MES.UI.TextBoxFx();
            this.cbCrew = new IntMapComboBox();
            this.cbRole = new IntMapComboBox();
            this.txtName = new GLEO.MES.UI.TextBoxFx();
            this.lbCrew = new GLEO.MES.UI.LabelFx();
            this.lbRole = new GLEO.MES.UI.LabelFx();
            this.lbNo = new GLEO.MES.UI.LabelFx();
            this.lbName = new GLEO.MES.UI.LabelFx();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).BeginInit();
            this.panelFx1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewFx1
            // 
            this.dataGridViewFx1.AllowUserToAddRows = false;
            this.dataGridViewFx1.AllowUserToResizeRows = false;
            this.dataGridViewFx1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("SimSun", 11F);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewFx1.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewFx1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.DisableResizing;
            this.dataGridViewFx1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column3,
            this.Column1,
            this.code,
            this.角色,
            this.crew});
            this.dataGridViewFx1.Location = new System.Drawing.Point(6, 37);
            this.dataGridViewFx1.MultiSelect = false;
            this.dataGridViewFx1.Name = "dataGridViewFx1";
            this.dataGridViewFx1.RowHeadersVisible = false;
            this.dataGridViewFx1.RowTemplate.Height = 23;
            this.dataGridViewFx1.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewFx1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewFx1.Size = new System.Drawing.Size(1431, 730);
            this.dataGridViewFx1.TabIndex = 0;
            this.dataGridViewFx1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewFx1_CellClick);
            // 
            // Column3
            // 
            this.Column3.DataPropertyName = "ID";
            this.Column3.HeaderText = "userid";
            this.Column3.Name = "Column3";
            this.Column3.Visible = false;
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "name";
            this.Column1.HeaderText = "用户名";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            // 
            // code
            // 
            this.code.DataPropertyName = "code";
            this.code.HeaderText = "工号";
            this.code.Name = "code";
            this.code.ReadOnly = true;
            // 
            // 角色
            // 
            this.角色.DataPropertyName = "role";
            this.角色.HeaderText = "角色";
            this.角色.Name = "角色";
            this.角色.ReadOnly = true;
            this.角色.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.角色.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            // 
            // crew
            // 
            this.crew.DataPropertyName = "crew";
            this.crew.HeaderText = "班组";
            this.crew.Name = "crew";
            this.crew.ReadOnly = true;
            this.crew.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.crew.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            // 
            // comboBoxFx1
            // 
            this.comboBoxFx1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxFx1.FormattingEnabled = true;
            this.comboBoxFx1.Location = new System.Drawing.Point(56, 0);
            this.comboBoxFx1.Name = "comboBoxFx1";
            this.comboBoxFx1.Size = new System.Drawing.Size(202, 20);
            this.comboBoxFx1.TabIndex = 2;
            this.comboBoxFx1.SelectedIndexChanged += new System.EventHandler(this.comboBoxFx1_SelectedIndexChanged);
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Font = new System.Drawing.Font("SimSun", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelFx1.Location = new System.Drawing.Point(0, 0);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(49, 14);
            this.labelFx1.TabIndex = 3;
            this.labelFx1.Text = "班组：";
            // 
            // panelFx1
            // 
            this.panelFx1.Controls.Add(this.txtCode);
            this.panelFx1.Controls.Add(this.cbCrew);
            this.panelFx1.Controls.Add(this.cbRole);
            this.panelFx1.Controls.Add(this.txtName);
            this.panelFx1.Controls.Add(this.lbCrew);
            this.panelFx1.Controls.Add(this.lbRole);
            this.panelFx1.Controls.Add(this.lbNo);
            this.panelFx1.Controls.Add(this.lbName);
            this.panelFx1.Location = new System.Drawing.Point(1461, 37);
            this.panelFx1.Name = "panelFx1";
            this.panelFx1.Size = new System.Drawing.Size(316, 586);
            this.panelFx1.TabIndex = 12;
            // 
            // txtCode
            // 
            this.txtCode.BackColor = System.Drawing.Color.DarkGreen;
            this.txtCode.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtCode.DataFiled = null;
            this.txtCode.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold);
            this.txtCode.ForeColor = System.Drawing.Color.White;
            this.txtCode.Location = new System.Drawing.Point(137, 146);
            this.txtCode.Name = "txtCode";
            this.txtCode.Size = new System.Drawing.Size(100, 21);
            this.txtCode.TabIndex = 22;
            this.txtCode.WriteLock = false;
            // 
            // cbCrew
            // 
            this.cbCrew.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbCrew.FormattingEnabled = true;
            this.cbCrew.Location = new System.Drawing.Point(137, 258);
            this.cbCrew.Name = "cbCrew";
            this.cbCrew.Size = new System.Drawing.Size(100, 20);
            this.cbCrew.TabIndex = 21;
            // 
            // cbRole
            // 
            this.cbRole.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbRole.FormattingEnabled = true;
            this.cbRole.Location = new System.Drawing.Point(137, 203);
            this.cbRole.Name = "cbRole";
            this.cbRole.Size = new System.Drawing.Size(100, 20);
            this.cbRole.TabIndex = 20;
            // 
            // txtName
            // 
            this.txtName.BackColor = System.Drawing.Color.DarkGreen;
            this.txtName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtName.DataFiled = null;
            this.txtName.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Bold);
            this.txtName.ForeColor = System.Drawing.Color.White;
            this.txtName.Location = new System.Drawing.Point(137, 89);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(100, 21);
            this.txtName.TabIndex = 16;
            this.txtName.WriteLock = false;
            // 
            // lbCrew
            // 
            this.lbCrew.AutoSize = true;
            this.lbCrew.DefaultText = null;
            this.lbCrew.Location = new System.Drawing.Point(67, 258);
            this.lbCrew.Name = "lbCrew";
            this.lbCrew.Size = new System.Drawing.Size(41, 12);
            this.lbCrew.TabIndex = 15;
            this.lbCrew.Text = "班组：";
            // 
            // lbRole
            // 
            this.lbRole.AutoSize = true;
            this.lbRole.DefaultText = null;
            this.lbRole.Location = new System.Drawing.Point(67, 203);
            this.lbRole.Name = "lbRole";
            this.lbRole.Size = new System.Drawing.Size(41, 12);
            this.lbRole.TabIndex = 14;
            this.lbRole.Text = "角色：";
            // 
            // lbNo
            // 
            this.lbNo.AutoSize = true;
            this.lbNo.DefaultText = null;
            this.lbNo.Location = new System.Drawing.Point(67, 146);
            this.lbNo.Name = "lbNo";
            this.lbNo.Size = new System.Drawing.Size(41, 12);
            this.lbNo.TabIndex = 13;
            this.lbNo.Text = "工号：";
            // 
            // lbName
            // 
            this.lbName.AutoSize = true;
            this.lbName.DefaultText = null;
            this.lbName.Location = new System.Drawing.Point(67, 92);
            this.lbName.Name = "lbName";
            this.lbName.Size = new System.Drawing.Size(53, 12);
            this.lbName.TabIndex = 12;
            this.lbName.Text = "用户名：";
            // 
            // FrmUser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panelFx1);
            this.Controls.Add(this.labelFx1);
            this.Controls.Add(this.comboBoxFx1);
            this.Controls.Add(this.dataGridViewFx1);
            this.Name = "FrmUser";
            this.Size = new System.Drawing.Size(1780, 780);
            this.Load += new System.EventHandler(this.FrmUser_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFx1)).EndInit();
            this.panelFx1.ResumeLayout(false);
            this.panelFx1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private DataGridViewFx dataGridViewFx1;
        private ComboBoxFx comboBoxFx1;
        private LabelFx labelFx1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn code;
        private System.Windows.Forms.DataGridViewTextBoxColumn 角色;
        private System.Windows.Forms.DataGridViewTextBoxColumn crew;
        private PanelFx panelFx1;
        private GLEO.MES.UI.TextBoxFx txtName;
        private GLEO.MES.UI.LabelFx lbCrew;
        private GLEO.MES.UI.LabelFx lbRole;
        private GLEO.MES.UI.LabelFx lbNo;
        private GLEO.MES.UI.LabelFx lbName;
        private IntMapComboBox cbCrew;
        private IntMapComboBox cbRole;
        private TextBoxFx txtCode;
    }
}
