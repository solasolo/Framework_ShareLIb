//#define MESSAGE_INVOKE

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Xml;
using System.IO;
using System.Threading;
using GLEO.MES.UI;
using GLEO.UI;
using PictureLib;
using GLEO.MES.Sys;
using GLEO.MES.Network;
using PictureLib;
using GLEO.DBUtility;
using System.Reflection;
using GLEO.Base;

namespace PictureLib
{
    public abstract partial class MainFrame : Form, IExceptionHandle, IDbSupply, IEditCtrl, INavigationCtrl, IMessageSender
    {
        const int MSG_STATUS = 9001;
        const int MSG_ALERT = 9002;
        const int MSG_SHIFT_CHANGE = 9003;

        const int WM_COMM_MESSAGE = WinAPIs.WM_SELF_LOAD + 10;

        private IntPtr WinHandle;
        private object MessageLocker;

        class CommMessage
        {
            public readonly short Code;
            public readonly MessageParser Parser;

            public CommMessage(short code, MessageParser parser)
            {
                Code = code;
                Parser = parser;
            }
        }

        Queue<CommMessage> MessageBuffer;

        delegate void SendMessageDel(object args);
        delegate void HandleDataDelegate(short code, MessageParser parser);
        delegate void ExceptionDelegate(Exception ex);

        public bool IsInDesignMode { get; set; }

        bool WindowsMode;

        private BaseControl CurrentPicture;
        private ButtonFx[] MenuButtons;
        private AlarmTranslator AlertTranfer;
        private BaseDbSupport DB;

        #region 后台通信

        private SocketClient Client;

        bool DEBUG = true;
        FrmCommunication frmMsg;

        SendMessageDel sendMsgDel;
        OptionControl optioncontrol;

        #endregion

        #region 调试窗口

        private void ThreadShowForm()
        {
            this.frmMsg.Invoke(sendMsgDel);
        }

        private void sendMsgToForm(object args)
        {
            if (args != null)
            {
                if (args is MessageEnity)
                {
                    this.frmMsg.Setdata((MessageEnity)args);
                }
                else
                {
                    this.frmMsg.Setdata(args.ToString());
                }
            }
        }

        #endregion

        public MainFrame()
        {
            InitializeComponent();

            string BasePath = AppDomain.CurrentDomain.BaseDirectory;

            // Memeber Init
            this.WinHandle = this.Handle;
            CurrentPicture = null;

            this.DB = this.CreateDatabase();

            MessageBuffer = new Queue<CommMessage>();
            MessageLocker = new Object();

            XmlDocument doc = new XmlDocument();
            XmlNode node;
            string Path = AppDomain.CurrentDomain.BaseDirectory + "..\\Data\\L2ServiceConfig.xml";
            string host = "127.0.0.1";
            int port = 8888;

            doc.Load(Path);
            XmlElement root = doc.DocumentElement;
            node = root.SelectSingleNode("Server/HMIPort");
            XMLHelper.GetText(node, ref port);

            node = root.SelectSingleNode("Server/HMIIP");
            XMLHelper.GetText(node, ref host);

            Client = new SocketClient(host, port);
            Client.OnDataReceived += new SocketMessageDelegate(client_DataReceived);
            Client.OnError += new SocketErrorDelegate(client_ErrorHandle);

            frmMsg = new FrmCommunication();
            sendMsgDel = sendMsgToForm;

            AlertTranfer = new AlarmTranslator(this.CreateDatabase() as IDBAlarmTranslator);

            // UI Init
            this.lbAlarm.Text = String.Empty;

            string LogoFile = BasePath + "logo.png";
            if (File.Exists(LogoFile))
            {
                this.picLogo.Image = Image.FromFile(LogoFile);
            }

            this.ResetButton();
            this.SetLanguageButtons();

            this.WindowsMode = false;
            this.SwichWindowMode(this.WindowsMode);

            optioncontrol = OptionControl.Instance;
            optioncontrol.SetDb(DB);
            optioncontrol.Init();
        }

        protected override void DefWndProc(ref Message m)
        {
            switch (m.Msg)
            {
                case WinAPIs.WM_SELF_LOAD:
                    this.Client.Start();
                    this.ShowLogin();
                    break;

                case WM_COMM_MESSAGE:
                    this.DisptchCommMessage();
                    break;

                default:
                    base.DefWndProc(ref m);
                    break;
            }
        }

