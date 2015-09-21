using GLEO.WebChatSDK;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Celami
{
    public partial class WebChatTest : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void BtnMenu_Click(object sender, EventArgs e)
        {
            string Menu = this.TextInput.Text;

            BaseRequest req = new BaseRequest();
            CallResult res = req.BuildMenu(Menu);

            this.LabelCode.Text = res.errcode.ToString();
            this.LabelMessage.Text = res.errmsg;
        }
    }
}