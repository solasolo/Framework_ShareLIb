using System.Drawing;
using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class ThreadLabel : Label
    {
        public delegate void SetString(string text);
        public delegate string GetString();

        public delegate void SetForeColor(Color color);
        public delegate Color GetForeColor();

        public delegate void SetBackColor(Color color);
        public delegate Color GetBackColor();

        public override string Text
        {
            get
            {
                if (InvokeRequired)
                {
                    GetString getDele = delegate()
                    {
                        return base.Text;
                    };

                    return (string)Invoke(getDele);
                }
                else
                {
                    return base.Text;
                }
            }
            set
            {
                if (InvokeRequired)
                {
                    SetString setDel = delegate(string text)
                    {
                        base.Text = text;
                    };
                    Invoke(setDel, new object[] { value });
                }
                else
                {
                    base.Text = value;
                }
            }
        }

        public override Color ForeColor
        {
            get
            {
                if (InvokeRequired)
                {
                    GetForeColor getDele = delegate()
                    {
                        return base.ForeColor;
                    };

                    return (Color)Invoke(getDele);
                }
                else
                {
                    return base.ForeColor;
                }
            }
            set
            {
                base.ForeColor = value;
            }
        }

        public override Color BackColor
        {
            get
            {
                if (InvokeRequired)
                {
                    GetForeColor getDele = delegate()
                    {
                        return base.BackColor;
                    };

                    return (Color)Invoke(getDele);
                }
                else
                {
                    return base.BackColor;
                }
            }
            set
            {
                base.BackColor = value;
            }
        }
    }
}