        protected override void OnLoad(EventArgs e)
        {
            this.CreateMenuButtons();

            WindowState = System.Windows.Forms.FormWindowState.Maximized;

            this.ClockTimer.Start();
            this.lbClock.Text = Convert.ToString(DateTime.Now.ToLocalTime());

            if (!this.IsInDesignMode)
            {
                this.LoadRefresh();
            }

            btnAlter.Enabled = false;
            btnDelete.Enabled = false;
            btnDown.Enabled = false;
            btnExport.Enabled = false;
            btnImport.Enabled = false;
            btnLeft.Enabled = false;
            btnNew.Enabled = false;
            btnRight.Enabled = false;
            btnSave.Enabled = false;
            btnUp.Enabled = false;

            this.lbOperator.Text = String.Empty;

            base.OnLoad(e);
        }

        private void LoadRefresh()
        {
            WinAPIs.PostMessage(this.Handle, WinAPIs.WM_SELF_LOAD, new IntPtr(0), new IntPtr(0));
        }

        private void DisptchCommMessage()
        {
            bool Incoming = true;
            int cmd = 0;
            MessageParser parser = null;

            lock (MessageLocker)
            {
                while (this.Client.GetData(out cmd, out parser))
                {
                    this.HandleData((short)cmd, parser);
                }
            }
        }

        private void SafeInvoke(Delegate method, params Object[] args)
        {
            try
            {
                if (this.InvokeRequired)
                {
                    this.Invoke(method, args);
                }
                else
                {
                    method.DynamicInvoke(args);
                }
            }
            catch (Exception)
            {
            }
        }

        private void ResetMenuButtons()
        {
            for (int i = 0; i < 20; i++)
            {
                ButtonFx n = MenuButtons[i];

                if (n != null)
                {
                    n.BackColor = SystemColors.ActiveBorder;
                    n.UseVisualStyleBackColor = true;
                }
            }
        }

        private void ResetButton()
        {
            int PanelWidth = 296;
            int PanelSpace = (Screen.PrimaryScreen.WorkingArea.Width - 16 * 2 - PanelWidth * 4) / 3;

            pnlDocument.Left = PanelWidth + PanelSpace;
            pnlNavigator.Left = 2 * (PanelWidth + PanelSpace);
            pnlEdit.Left = 3 * (PanelWidth + PanelSpace);
        }

        private void LoadControl(BaseControl obj)
        {
            this.panel_Main.Controls.Clear();

            if (obj != null)
            {
                this.panel_Main.Controls.Add(obj);
                obj.Dock = DockStyle.Fill;
            }
        }

        public void CreateMenuButtons()
        {
            int Count = 0;
            int ScreenX = Screen.PrimaryScreen.WorkingArea.Width;
            int ButtonX = 250;
            int ButtonY = 35;
            int XSpace = (ScreenX - panel1.Width - ButtonX * 5 - 20) / 4;

            this.MenuButtons = new ButtonFx[20];

            for (int i = 0; i < 20; i++)
            {
                this.MenuButtons[i] = null;
            }

            XmlDocument doc = new XmlDocument();
            string filepath = AppDomain.CurrentDomain.BaseDirectory + "..\\Data\\Menu.xml";

            if (File.Exists(filepath))
            {
                doc.Load(filepath);
                XmlElement root = doc.DocumentElement;
                if (root != null)
                {
                    int i = 0;
                    int j = 0;

                    foreach (XmlElement main in root.ChildNodes)
                    {
                        int x = 10 + j * (ButtonX + XSpace);
                        int y = 30 + i * 35;

                        ButtonFx btn = new ButtonFx();
                        btn.Location = new Point(x, y);
                        btn.Size = new Size(ButtonX, ButtonY);
                        btn.Parent = this.panel5;
                        btn.BackColor = SystemColors.ActiveBorder;
                        btn.UseVisualStyleBackColor = true;
                        btn.Click += new System.EventHandler(buttonFx1_Click);
                        this.panel2.Controls.Add(btn);

                        MenuButtons[Count++] = btn;

                        string text = main.Attributes["Text"].Value;
                        string cls = main.Attributes["Class"].Value;

                        if (cls.IndexOf('.') < 0)
                        {
                            cls = "PictureLib." + cls;
                        }

                        if (string.IsNullOrEmpty(text))
                        {
                            btn.Enabled = false;
                        }
                        else
                        {
                            btn.Text = text;
                            btn.DefaultText = text;
                            btn.Tag = cls;
                        }

                        j++;
                        if (j >= 5)
                        {
                            j = 0; i++;
                            if (i >= 4) break;
                        }

                    }
                }
            }
        }

