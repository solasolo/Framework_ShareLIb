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
    abstract class BaseFormConfigItem
    {
        protected FormalPrint Form;

        protected float X;
        protected float Y;

        public BaseFormConfigItem(FormalPrint form, XmlNode node)
        {
            this.Form = form;

            this.X = 0;
            this.Y = 0;

            XMLHelper.GetAttribute(node, "X", ref this.X);
            XMLHelper.GetAttribute(node, "Y", ref this.Y);

            this.X += form.OffsetX;
            this.Y += form.OffsetY;
        }

        public abstract void Print(Graphics g);
    }

    class TextConfigItem : BaseFormConfigItem
    {
        protected Font TextFont;
        protected string Text;
        protected bool IsBold;

        public TextConfigItem(FormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Text = String.Empty;
            this.IsBold = false;

            XMLHelper.GetText(node, ref this.Text); 
            XMLHelper.GetAttribute(node, "Bold", ref this.IsBold);

            string FontName = SystemFonts.DefaultFont.Name;
            int FontSize = 8;

            XMLHelper.GetAttribute(node, "Font", ref FontName);

            FontStyle style = this.IsBold ? FontStyle.Bold : FontStyle.Regular;
            XMLHelper.GetAttribute(node, "Size", ref FontSize);
            this.TextFont = new Font(FontName, (float)FontSize, style, GraphicsUnit.Millimeter);
        }

        public override void Print(Graphics g)
        {
            g.DrawString(this.Text, this.TextFont, Form.PrintBrush, this.X, this.Y);
        }
    }

    class FieldConfigItem : TextConfigItem
    {
        private string Field;

        public FieldConfigItem(FormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Field = String.Empty;

            XMLHelper.GetAttribute(node, "Field", ref this.Field);
        }

        public override void Print(Graphics g)
        {
            this.Text = Form.ReadField(this.Field);

            base.Print(g);
        }
    }

    class FontBarcodeConfigItem : FieldConfigItem
    {
        protected int BarHeight;

        public FontBarcodeConfigItem(FormalPrint form, XmlNode node)
            : base(form, node)
        {
        }

        public override void Print(Graphics g)
        {
            float h = this.TextFont.GetHeight(g);
            for (int i = 0; i < this.BarHeight; i++)
            {
                base.Print(g);
            }
        }
    }

    class ImageConfigItem : BaseFormConfigItem
    {
        protected Image Image;

        public ImageConfigItem(FormalPrint form, XmlNode node)
            : base(form, node)
        {
            this.Image = null;

            string BasePath = AppDomain.CurrentDomain.BaseDirectory;
            string path = null;
            XMLHelper.GetAttribute(node, "Path", ref path);

            path = BasePath + path;

            if(!String.IsNullOrEmpty(path))
            {
                if (File.Exists(path))
                {
                    this.Image = Image.FromFile(path);
                }
            }
        }

        public override void Print(Graphics g)
        {
            g.DrawImage(this.Image, this.X, this.Y);
        }
    }
}
