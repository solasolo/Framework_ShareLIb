using GLEO.OA.System;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Xml;

namespace GLEO.WebChatSDK
{
    public abstract class BaseCallback : Page
    {
        protected static ILogger Logger;

        protected abstract Message OnMessage(Message msg);

        protected void Run()
        {
            try
            {
                this.DoDispatch();
            }
            catch (Exception ex)
            {
                Logger.Log(MessageType.Error, ex.Message);
            }
        }

        protected void DoDispatch()
        {
            string ResponseText = String.Empty;

            string echoStr = Request.QueryString["echoStr"];

            if (this.CheckSignature())
            {
                if (this.Request.RequestType.ToUpper() == "GET")
                {
                    this.Log("CheckSignature");

                    ResponseText = echoStr;
                }
                else
                {
                    Stream sream = System.Web.HttpContext.Current.Request.InputStream;

                    byte[] buf = new byte[sream.Length];
                    sream.Read(buf, 0, (int)sream.Length);

                    string reply_text = Encoding.UTF8.GetString(buf);

                    this.Log("GetMessage:\r\n" + reply_text);

                    XmlDocument data = new XmlDocument();
                    data.LoadXml(reply_text);

                    Message message = Message.Parse(data);

                    Message replay = this.OnMessage(message);
                    if (replay != null)
                    {
                        ResponseText = replay.ToXMLString();
                    }
                }

                if (ResponseText == null) ResponseText = String.Empty;

                this.Log("Repley: \r\n" + ResponseText);

                this.Response.Write(ResponseText);
            }
            else
            {
                this.Response.End();
            }
        }

        protected bool CheckSignature()
        {
            string signature = ReadQueryString("signature");
            string timestamp = ReadQueryString("timestamp");
            string nonce = Request.QueryString["nonce"] == null ? "" : Request.QueryString["nonce"].Trim();

            string[] arrTmp = { WebChatProof.AppToken, timestamp, nonce };
            Array.Sort(arrTmp);
            string tmpStr = string.Join("", arrTmp);
            tmpStr = FormsAuthentication.HashPasswordForStoringInConfigFile(tmpStr, "SHA1");
            tmpStr = tmpStr.ToLower();

            return tmpStr == signature;
        }

        private void Log(string msg)
        {
            if (Logger != null)
            {
                Logger.Log(MessageType.Debug, msg);
            }
        }

        private string ReadQueryString(string key)
        {
            string Result = Request.QueryString[key];

            if (Result == null)
            {
                Result = String.Empty;
            }
            else
            {
                Result = Result.Trim();
            }

            return Result;
        }
    }
}
