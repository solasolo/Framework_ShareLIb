using GLEO.MES.UI;
namespace PictureLib
{
    partial class FrmChangeCrew
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
            this.labelFx1 = new GLEO.MES.UI.LabelFx();
            this.cmdOk = new GLEO.MES.UI.ButtonFx();
            this.cmdCancel = new GLEO.MES.UI.ButtonFx();
            this.SuspendLayout();
            // 
            // labelFx1
            // 
            this.labelFx1.AutoSize = true;
            this.labelFx1.DefaultText = null;
            this.labelFx1.Font = new System.Drawing.Font("SimSun", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelFx1.Location = new System.Drawing.Point(165, 39);
            this.labelFx1.Name = "labelFx1";
            this.labelFx1.Size = new System.Drawing.Size(144, 29);
            this.labelFx1.TabIndex = 0;
            this.labelFx1.Text = "确定换班?";
            // 
            // cmdOk
            // 
            this.cmdOk.AutoSize = true;
            this.cmdOk.DefaultText = null;
            this.cmdOk.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.cmdOk.Location = new System.Drawing.Point(253, 102);
            this.cmdOk.Name = "cmdOk";
            this.cmdOk.Size = new System.Drawing.Size(80, 33);
            this.cmdOk.TabIndex = 3;
            this.cmdOk.Text = "确定";
            this.cmdOk.UseVisualStyleBackColor = true;
            this.cmdOk.Click += new System.EventHandler(this.cmdOk_Click);
            // 
            // cmdCancel
            // 
            this.cmdCancel.AutoSize = true;
            this.cmdCancel.DefaultText = null;
            this.cmdCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cmdCancel.Location = new System.Drawing.Point(361, 102);
            this.cmdCancel.Name = "cmdCancel";
            this.cmdCancel.Size = new System.Drawing.Size(80, 33);
            this.cmdCancel.TabIndex = 4;
            this.cmdCancel.Text = "取消";
            this.cmdCancel.UseVisualStyleBackColor = true;
            this.cmdCancel.Click += new System.EventHandler(this.cmdCancel_Click);
            // 
            // FrmChangeCrew
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(484, 162);
            this.Controls.Add(this.cmdCancel);
            this.Controls.Add(this.cmdOk);
            this.Controls.Add(this.labelFx1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FrmChangeCrew";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "更换班组";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private LabelFx labelFx1;
        private ButtonFx cmdOk;
        private ButtonFx cmdCancel;
    }
}