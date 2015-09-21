using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GLEO.UI
{
    public class ObjentMappedPanel : UserControl
    {
        public ObjentMappedPanel()
        {
        }

        public virtual void GetObject(object obj)
        {
            UIFunctions.UpdateData(obj, this);
        }

        public virtual void SetObject(object obj)
        {
            UIFunctions.UpdateScreen(obj, this);
        }

        public virtual void Clean()
        {
            UIFunctions.ClearForm(this);
        }

        public virtual void ReadOnly(bool val)
        {
            UIFunctions.ReadOnly(this, val);
        }

        public virtual bool Validate()
        {
            return UIFunctions.Validate(this);
        }
    }
}
