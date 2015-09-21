using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web.Script.Serialization;

namespace GLEO.WebChatSDK
{
    public class Helper
    {
        protected static DateTime BaseTime;

        static Helper()
        {
            BaseTime = TimeZone.CurrentTimeZone.ToLocalTime(new DateTime(1970, 1, 1));
        }

        public static string GetJosnValue(string jsonStr, string key)
        {
            string result = string.Empty;

            if (!string.IsNullOrWhiteSpace(jsonStr))
            {
                key = "\"" + key.Trim('"') + "\"";
                int index = jsonStr.IndexOf(key) + key.Length + 1;
                if (index > key.Length + 1)
                {
                    //先截逗号，若是最后一个，截“｝”号，取最小值

                    int end = jsonStr.IndexOf(',', index);
                    if (end == -1)
                    {
                        end = jsonStr.IndexOf('}', index);
                    }
                    //index = json.IndexOf('"', index + key.Length + 1) + 1;
                    result = jsonStr.Substring(index, end - index);
                    //过滤引号或空格
                    result = result.Trim(new char[] { '"', ' ', '\'' });
                }
            }

            return result;
        }


        public static DateTime Long2DateTime(long value)
        {
            return BaseTime.AddSeconds(value);
        }
    
        public static long DateTime2Long(DateTime time)
        {
            return (long)(time - BaseTime).TotalSeconds;
        }

        public static string JsonEncode<T>(T obj) where T : class
        {
            JavaScriptSerializer jsonSerializer = new JavaScriptSerializer();
            string s = jsonSerializer.Serialize(obj);

            return s;
        }

        public static T JsonDecode<T>(string json)
        {
            JavaScriptSerializer jsonSerializer = new JavaScriptSerializer();
            T obj = jsonSerializer.Deserialize<T>(json);

            return obj;
        }
    }

    public class XMLBuilder
    {
        private StringBuilder Buffer;

        public XMLBuilder()
        {
            this.Buffer = new StringBuilder();
            this.Buffer.Append("<xml>\r\n");
        }

        public void AddString(string key, string value)
        {
            this.AddTag(key);
            this.Buffer.Append("<![CDATA[");
            this.Buffer.Append(value);
            this.Buffer.Append("]]>");
            this.CloseTag(key);
        }

        public void AddDateTime(string key, DateTime value)
        {
            this.AddTag(key);
            this.Buffer.Append(Helper.DateTime2Long(value));
            this.CloseTag(key);
        }


        public void AddInt(string key, int value)
        {
            this.AddTag(key);
            this.Buffer.Append(value);
            this.CloseTag(key);
        }

        public void AddTag(string key)
        {
            this.Buffer.Append("<");
            this.Buffer.Append(key);
            this.Buffer.Append(">");
        }

        public void CloseTag(string key)
        {
            this.Buffer.Append("</");
            this.Buffer.Append(key);
            this.Buffer.Append(">\r\n");
        }

        public string GetResult()
        {
            this.Buffer.Append("</xml>");

            return this.Buffer.ToString();
        }
    }
}