        private void CreatePanel(string cls)
        {
            Type type = ReflectHelper.CreateType(cls);
            Object obj = null;

            if (type != null)
            {
                ConstructorInfo con = type.GetConstructor(new Type[1] { this.GetType() });
                if (con == null)
                {
                    obj = ReflectHelper.CreateObject(type);
                }
                else
                {
                    obj = ReflectHelper.CreateObject(type, new object[1] { this });
                }
            }

            if (obj != null)
            {
                CurrentPicture = (BaseControl)obj;
                CurrentPicture.SetOwner(this);

                if (obj is INavigation)
                {
                    btnDown.Enabled = true;
                    btnLeft.Enabled = true;
                    btnRight.Enabled = true;
                    btnUp.Enabled = true;
                }
                else
                {
                    btnDown.Enabled = false;
                    btnLeft.Enabled = false;
                    btnRight.Enabled = false;
                    btnUp.Enabled = false;
                }

                if (obj is IReport)
                {
                    btnPrint.Enabled = true;
                    btnExport.Enabled = true;
                    btnImport.Enabled = false;
                }
                else
                {
                    btnPrint.Enabled = false;
                    btnExport.Enabled = false;
                    btnImport.Enabled = false;
                }

                if (obj is IEdit)
                {
                    this.EnableEditButtons(true);
                    this.EditEnd();
                }
                else
                {
                    this.EnableEditButtons(false);
                }

                this.LoadControl(CurrentPicture);
            }
            else
            {
                this.LoadControl(null);
            }
        }

        public void SendData(short cmd, params object[] data)
        {
            Client.Send(cmd, data);
        }

        private void ShowLogin()
        {
            FrmLogin fm = new FrmLogin(this.CreateDatabase());
            if (DialogResult.OK == fm.ShowDialog(this))
            {
                this.SetPermission();
                lbOperator.Text = Global.LoginUser.Name;
            }
            else
            {
                Application.Exit();
            }
        }

        private void SetPermission()
        {
            int role = Global.LoginUser.Role;

            if (role == 0)
            {
                for (int i = 0; i < 20; i++)
                {
                    ButtonFx btn = MenuButtons[i];

                    if (btn != null)
                    {
                        btn.PromissionId = optioncontrol.ReadDictionary(btn.Text, role);
                    }
                }
            }
            else
            {
                for (int i = 0; i < 20; i++)
                {
                    ButtonFx btn = MenuButtons[i];

                    if (btn != null)
                    {
                        btn.PromissionId = optioncontrol.ReadDictionary(btn.Text, role);
                        if (btn.PromissionId == 1 || btn.PromissionId == -1)
                        {
                            btn.Enabled = false;
                        }
                        else
                        {

                        }
                    }
                }
            }
        }

        private void SwichWindowMode(bool mode)
        {
            this.Top = 0;
            this.Left = 0;

            Screen sc = Screen.PrimaryScreen;

            int W = sc.WorkingArea.Width;
            int H = sc.WorkingArea.Height;

            if (mode)
            {
                this.ControlBox = true;
                this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;

                //this.panelFx1.Location = new Point(2, 0);
                //this.panelFx1.Size = new Size(W - 2, 178);

                //this.panelFx2.Location = new Point(2, 178);
                //this.panelFx2.Size = new Size(W - 2, 810);

                //this.panelFx3.Location = new Point(2, 988);
                //this.panelFx3.Size = new Size(W - 2, 70);

                this.Size = new Size(W, H);
                this.Location = new Point(0, 0);
            }
            else
            {
                this.ControlBox = false;
                this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;

                //this.panelFx1.Location = new Point(0, 0);
                //this.panelFx1.Size = new Size(W, 178);

                //this.panelFx2.Location = new Point(0, 178);
                //this.panelFx2.Size = new Size(W, 810);

                //this.panelFx3.Location = new Point(0, 988);
                //this.panelFx3.Size = new Size(W, 70);

                this.Size = new Size(W, H);
                this.Location = new Point(0, 0);
            }
        }

