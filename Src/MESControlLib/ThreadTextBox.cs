using System.Windows.Forms;

namespace GLEO.MES.UI
{
    public class ThreadTextBox : TextBox
    {
        public delegate void SetString(string text);
        public delegate string GetString();

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

    }
}