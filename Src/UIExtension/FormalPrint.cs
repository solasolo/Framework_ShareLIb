using BarcodeLib;
using GLEO.Base;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Xml;

namespace GLEO.Utility
{
    public interface IPrintProvider
    {
        void DrawText(string Text, Font Font, float X, float Y);
        void DrawImage(Image Image, float X, float Y);
        void DrawLine(float FromX, float FromY, float ToX, float ToY, float Width);
        void DrawBar(string Text, string Type, float X, float Y, float Width, float Height);
        void DrawBarFont(string Text, Font Font, float X, float Y);

        float GetTextHeight(Font Font);
    }

    interface IPrintContentProvider
    {
        string GetText(string field);
    }

    class ObjectPrintContent : IPrintContentProvider
    {
        private object Content;

        public ObjectPrintContent(object obj)
        { 
            this.Content = obj;
        }

        public string GetText(string field)
        {
            object value = ReflectHelper.GetPropertyValue(this.Content, field);

            if (value == null) value = String.Empty;

            return value.ToString();
        }
    }

    class DicrionaryPrintContent : IPrintContentProvider
    {
        private Dictionary<string, string> Content;

        public DicrionaryPrintContent(Dictionary<string, string> dict)
        {
            this.Content = dict;
        }

        public string GetText(string field)
        {
            string Result = null;

            if (this.Content.ContainsKey(field))
            {
                Result = this.Content[field];
            }

            if (Result == null) Result = String.Empty;


            return Result;
        }
    }

    public abstract class BaseFormalPrint
    {
        protected int CopyCount;

        protected float Width;
        protected float Height;
        protected float _OffsetX;
        protected float _OffsetY;

        IPrintContentProvider Provider;
        protected List<BaseFormConfigItem> Items;

        public float OffsetX
        {
            get
            {
                return this._OffsetX;
            }
        }

        public float OffsetY
        {
            get
            {
                return this._OffsetY;
            }
        }

        public BaseFormalPrint(string conf_file)
        {
            this.Provider = null;
            this.Items = null;

            this.CopyCount = 1;
            this.Width = 0;
            this.Height = 0;
            this._OffsetX = 0;
            this._OffsetY = 0;

            this.Load(conf_file);
        }

        public void Load(string conf_file)
        {
            XmlDocument Doc = new XmlDocument();
            Doc.Load(conf_file);

            XmlNode root = Doc.DocumentElement;

            this.Load(root);
        }

        protected virtual void Load(XmlNode root)
        {
            XMLHelper.GetAttribute(root, "Width", ref this.Width);
            XMLHelper.GetAttribute(root, "Height", ref this.Height);

            XMLHelper.GetAttribute(root, "Count", ref this.CopyCount);
            XMLHelper.GetAttribute(root, "OffsetX", ref this._OffsetX);
            XMLHelper.GetAttribute(root, "OffsetY", ref this._OffsetY);

            this.Items = new List<BaseFormConfigItem>();
            XmlNodeList nodes = root.ChildNodes;
            foreach (XmlNode n in nodes)
            {
                BaseFormConfigItem item = null;

                if (n.Name == "Item")
                {
                    string field = null;
                    XMLHelper.GetAttribute(n, "Field", ref field);

                    if (String.IsNullOrEmpty(field))
                    {
                        item = new TextConfigItem(this, n);
                    }
                    else
                    {
                        item = new FieldConfigItem(this, n);
                    }
                }
                else if (n.Name == "Image")
                {
                    item = new ImageConfigItem(this, n);
                }
                else if (n.Name == "Barfont")
                {
                    item = new FontBarcodeConfigItem(this, n);
                }
                else if (n.Name == "Barcode")
                {
                    item = new BarcodeConfigItem(this, n);
                }
                else if (n.Name == "Line")
                {
                    item = new LineConfigItem(this, n);
                }
                if (item != null)
                {
                    this.Items.Add(item);
                }
            }
        }

        protected abstract void Print();

        public string ReadField(string field)
        {
            return this.Provider.GetText(field);
        }

        public void Print(Object obj, int count)
        {
            this.SetCopies(count);
            this.Provider = new ObjectPrintContent(obj);

            this.Print();
        }

        public void Print(Dictionary<string, string> content, int count)
        {
            this.SetCopies(count);
            this.Provider = new DicrionaryPrintContent(content);

            this.Print();
        }

        public void Print(Object obj)
        {
            this.Print(obj, 0);
        }

        public void Print(Dictionary<string, string> content)
        {
            this.Print(content, 0);
        }

        private void SetCopies(int count)
        {
            if (count > 0)
            {
                this.CopyCount = count;
            }
        }
    }

    class GraphicsPrinter : IPrintProvider
    {
        private Graphics Graphics;

        Brush PrintBrush;

        public GraphicsPrinter(Graphics g)
        {
            this.Graphics = g;
            this.Graphics.PageUnit = GraphicsUnit.Millimeter;

            this.PrintBrush = new SolidBrush(Color.Black);
        }

        public void DrawText(string Text, Font Font, float X, float Y)
        {
            this.Graphics.DrawString(Text, Font, PrintBrush, X, Y);
        }

        public void DrawImage(Image Image, float X, float Y)
        {
            this.Graphics.DrawImage(Image, X, Y);
        }

        public void DrawLine(float FromX, float FromY, float ToX, float ToY, float Width)
        {
            Pen PrintPen = new Pen(Color.Black, Width);
            this.Graphics.DrawLine(PrintPen, FromX, FromY, ToX, ToY);
        }

        public void DrawBar(string Text, string Type, float X, float Y, float Width, float Height)
        {
            TYPE BarType = TYPE.CODE128;
            switch (Type)
            {
                case "Code128":
                    BarType = TYPE.CODE128;
                    break;

                case "Code39":
                    BarType = TYPE.CODE39;
                    break;
            }

            Image img = Barcode.DoEncode(BarType, Text, false, (int)Width, (int)Height);
            this.Graphics.DrawImage(img, X, Y);
        }

        public void DrawBarFont(string Text, Font Font, float X, float Y)
        {
            this.Graphics.DrawString(Text, Font, PrintBrush, X, Y);
        }

        public float GetTextHeight(Font Font)
        {
            return Font.GetHeight();
        }

    }

    public class FormalPrint : BaseFormalPrint
    {
        PrintDocument Printer;
        string PrinterName;

        public FormalPrint(string conf_file)
            : base(conf_file)
        {
            this.Printer.PrintPage += new PrintPageEventHandler(this.DoPrintPage);

        }

        protected override void Load(XmlNode root)
        {
            this.PrinterName = String.Empty;
            this.Printer = new PrintDocument();

            base.Load(root);

            XMLHelper.GetAttribute(root, "Printer", ref this.PrinterName);
            if (this.PrinterName != String.Empty)
            {
                this.Printer.DefaultPageSettings.PrinterSettings.PrinterName = this.PrinterName;
            }
        }

        protected override void Print()
        {
            this.Printer.DefaultPageSettings.PrinterSettings.Copies = (short)this.CopyCount;

            if (this.Width != 0 && this.Height != 0)
            {
                this.Printer.DefaultPageSettings.PaperSize = new PaperSize("Custom", (int)((float)this.Width / 0.254), (int)((float)this.Height / 0.254));
            }

            this.Printer.Print();
        }

        protected void DoPrintPage(object sender, PrintPageEventArgs e)
        {
            Graphics g = e.Graphics;
            GraphicsPrinter printer = new GraphicsPrinter(g);

            foreach (BaseFormConfigItem item in this.Items)
            {
                item.Print(printer);
            }
        }
    }
}