        private void ShowAlert(string id, string param)
        {
            AlarmType type = AlarmType.Unknown;
            string msg = AlertTranfer.ReadAlarmString(id, param, ref type);

            Color c = Color.Gray;
            switch (type)
            {
                case AlarmType.Error:
                    c = Color.Red;
                    break;

                case AlarmType.Warning:
                    c = Color.Yellow;
                    break;

                case AlarmType.Message:
                    c = Color.Green;
                    break;
            }

            lbAlarm.ForeColor = c;
            lbAlarm.Text = msg;
        }

        void ShowException(Exception ex)
        {
            string msg = ex.Message;
            msg = msg.Replace("\n", " ");
            msg = msg.Replace("\r", " ");

            this.tslbError.Text = msg;
            this.tslbError.Tag = ex;
        }

        #region 事件

        private void buttonFx1_Click(object sender, EventArgs e)
        {
            ButtonFx btn = (ButtonFx)sender;

            this.ResetMenuButtons();

            string PanelClass = (string)btn.Tag;

            if (btn.PromissionId == 1)
            {
                UIFunctions.ReadOnly(CurrentPicture, true);
            }

            if (!String.IsNullOrEmpty(PanelClass))
            {
                this.CreatePanel(PanelClass);

                btn.BackColor = Color.Gray;
            }
        }

        private void currentPic_DataChanged(object args)
        {
            this.ResetButton();

            ToolButton buttons = args as ToolButton;

            if (buttons == null)
            {
                return;
            }

            List<PictureLib.ToolButton.ToolButtonType> items = buttons.Getitems();

            foreach (PictureLib.ToolButton.ToolButtonType item in items)
            {
                if (item == PictureLib.ToolButton.ToolButtonType.SAVE)
                {
                    btnSave.Enabled = true;
                }
                else if (item == PictureLib.ToolButton.ToolButtonType.NEW)
                {
                    btnNew.Enabled = true;
                }
                else if (item == PictureLib.ToolButton.ToolButtonType.DELETE)
                {
                    btnDelete.Enabled = true;
                }
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            IEdit editor = this.CurrentPicture as IEdit;
            editor.Add();
        }

        private void btnAlter_Click(object sender, EventArgs e)
        {
            this.EditStart();
            IEdit editor = this.CurrentPicture as IEdit;
            if (editor != null)
            {
                editor.Alter();
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            IEdit editor = this.CurrentPicture as IEdit;
            editor.Save();

            //this.EditEnd();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            IEdit editor = this.CurrentPicture as IEdit;
            if (editor != null)
            {
                editor.Delete();
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            IReport report = this.CurrentPicture as IReport;
            if (report != null)
            {
                report.Print();
            }
        }

        private void btnExport_Click(object sender, EventArgs e)
        {
            IReport report = this.CurrentPicture as IReport;
            if (report != null)
            {
                report.Export();
            }
        }

        private void ClockTimer_Tick(object sender, EventArgs e)
        {
            this.lbClock.Text = Convert.ToString(DateTime.Now.ToLocalTime());

            if (this.Client.IsOnline)
            {
                this.tslbConnectionState.BackColor = Color.Green;
            }
            else
            {
                this.tslbConnectionState.BackColor = Color.Red;
            }
        }

        private void buttonFx7_Click(object sender, EventArgs e)
        {
            WindowsMode = !WindowsMode;

            this.SwichWindowMode(WindowsMode);
        }

        private void buttonFx1_Click_1(object sender, EventArgs e)
        {
            frmMsg.Visible = !frmMsg.Visible;

            frmMsg.TopMost = true;
        }


        private void tsbtnLanguage_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

            string lang = (string)e.ClickedItem.Tag;
            switch (lang)
            {
                case "ZH":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.Chinese;
                    break;
                case "EN":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.English;
                    break;
                case "GE":
                    TranslateLanguage.Instance.CurrentLang = LanguageType.Germany;
                    break;
            }

            this.panel5.Refresh();
            this.panel_Main.Refresh();
        }

        //点下鼠标
        private void Pic_Lang_MouseDown(object sender, MouseEventArgs e)
        {
            PictureBox pic = (PictureBox)sender;
            pic.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
        }

        //弹起鼠标
        private void Pic_Lang_MouseUp(object sender, MouseEventArgs e)
        {
            PictureBox pic = (PictureBox)sender;
            pic.BorderStyle = System.Windows.Forms.BorderStyle.None;
        }

        private void buttonFx2_Click(object sender, EventArgs e)
        {
            FrmChangePwd frmchangepwd = new FrmChangePwd(this.CreateDatabase());
            frmchangepwd.ShowDialog();
        }

        private void labelFx1_Click(object sender, EventArgs e)
        {
            FrmChangeCrew frmchangecrew = new FrmChangeCrew();
            if (frmchangecrew.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                FrmLogin fm = new FrmLogin(this.CreateDatabase());
                fm.ShowDialog(this);
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            //Application.Exit();
            this.Hide();
        }

        private void Noticor_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Show();
            }
        }

        private void NoticeMenu_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            if (e.ClickedItem == tsmQuit)
            {
                Application.Exit();
            }
        }


