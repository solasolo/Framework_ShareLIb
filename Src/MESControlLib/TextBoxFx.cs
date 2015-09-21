using GLEO.Base;
using GLEO.UI;
using System;
using System.ComponentModel;
using System.Drawing;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace GLEO.MES.UI
{

    /// <summary>
    /// Author Ls
    /// Date   UnKnown
    /// Version 1.0
    /// 
    /// EditBy Gk
    /// Support I18N  对语言
    /// Verification Data 验证数据
    /// Add DataFiled  对应数据库的字段名
    /// 日期时间验证,只读, 格式2013-12-21 09:12:55
    /// 支持日期验证,设置后只读,gk,格式2012-12-11
    /// </summary>
    /// 

    [UIExtend(ExtendClass="GLEO.MES.UI.TextBoxFxUIExtend")]
    public class TextBoxFx : ThreadTextBox, IVerifiable
    {
        private bool _WriteLock;
        private Verification _Verfier;

        public string DataFiled { get; set; }

        public bool WriteLock 
        {
            get 
            {
                return _WriteLock;
            } 

            set
            {
                this._WriteLock = value;

                this.ReadOnly = this._WriteLock;
            }
        }

        public Verification Validation
        {
            get 
            {
                return this._Verfier;
            }
        }

        public VerifyType VerifyType
        {
            get
            { 
                return this._Verfier.Type;
            }

            set
            {
                this._Verfier.Type = value;
            }
        }

        public string VerifyCostomer
        {
            get
            {
                return this._Verfier.CustomerRule;
            }

            set
            {
                this._Verfier.CustomerRule = value;
            }
        }

        public bool VeriryRequired
        {
            get 
            {
                return this._Verfier.Required;
            }

            set
            {
                this._Verfier.Required = value;
            }
        }

        public TextBoxFx()
        {
            this._Verfier = new Verification();

            this.WriteLock = false;
            this.BorderStyle = BorderStyle.FixedSingle;

            this.DefaultStyle();
        }

        private void DefaultStyle()
        {
            if (this.ReadOnly)
            {
                this.BackColor = Color.LimeGreen;
                this.Font = new Font(this.Font.Name, this.Font.Size, FontStyle.Bold);
                this.ForeColor = Color.Black;
            }
            else
            {
                this.BackColor = Color.DarkGreen;
                this.Font = new Font(this.Font.Name, this.Font.Size, FontStyle.Bold);
                this.ForeColor = Color.White;
            }
        }

        private void ErrorStyle()
        {
            if (this.ReadOnly)
            {
                this.BackColor = Color.LimeGreen;
                this.Font = new Font(this.Font.Name, this.Font.Size, FontStyle.Bold);
                this.ForeColor = Color.Red;//验证错误标记为红色
            }
            else
            {
                this.BackColor = Color.DarkGreen;
                this.Font = new Font(this.Font.Name, this.Font.Size, FontStyle.Bold);
                this.ForeColor = Color.Red;//验证错误标记为红色
            }
        }


        protected override void OnCreateControl()
        {
            base.OnCreateControl();

            this.DefaultStyle();
        }

        protected override void OnReadOnlyChanged(EventArgs e)
        {
            base.OnReadOnlyChanged(e);

            this.DefaultStyle();
        }

        protected override void OnMouseDown(MouseEventArgs e)
        {
            base.OnMouseDown(e);
        }

        protected override void OnTextChanged(EventArgs e)
        {
            base.OnTextChanged(e);
        }

        protected override void OnLostFocus(EventArgs e)
        {
            if (!this.Verify())
            {
                if (this.Enabled)
                {
                    this.ErrorStyle();
                    this.SelectAll();
                }
            }
            else 
            {
                this.DefaultStyle();
            }

            base.OnLostFocus(e);
        }

        public bool Verify()
        {
            return this._Verfier.Verify(this.Text);
        }
    }

    public class TextBoxFxUIExtend : IUIExtend
    {
        public void SetValue(object ctrl, object obj)
        {
            object Result = null;

            TextBoxFx box = ctrl as TextBoxFx;

            if (box.DataFiled != null)
            {
                string PropName = box.DataFiled.ToString().Trim();

                Result = ReflectHelper.GetObjectProp(obj, PropName);
            }

            box.Text = Result == null ? "" : Result.ToString();
        }

        public void GetValue(object ctrl, object obj)
        {
            TextBoxFx box = ctrl as TextBoxFx;
            object PropValue = box.Text;

            if (box.DataFiled != null)
            {
                string PropName = box.DataFiled.ToString().Trim();

                ReflectHelper.SetObjectProp(obj, PropName, PropValue);
            }
        }

        public void SetReadOnly(object ctrl, bool value)
        {
            TextBoxFx box = ctrl as TextBoxFx;

            if (box.WriteLock)
            {
                box.ReadOnly = true;
            }
            else
            {
                box.ReadOnly = value;
            }
        }
    }
}