using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;

namespace GLEO.WebChatSDK
{
    public class WebChatProof
    {
        private static string _WebChatID;
        private static string _AppToken;
        static private string _AppID;
        static private string _AppSecret;

        static WebChatProof()
        {
            _WebChatID = ConfigurationManager.AppSettings["WebChatID"];
            _AppToken = ConfigurationManager.AppSettings["AppToken"];
            _AppID = ConfigurationManager.AppSettings["AppID"];
            _AppSecret = ConfigurationManager.AppSettings["AppSecret"];
        }

        public static string WebChatID
        {
            get
            {
                return _WebChatID;
            }
        }

        public static string AppID
        {
            get
            {
                return _AppID;
            }
        }

        public static string AppToken
        {
            get
            {
                return _AppToken;
            }
        }

        public static string AppSecret
        {
            get
            {
                return _AppSecret;
            }
        }
    }
}