        private void tslbError_DoubleClick(object sender, EventArgs e)
        {
            if (tslbError.Tag != null)
            {
                Exception ex = (Exception)tslbError.Tag;

                MessageBox.Show(ex.Message + "\r\n" + ex.StackTrace.ToString());
            }
        }
        #endregion

        #region 后台通信

        private void client_ErrorHandle(object sender, SocketErrorEventArgs e)
        {
            if (DEBUG)
            {
                this.SafeInvoke(sendMsgDel, new object[] { e.Exception.Message });
            }
        }

        private void client_DataReceived(object sender, SocketMessageEventArgs e)
        {
            MessageEnity item = null;

            if (DEBUG)
            {
                this.SafeInvoke(sendMsgDel, new object[] { item });
            }

            short cmd;
            MessageParser parser;


#if MESSAGE_INVOKE
            
            this.SafeInvoke(new HandleDataDelegate(this.HandleData), new object[] { cmd, parser });
#else

            WinAPIs.PostMessage(this.WinHandle, WM_COMM_MESSAGE, new IntPtr(0), new IntPtr(0));
#endif
        }

        #endregion

        #region Function Buttons Control

        private void EnableEditButtons(bool en)
        {
            if (en)
            {
                btnAlter.Enabled = true;
                btnSave.Enabled = true;
                btnDelete.Enabled = true;
                btnNew.Enabled = true;
            }
            else
            {
                EditDisable();
            }
        }

        private void SetLanguageButtons()
        {
            if (this.CanMultilanguage())
            {
                //this.Pic_LangEN.Visible = true;
                //this.Pic_LangGE.Visible = true;
                //this.Pic_LangZH.Visible = true;
            }
            else
            {
                //this.Pic_LangEN.Visible = false;
                //this.Pic_LangGE.Visible = false;
                //this.Pic_LangZH.Visible = false;
            }
        }

        #endregion

        #region Interface IEditCtrl

        public void EditEnd()
        {
            if (this.CurrentPicture is IEdit)
            {
                btnAlter.Enabled = true;
                btnSave.Enabled = false;
                btnDelete.Enabled = true;
                btnNew.Enabled = true;
            }
            else
            {
                this.EditDisable();
            }
        }

        public void EditStart()
        {
            if (this.CurrentPicture is IEdit)
            {
                btnAlter.Enabled = false;
                btnSave.Enabled = true;
                btnDelete.Enabled = false;
                btnNew.Enabled = false;
            }
            else
            {
                this.EditDisable();
            }
        }

        public void EditDisable()
        {
            btnAlter.Enabled = false;
            btnSave.Enabled = false;
            btnDelete.Enabled = false;
            btnNew.Enabled = false;
        }

        #endregion

        public void HandleException(Exception ex)
        {
            this.SafeInvoke(new ExceptionDelegate(this.ShowException), new object[] { ex });
        }

        public abstract BaseDbSupport CreateDatabase();

        protected virtual void HandleData(short cmd, MessageParser parser)
        {
            if (cmd == MSG_STATUS)
            {
                string msg = parser.GetUnicodeString();

                this.tslbMessage.Text = msg;
            }
            else if (cmd == MSG_ALERT)
            {
                //故障报警信息
                string id = parser.GetString();
                String param = parser.GetUnicodeString();

                this.ShowAlert(id, param);
            }
            else if (cmd == 2005)
            {
                //系统换班响应
                string msg = parser.GetString();
                lb_Crew.Flash(50, 500);
            }
            else
            {
                if (CurrentPicture is ICommunication)
                {
                    //实现了接口ICommunication 可以处理的电文
                    ICommunication intf = CurrentPicture as ICommunication;
                    intf.HandleData(cmd, parser);
                }
            }
        }

        protected virtual bool CanMultilanguage()
        {
            return true;
        }

        protected void UpdateShiftCrew(string str)
        {
            this.lb_Crew.Text = str;
        }
    }
}
