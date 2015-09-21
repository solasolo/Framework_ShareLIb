using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using GLEO.WebChatSDK;
using GLEO.OA.System;

public partial class WebChatCallback : BaseCallback
{
    static ILoggerManager LoggerManager;

    static WebChatCallback()
    {
        LoggerManager = new CommonLoggerManager();
        LoggerManager.AppendWriter(new UDPLoggerWriter("localhost", 1111));

        Logger = LoggerManager.RegisterLogger("WebChat");

        Logger.Log(MessageType.Debug, "Callback Started");
    }

    protected void Page_Load(object sender, EventArgs e)
    {
        this.Run();
    }

    protected override Message OnMessage(Message msg)
    {
        Message Result = null;

        switch (msg.MsgType)
        {
            case MsgType.Event:
                {
                    Result = this.ProcessEvent((EventMessages)msg, msg.FromUserName);
                }
                break;
        }


        //NewsMessageItem item = new NewsMessageItem();
        //item.Title = "Hello";
        //item.Description = "Hello @ " + DateTime.Now.ToString();
        //item.PicUrl = "http://e.hiphotos.baidu.com/news/crop%3D0%2C0%2C473%2C284%3Bw%3D638/sign=d07775142d2eb938f82220b2e852a905/738b4710b912c8fc475e8038fe039245d7882191.jpg";
        //item.Url = "http://laotie.baijia.baidu.com/article/16545";
        //replay.Items.Add(item);

        if (Result != null)
        {
            Result.ToUserName = msg.FromUserName;
            Result.FromUserName = msg.ToUserName;
        };

        return Result;
    }

    private Message ProcessEvent(EventMessages msg, string sender)
    {
        Message Result = null;

        switch (msg.EventType)
        {
            case EventType.Subscribe:
                {
                    Result = new TextMessage()
                    {
                        Content = "欢迎加入鲜乐美生活"
                    };

                }
                break;

            case EventType.Click:
                Result = this.ProcessClick((MenuEventMessage)msg, sender);
                break;
        }

        return Result;
    }

    private Message ProcessClick(MenuEventMessage msg, string sender)
    {
        Message Result = null;

        switch (msg.EventKey)
        {
            case "redirect":
                {
                    string reurl = "http://solasolo.vicp.net/celami/WebChatAuth.aspx";

                    NewsMessage m = new NewsMessage();
                    NewsMessageItem item = new NewsMessageItem()
                   {
                       Title = "在线购买",
                       Description = "精品水果任你请挑选",
                       PicUrl = "http://www.celami.com/themes/moly/images/pic_1.jpg",
                       Url = String.Format("https://open.weixin.qq.com/connect/oauth2/authorize?appid={0}&redirect_uri={1}&response_type=code&scope={2}&state={3}#wechat_redirect", WebChatProof.AppID, HttpUtility.UrlEncode(reurl), "code", "test")
                   };

                    m.Items.Add(item);
                    Result = m;
                }
                break;

            case "custom":
                {
                    NewsMessage m = new NewsMessage();
                    NewsMessageItem item = new NewsMessageItem()
                    {
                        Title = "客户服务",
                        Description = "提供最新资讯",
                        PicUrl = "http://www.celami.com/themes/moly/images/pic_1.jpg",
                        Url = String.Format("http://wds.allinhui.com/default/default?openid={0}&wxid={1}&vendorid={2}&wxpublicid={3}&type=4&MicroInfo=&product_sysno=&RedirectUrl=", sender, "Celami", "1721250001831", "gh_ae4fbe3e44d6")
                    };

                    m.Items.Add(item);
                    Result = m;
                }
                break;
        }


        return Result;
    }
}