using GLEO.MES.UI;
namespace PictureLib
{
    partial class MainFrame
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainFrame));
            this.ClockTimer = new System.Windows.Forms.Timer(this.components);
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.tslbConnectionState = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripDropDownButton1 = new System.Windows.Forms.ToolStripDropDownButton();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.tsbtnLanguage = new System.Windows.Forms.ToolStripDropDownButton();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.tslbMessage = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslbError = new System.Windows.Forms.ToolStripStatusLabel();
            this.Noticor = new System.Windows.Forms.NotifyIcon(this.components);
            this.NoticeMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmQuit = new System.Windows.Forms.ToolStripMenuItem();
            this.panel4 = new GLEO.MES.UI.PanelFx();
            this.panel_Main = new System.Windows.Forms.Panel();
            this.panel3 = new GLEO.MES.UI.PanelFx();
            this.pnlSystem = new System.Windows.Forms.Panel();
            this.btnExit = new GLEO.MES.UI.ButtonFx();
            this.btnLock = new GLEO.MES.UI.ButtonFx();
            this.pnlDocument = new System.Windows.Forms.Panel();
            this.buttonFx9 = new GLEO.MES.UI.ButtonFx();
            this.btnImport = new GLEO.MES.UI.ButtonFx();
            this.btnExport = new GLEO.MES.UI.ButtonFx();
            this.btnPrint = new GLEO.MES.UI.ButtonFx();
            this.pnlNavigator = new System.Windows.Forms.Panel();
            this.btnUp = new GLEO.MES.UI.ButtonFx();
            this.btnDown = new GLEO.MES.UI.ButtonFx();
            this.btnRight = new GLEO.MES.UI.ButtonFx();
            this.btnLeft = new GLEO.MES.UI.ButtonFx();
            this.pnlEdit = new System.Windows.Forms.Panel();
            this.btnNew = new GLEO.MES.UI.ButtonFx();
            this.btnSave = new GLEO.MES.UI.ButtonFx();
            this.btnAlter = new GLEO.MES.UI.ButtonFx();
            this.btnDelete = new GLEO.MES.UI.ButtonFx();
            this.panel5 = new GLEO.MES.UI.PanelFx();
            this.panel2 = new System.Windows.Forms.Panel();
            this.lbAlarm = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lbClock = new System.Windows.Forms.Label();
            this.lbOperator = new System.Windows.Forms.Label();
            this.picLogo = new System.Windows.Forms.PictureBox();
            this.lb_Crew = new GLEO.MES.UI.FlashLabel();
            this.statusStrip1.SuspendLayout();
            this.NoticeMenu.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel3.SuspendLayout();
            this.pnlSystem.SuspendLayout();
            this.pnlDocument.SuspendLayout();
            this.pnlNavigator.SuspendLayout();
            this.pnlEdit.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picLogo)).BeginInit();
            this.SuspendLayout();
            // 
            // ClockTimer
            // 
            this.ClockTimer.Interval = 1000;
            this.ClockTimer.Tick += new System.EventHandler(this.ClockTimer_Tick);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslbConnectionState,
            this.tslStatus,
            this.toolStripDropDownButton1,
            this.tsbtnLanguage,
            this.tslbMessage,
            this.tslbError});
            this.statusStrip1.Location = new System.Drawing.Point(0, 758);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1378, 22);
            this.statusStrip1.TabIndex = 0;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // tslbConnectionState
            // 
            this.tslbConnectionState.AutoSize = false;
            this.tslbConnectionState.BackColor = System.Drawing.Color.Green;
            this.tslbConnectionState.Name = "tslbConnectionState";
            this.tslbConnectionState.Size = new System.Drawing.Size(17, 17);
            // 
            // tslStatus
            // 
            this.tslStatus.Name = "tslStatus";
            this.tslStatus.Size = new System.Drawing.Size(0, 17);
            // 
            // toolStripDropDownButton1
            // 
            this.toolStripDropDownButton1.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.toolStripDropDownButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripDropDownButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolStripMenuItem2});
            this.toolStripDropDownButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton1.Image")));
            this.toolStripDropDownButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDropDownButton1.Name = "toolStripDropDownButton1";
            this.toolStripDropDownButton1.Size = new System.Drawing.Size(29, 20);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.toolStripMenuItem1.Text = "窗口";
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(152, 22);
            this.toolStripMenuItem2.Text = "通信";
            // 
            // tsbtnLanguage
            // 
            this.tsbtnLanguage.AutoSize = false;
            this.tsbtnLanguage.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.tsbtnLanguage.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbtnLanguage.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem3,
            this.toolStripMenuItem4,
            this.toolStripMenuItem5});
            this.tsbtnLanguage.Image = ((System.Drawing.Image)(resources.GetObject("tsbtnLanguage.Image")));
            this.tsbtnLanguage.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.tsbtnLanguage.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbtnLanguage.Name = "tsbtnLanguage";
            this.tsbtnLanguage.Size = new System.Drawing.Size(50, 20);
            this.tsbtnLanguage.Text = "toolStripDropDownButton2";
            this.tsbtnLanguage.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.tsbtnLanguage_DropDownItemClicked);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripMenuItem3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem3.Image")));
            this.toolStripMenuItem3.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(189, 34);
            this.toolStripMenuItem3.Tag = "ZH";
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripMenuItem4.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem4.Image")));
            this.toolStripMenuItem4.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(189, 34);
            this.toolStripMenuItem4.Tag = "EN";
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripMenuItem5.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem5.Image")));
            this.toolStripMenuItem5.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(189, 34);
            this.toolStripMenuItem5.Tag = "GE";
            // 
            // tslbMessage
            // 
            this.tslbMessage.ActiveLinkColor = System.Drawing.Color.Black;
            this.tslbMessage.AutoSize = false;
            this.tslbMessage.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.tslbMessage.Name = "tslbMessage";
            this.tslbMessage.Size = new System.Drawing.Size(500, 17);
            this.tslbMessage.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tslbError
            // 
            this.tslbError.AutoSize = false;
            this.tslbError.DoubleClickEnabled = true;
            this.tslbError.ForeColor = System.Drawing.Color.Red;
            this.tslbError.Name = "tslbError";
            this.tslbError.Size = new System.Drawing.Size(767, 17);
            this.tslbError.Spring = true;
            this.tslbError.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.tslbError.DoubleClick += new System.EventHandler(this.tslbError_DoubleClick);
            // 
            // Noticor
            // 
            this.Noticor.ContextMenuStrip = this.NoticeMenu;
            this.Noticor.Icon = ((System.Drawing.Icon)(resources.GetObject("Noticor.Icon")));
            this.Noticor.Visible = true;
            this.Noticor.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Noticor_MouseClick);
            // 
            // NoticeMenu
            // 
            this.NoticeMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmQuit});
            this.NoticeMenu.Name = "NoticeMenu";
            this.NoticeMenu.Size = new System.Drawing.Size(99, 26);
            this.NoticeMenu.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.NoticeMenu_ItemClicked);
            // 
            // tsmQuit
            // 
            this.tsmQuit.Name = "tsmQuit";
            this.tsmQuit.Size = new System.Drawing.Size(98, 22);
            this.tsmQuit.Text = "退出";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.panel_Main);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel4.Location = new System.Drawing.Point(0, 175);
            this.panel4.Margin = new System.Windows.Forms.Padding(0);
            this.panel4.Name = "panel4";
            this.panel4.Padding = new System.Windows.Forms.Padding(16, 8, 16, 8);
            this.panel4.Size = new System.Drawing.Size(1378, 515);
            this.panel4.TabIndex = 17;
            // 
            // panel_Main
            // 
            this.panel_Main.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel_Main.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel_Main.Location = new System.Drawing.Point(16, 8);
            this.panel_Main.Margin = new System.Windows.Forms.Padding(0);
            this.panel_Main.Name = "panel_Main";
            this.panel_Main.Size = new System.Drawing.Size(1346, 499);
            this.panel_Main.TabIndex = 0;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panel3.Controls.Add(this.pnlSystem);
            this.panel3.Controls.Add(this.pnlDocument);
            this.panel3.Controls.Add(this.pnlNavigator);
            this.panel3.Controls.Add(this.pnlEdit);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel3.ForeColor = System.Drawing.SystemColors.ControlText;
            this.panel3.Location = new System.Drawing.Point(0, 690);
            this.panel3.Margin = new System.Windows.Forms.Padding(0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1378, 68);
            this.panel3.TabIndex = 0;
            // 
            // pnlSystem
            // 
            this.pnlSystem.Controls.Add(this.btnExit);
            this.pnlSystem.Controls.Add(this.btnLock);
            this.pnlSystem.Location = new System.Drawing.Point(16, 7);
            this.pnlSystem.Name = "pnlSystem";
            this.pnlSystem.Size = new System.Drawing.Size(135, 54);
            this.pnlSystem.TabIndex = 20;
            // 
            // btnExit
            // 
            this.btnExit.DefaultText = null;
            this.btnExit.Image = ((System.Drawing.Image)(resources.GetObject("btnExit.Image")));
            this.btnExit.Location = new System.Drawing.Point(0, 0);
            this.btnExit.Name = "btnExit";
            this.btnExit.PromissionId = 0;
            this.btnExit.Size = new System.Drawing.Size(54, 54);
            this.btnExit.TabIndex = 16;
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // btnLock
            // 
            this.btnLock.DefaultText = null;
            this.btnLock.Enabled = false;
            this.btnLock.Image = ((System.Drawing.Image)(resources.GetObject("btnLock.Image")));
            this.btnLock.Location = new System.Drawing.Point(81, 0);
            this.btnLock.Name = "btnLock";
            this.btnLock.PromissionId = 0;
            this.btnLock.Size = new System.Drawing.Size(54, 54);
            this.btnLock.TabIndex = 1;
            this.btnLock.UseVisualStyleBackColor = true;
            // 
            // pnlDocument
            // 
            this.pnlDocument.Controls.Add(this.buttonFx9);
            this.pnlDocument.Controls.Add(this.btnImport);
            this.pnlDocument.Controls.Add(this.btnExport);
            this.pnlDocument.Controls.Add(this.btnPrint);
            this.pnlDocument.Location = new System.Drawing.Point(296, 7);
            this.pnlDocument.Name = "pnlDocument";
            this.pnlDocument.Size = new System.Drawing.Size(297, 54);
            this.pnlDocument.TabIndex = 19;
            // 
            // buttonFx9
            // 
            this.buttonFx9.DefaultText = null;
            this.buttonFx9.Enabled = false;
            this.buttonFx9.Image = ((System.Drawing.Image)(resources.GetObject("buttonFx9.Image")));
            this.buttonFx9.Location = new System.Drawing.Point(243, 0);
            this.buttonFx9.Name = "buttonFx9";
            this.buttonFx9.PromissionId = 0;
            this.buttonFx9.Size = new System.Drawing.Size(54, 54);
            this.buttonFx9.TabIndex = 2;
            this.buttonFx9.UseVisualStyleBackColor = true;
            // 
            // btnImport
            // 
            this.btnImport.DefaultText = null;
            this.btnImport.Enabled = false;
            this.btnImport.Image = ((System.Drawing.Image)(resources.GetObject("btnImport.Image")));
            this.btnImport.Location = new System.Drawing.Point(162, 0);
            this.btnImport.Name = "btnImport";
            this.btnImport.PromissionId = 0;
            this.btnImport.Size = new System.Drawing.Size(54, 54);
            this.btnImport.TabIndex = 5;
            this.btnImport.UseVisualStyleBackColor = true;
            // 
            // btnExport
            // 
            this.btnExport.DefaultText = null;
            this.btnExport.Enabled = false;
            this.btnExport.Image = ((System.Drawing.Image)(resources.GetObject("btnExport.Image")));
            this.btnExport.Location = new System.Drawing.Point(81, 0);
            this.btnExport.Name = "btnExport";
            this.btnExport.PromissionId = 0;
            this.btnExport.Size = new System.Drawing.Size(54, 54);
            this.btnExport.TabIndex = 15;
            this.btnExport.UseVisualStyleBackColor = true;
            this.btnExport.Click += new System.EventHandler(this.btnExport_Click);
            // 
            // btnPrint
            // 
            this.btnPrint.DefaultText = null;
            this.btnPrint.Enabled = false;
            this.btnPrint.Image = ((System.Drawing.Image)(resources.GetObject("btnPrint.Image")));
            this.btnPrint.Location = new System.Drawing.Point(0, 0);
            this.btnPrint.Name = "btnPrint";
            this.btnPrint.PromissionId = 0;
            this.btnPrint.Size = new System.Drawing.Size(54, 54);
            this.btnPrint.TabIndex = 3;
            this.btnPrint.UseVisualStyleBackColor = true;
            this.btnPrint.Click += new System.EventHandler(this.btnPrint_Click);
            // 
            // pnlNavigator
            // 
            this.pnlNavigator.Controls.Add(this.btnUp);
            this.pnlNavigator.Controls.Add(this.btnDown);
            this.pnlNavigator.Controls.Add(this.btnRight);
            this.pnlNavigator.Controls.Add(this.btnLeft);
            this.pnlNavigator.Location = new System.Drawing.Point(715, 7);
            this.pnlNavigator.Name = "pnlNavigator";
            this.pnlNavigator.Size = new System.Drawing.Size(297, 54);
            this.pnlNavigator.TabIndex = 18;
            // 
            // btnUp
            // 
            this.btnUp.DefaultText = null;
            this.btnUp.Enabled = false;
            this.btnUp.Image = ((System.Drawing.Image)(resources.GetObject("btnUp.Image")));
            this.btnUp.Location = new System.Drawing.Point(81, 0);
            this.btnUp.Name = "btnUp";
            this.btnUp.PromissionId = 0;
            this.btnUp.Size = new System.Drawing.Size(54, 54);
            this.btnUp.TabIndex = 10;
            this.btnUp.UseVisualStyleBackColor = true;
            // 
            // btnDown
            // 
            this.btnDown.DefaultText = null;
            this.btnDown.Enabled = false;
            this.btnDown.Image = ((System.Drawing.Image)(resources.GetObject("btnDown.Image")));
            this.btnDown.Location = new System.Drawing.Point(162, 0);
            this.btnDown.Name = "btnDown";
            this.btnDown.PromissionId = 0;
            this.btnDown.Size = new System.Drawing.Size(54, 54);
            this.btnDown.TabIndex = 11;
            this.btnDown.UseVisualStyleBackColor = true;
            // 
            // btnRight
            // 
            this.btnRight.DefaultText = null;
            this.btnRight.Enabled = false;
            this.btnRight.Image = ((System.Drawing.Image)(resources.GetObject("btnRight.Image")));
            this.btnRight.Location = new System.Drawing.Point(243, 0);
            this.btnRight.Name = "btnRight";
            this.btnRight.PromissionId = 0;
            this.btnRight.Size = new System.Drawing.Size(54, 54);
            this.btnRight.TabIndex = 13;
            this.btnRight.UseVisualStyleBackColor = true;
            // 
            // btnLeft
            // 
            this.btnLeft.DefaultText = null;
            this.btnLeft.Enabled = false;
            this.btnLeft.Image = ((System.Drawing.Image)(resources.GetObject("btnLeft.Image")));
            this.btnLeft.Location = new System.Drawing.Point(0, 0);
            this.btnLeft.Name = "btnLeft";
            this.btnLeft.PromissionId = 0;
            this.btnLeft.Size = new System.Drawing.Size(54, 54);
            this.btnLeft.TabIndex = 12;
            this.btnLeft.UseVisualStyleBackColor = true;
            // 
            // pnlEdit
            // 
            this.pnlEdit.Controls.Add(this.btnNew);
            this.pnlEdit.Controls.Add(this.btnSave);
            this.pnlEdit.Controls.Add(this.btnAlter);
            this.pnlEdit.Controls.Add(this.btnDelete);
            this.pnlEdit.Location = new System.Drawing.Point(1074, 7);
            this.pnlEdit.Name = "pnlEdit";
            this.pnlEdit.Size = new System.Drawing.Size(297, 54);
            this.pnlEdit.TabIndex = 17;
            // 
            // btnNew
            // 
            this.btnNew.DefaultText = null;
            this.btnNew.Enabled = false;
            this.btnNew.Image = ((System.Drawing.Image)(resources.GetObject("btnNew.Image")));
            this.btnNew.Location = new System.Drawing.Point(0, 0);
            this.btnNew.Name = "btnNew";
            this.btnNew.PromissionId = 0;
            this.btnNew.Size = new System.Drawing.Size(54, 54);
            this.btnNew.TabIndex = 0;
            this.btnNew.UseVisualStyleBackColor = true;
            this.btnNew.Click += new System.EventHandler(this.btnNew_Click);
            // 
            // btnSave
            // 
            this.btnSave.DefaultText = null;
            this.btnSave.Enabled = false;
            this.btnSave.Image = ((System.Drawing.Image)(resources.GetObject("btnSave.Image")));
            this.btnSave.Location = new System.Drawing.Point(243, 0);
            this.btnSave.Name = "btnSave";
            this.btnSave.PromissionId = 0;
            this.btnSave.Size = new System.Drawing.Size(54, 54);
            this.btnSave.TabIndex = 6;
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnAlter
            // 
            this.btnAlter.DefaultText = null;
            this.btnAlter.Enabled = false;
            this.btnAlter.Image = ((System.Drawing.Image)(resources.GetObject("btnAlter.Image")));
            this.btnAlter.Location = new System.Drawing.Point(162, 0);
            this.btnAlter.Name = "btnAlter";
            this.btnAlter.PromissionId = 0;
            this.btnAlter.Size = new System.Drawing.Size(54, 54);
            this.btnAlter.TabIndex = 4;
            this.btnAlter.UseVisualStyleBackColor = true;
            this.btnAlter.Click += new System.EventHandler(this.btnAlter_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.DefaultText = null;
            this.btnDelete.Enabled = false;
            this.btnDelete.Image = ((System.Drawing.Image)(resources.GetObject("btnDelete.Image")));
            this.btnDelete.Location = new System.Drawing.Point(81, 0);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.PromissionId = 0;
            this.btnDelete.Size = new System.Drawing.Size(54, 54);
            this.btnDelete.TabIndex = 7;
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // panel5
            // 
            this.panel5.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panel5.Controls.Add(this.panel2);
            this.panel5.Controls.Add(this.panel1);
            this.panel5.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel5.Location = new System.Drawing.Point(0, 0);
            this.panel5.Margin = new System.Windows.Forms.Padding(0);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(1378, 175);
            this.panel5.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.lbAlarm);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Padding = new System.Windows.Forms.Padding(10, 2, 10, 0);
            this.panel2.Size = new System.Drawing.Size(1219, 175);
            this.panel2.TabIndex = 40;
            // 
            // lbAlarm
            // 
            this.lbAlarm.BackColor = System.Drawing.Color.Black;
            this.lbAlarm.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lbAlarm.Dock = System.Windows.Forms.DockStyle.Top;
            this.lbAlarm.Font = new System.Drawing.Font("SimSun", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbAlarm.ForeColor = System.Drawing.Color.Red;
            this.lbAlarm.Location = new System.Drawing.Point(10, 2);
            this.lbAlarm.Name = "lbAlarm";
            this.lbAlarm.Size = new System.Drawing.Size(1199, 23);
            this.lbAlarm.TabIndex = 30;
            this.lbAlarm.Text = "Test测试";
            this.lbAlarm.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.lbClock);
            this.panel1.Controls.Add(this.lbOperator);
            this.panel1.Controls.Add(this.picLogo);
            this.panel1.Controls.Add(this.lb_Crew);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel1.Location = new System.Drawing.Point(1219, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(159, 175);
            this.panel1.TabIndex = 39;
            // 
            // lbClock
            // 
            this.lbClock.Font = new System.Drawing.Font("SimHei", 10.5F);
            this.lbClock.Location = new System.Drawing.Point(7, 2);
            this.lbClock.Name = "lbClock";
            this.lbClock.Size = new System.Drawing.Size(145, 23);
            this.lbClock.TabIndex = 25;
            this.lbClock.Text = "time";
            this.lbClock.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lbOperator
            // 
            this.lbOperator.Font = new System.Drawing.Font("SimHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbOperator.Location = new System.Drawing.Point(50, 28);
            this.lbOperator.Name = "lbOperator";
            this.lbOperator.Size = new System.Drawing.Size(97, 23);
            this.lbOperator.TabIndex = 26;
            this.lbOperator.Text = "员工姓名";
            this.lbOperator.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // picLogo
            // 
            this.picLogo.Location = new System.Drawing.Point(7, 56);
            this.picLogo.Name = "picLogo";
            this.picLogo.Size = new System.Drawing.Size(145, 116);
            this.picLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picLogo.TabIndex = 37;
            this.picLogo.TabStop = false;
            // 
            // lb_Crew
            // 
            this.lb_Crew.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lb_Crew.Cursor = System.Windows.Forms.Cursors.Hand;
            this.lb_Crew.Font = new System.Drawing.Font("SimHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lb_Crew.Location = new System.Drawing.Point(7, 28);
            this.lb_Crew.Name = "lb_Crew";
            this.lb_Crew.Size = new System.Drawing.Size(37, 25);
            this.lb_Crew.TabIndex = 38;
            this.lb_Crew.Text = "班组";
            this.lb_Crew.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lb_Crew.Click += new System.EventHandler(this.labelFx1_Click);
            // 
            // MainFrame
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.AutoScroll = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(1378, 780);
            this.ControlBox = false;
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.panel5);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainFrame";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.NoticeMenu.ResumeLayout(false);
            this.panel4.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.pnlSystem.ResumeLayout(false);
            this.pnlDocument.ResumeLayout(false);
            this.pnlNavigator.ResumeLayout(false);
            this.pnlEdit.ResumeLayout(false);
            this.panel5.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picLogo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private PanelFx panel4;
        private PanelFx panel5;
        private System.Windows.Forms.Label lbClock;
        private System.Windows.Forms.Timer ClockTimer;
        private System.Windows.Forms.Label lbOperator;
        private System.Windows.Forms.Panel panel_Main;
        private System.Windows.Forms.Label lbAlarm;
        private ButtonFx btnNew;
        private ButtonFx btnAlter;
        private ButtonFx btnImport;
        private ButtonFx btnSave;
        private ButtonFx btnDelete;
        private ButtonFx btnUp;
        private ButtonFx btnDown;
        private ButtonFx btnLeft;
        private ButtonFx btnRight;
        private ButtonFx buttonFx9;
        private ButtonFx btnExport;
        private ButtonFx btnLock;
        private ButtonFx btnPrint;
        private PanelFx panel3;
        private System.Windows.Forms.PictureBox picLogo;
        private FlashLabel lb_Crew;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel tslbConnectionState;
        private ButtonFx btnExit;
        private System.Windows.Forms.ToolStripStatusLabel tslStatus;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ToolStripDropDownButton toolStripDropDownButton1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripDropDownButton tsbtnLanguage;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem5;
        private System.Windows.Forms.Panel pnlSystem;
        private System.Windows.Forms.Panel pnlDocument;
        private System.Windows.Forms.Panel pnlNavigator;
        private System.Windows.Forms.Panel pnlEdit;
        private System.Windows.Forms.NotifyIcon Noticor;
        private System.Windows.Forms.ContextMenuStrip NoticeMenu;
        private System.Windows.Forms.ToolStripMenuItem tsmQuit;
        private System.Windows.Forms.ToolStripStatusLabel tslbMessage;
        private System.Windows.Forms.ToolStripStatusLabel tslbError;
    }
}