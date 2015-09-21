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

    public class FormalPrint : PrintDocument
    {
        string PrinterName;
        int CopyCount;

        float Width;
        float Height;
        float _OffsetX;
        float _OffsetY;
        Brush _PrintBrush;
        IPrintContentProvider Provider;

        private List<BaseFormConfigItem> Items;

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

        public Brush PrintBrush
        {
            get
            {
                return this._PrintBrush;
            }
        }

        public FormalPrint(string conf_file)
        {
            this.Provider = null;
            this.Items = null;

            this.PrinterName = String.Empty;
            this.CopyCount = 1;
            this.Width = 0;
            this.Height = 0;
            this._OffsetX = 0;
            this._OffsetY = 0;

            this._PrintBrush = new SolidBrush(Color.Black);

            this.Load(conf_file);
        }

        public void Load(string conf_file)
        {
            XmlDocument Doc = new XmlDocument();
            Doc.Load(conf_file);
            
            XmlNode root = Doc.DocumentElement;
            XmlAttribute attr;

            XMLHelper.GetAttribute(root, "Printer", ref this.PrinterName);
            if(this.PrinterName != String.Empty)
            {
                this.DefaultPageSettings.PrinterSettings.PrinterName = this.PrinterName;
            }

            XMLHelper.GetAttribute(root, "Width", ref this.Width);
            XMLHelper.GetAttribute(root, "Height", ref this.Height);
            if (this.Width != 0 && this.Height != 0)
            {
                this.DefaultPageSettings.PaperSize = new PaperSize("Custom", (int)((float)this.Width / 0.254), (int)((float)this.Height / 0.254));
            }

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
                else if(n.Name == "Image")
                { 
                    item = new ImageConfigItem(this, n);
                }
                else if (n.Name == "Bar")
                {
                    item = new FontBarcodeConfigItem(this, n);
                }

                if(item != null)
                {
                    this.Items.Add(item);
                }
            }
        }

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
            short copies = (count > 0) ? (short)count : (short)this.CopyCount;
            this.DefaultPageSettings.PrinterSettings.Copies = copies;
        }

        protected override void OnPrintPage(PrintPageEventArgs e)
        {
            Graphics g = e.Graphics;
            g.PageUnit = GraphicsUnit.Millimeter;

            foreach (BaseFormConfigItem item in this.Items)
            {
                item.Print(g);
            }
        }
    }
}
