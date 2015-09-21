namespace TestMutiLang
{
    partial class Form2
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
            this.SuspendLayout();
            // 
            // buttonFx1
            // 
            this.buttonFx1.DefaultText = null;
            this.buttonFx1.Location = new System.Drawing.Point(101, 78);
            this.buttonFx1.Name = "buttonFx1";
            this.buttonFx1.Size = new System.Drawing.Size(75, 23);
            this.buttonFx1.TabIndex = 0;
            this.buttonFx1.Text = "buttonFx1";
            this.buttonFx1.UseVisualStyleBackColor = true;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonFx1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);

        }

        #endregion

        private GLEO.MES.UI.ButtonFx buttonFx1;
    }
}