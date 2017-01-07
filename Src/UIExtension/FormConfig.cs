using GLEO.Base;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml;

namespace GLEO.Utility
{

    public abstract class BaseFormConfigItem
    {
        protected BaseFormalPrint Form;

        protected float X;
        protected float Y;

        public BaseFormConfigItem(BaseFormalPrint form, XmlNode node)
        {
            this.Form = form;

            this.X = 0;
            this.Y = 0;

            XMLHelper.GetAttribute(node, "X", ref this.X);
            XMLHelper.GetAttribute(node, "Y", ref this.Y);

            this.X += form.OffsetX;
            this.Y += form.OffsetY;
        }

        public abstract void Print(IPrintProvider g);
    }

    class TextConfigItem : BaseFormConfigItem
    {
        protected Font TextFont;
        protected string _Text;
        protected bool IsBold;

        protected virtual string Text
        {
            get
            {
                return this._Text;
            }
        }

        public TextConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
            this._Text = String.Empty;
            this.IsBold = false;

            XMLHelper.GetText(node, ref this._Text);
            XMLHelper.GetAttribute(node, "Bold", ref this.IsBold);

            string FontName = SystemFonts.DefaultFont.Name;
            int FontSize = 8;

            XMLHelper.GetAttribute(node, "Font", ref FontName);

            FontStyle style = this.IsBold ? FontStyle.Bold : FontStyle.Regular;
            XMLHelper.GetAttribute(node, "Size", ref FontSize);
            this.TextFont = new Font(FontName, (float)FontSize, style, GraphicsUnit.Millimeter);
        }

        public override void Print(IPrintProvider g)
        {
            g.DrawText(this.Text, this.TextFont, this.X, this.Y);
        }
    }

    class FieldConfigItem : TextConfigItem
    {
        protected string Field;

        protected override string Text
        {
            get
            {
                if (String.IsNullOrEmpty(this._Text))
                {
                    this._Text = Form.ReadField(this.Field);
                }
                
                return this._Text;
            }
        }

        public FieldConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Field = String.Empty;

            XMLHelper.GetAttribute(node, "Field", ref this.Field);
        }

        public override void Print(IPrintProvider g)
        {
            base.Print(g);
        }
    }

    class FontBarcodeConfigItem : FieldConfigItem
    {
        protected int BarHeight;

        public FontBarcodeConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
        }

        public override void Print(IPrintProvider g)
        {
            float h = g.GetTextHeight(this.TextFont);

            for (int i = 0; i < this.BarHeight; i++)
            {
                g.DrawBarFont(this.Text, this.TextFont, this.X, this.Y);
            }
        }
    }

    class BarcodeConfigItem : FieldConfigItem
    {
        protected string Type;
        protected float Height;
        protected float Width;

        public BarcodeConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
            XMLHelper.GetAttribute(node, "Type", ref this.Type);
            XMLHelper.GetAttribute(node, "Height", ref this.Height);
            XMLHelper.GetAttribute(node, "Width", ref this.Width);
        }

        public override void Print(IPrintProvider g)
        {
            g.DrawBar(this.Text, this.Type, this.X, this.Y, this.Width, this.Height);
        }
    }

    class LineConfigItem : BaseFormConfigItem
    {
        protected float ToX;
        protected float ToY;
        protected float Width;

        public LineConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Width = 1;

            XMLHelper.GetAttribute(node, "ToX", ref this.ToX);
            XMLHelper.GetAttribute(node, "ToY", ref this.ToY);
            XMLHelper.GetAttribute(node, "Width", ref this.Width);

            this.ToX += form.OffsetX;
            this.ToY += form.OffsetY;
        }

        public override void Print(IPrintProvider g)
        {
            g.DrawLine(this.X, this.Y, this.ToX, this.ToY, this.Width);
        }
    }

    class ImageConfigItem : BaseFormConfigItem
    {
        protected Image Image;

        public ImageConfigItem(BaseFormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Image = null;

            string BasePath = AppDomain.CurrentDomain.BaseDirectory;
            string path = null;
            XMLHelper.GetAttribute(node, "Path", ref path);

            path = BasePath + path;

            if (!String.IsNullOrEmpty(path))
            {
                if (File.Exists(path))
                {
                    this.Image = Image.FromFile(path);
                }
            }
        }

        public override void Print(IPrintProvider g)
        {
            g.DrawImage(this.Image, this.X, this.Y);
        }
    }
}
