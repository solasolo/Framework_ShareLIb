using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Configuration;
using System.Web;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;

namespace GLEO.WebChatSDK
{
    public class BaseRequest
    {
        protected class RequestParamters
        {
            private Dictionary<string, string> Params;

            public RequestParamters()
            {
                this.Params = new Dictionary<string, string>();
            }

            public void Add(string key, string value)
            {
                this.Params.Add(key, value);
            }

            public string MakeUrl(string path)
            {
                string Result;

                Result = BaseRequest.BASE_URL + path;
                foreach (KeyValuePair<string, string> item in this.Params)
                {
                    Result += Result.Contains('?') ? "&" : "?";
                    Result += item.Key + "=" + HttpUtility.UrlEncode(item.Value, Encoding.UTF8);
                }

                return Result;
            }
        }


        static private AccessTokenInfo AccessToken;
        private const string BASE_URL = "https://api.weixin.qq.com/cgi-bin/";
        
        static BaseRequest()
        {
            AccessToken = null;
        }

        public void SendMessage()
        { 
            

        }

        public CallResult BuildMenu(string menu)
        { 
            RequestParamters param = this.CreateRequestParams();

            string json = this.Post("menu/create", param, menu);

            return Helper.JsonDecode<CallResult>(json);
        }


        protected string Get(string path, RequestParamters param)
        {
            string url = param.MakeUrl(path);

            HttpWebRequest request = this.CreateWebRequest(url, "GET");

            return this.ReadResponse(request);
        }

        protected string Post(string path, RequestParamters param, string content)
        {
            string url = param.MakeUrl(path);

            HttpWebRequest request = this.CreateWebRequest(url, "POST");
            request.ContentType = "application/x-www-form-urlencoded";

            byte[] PostData = Encoding.UTF8.GetBytes(content);
            Stream reqStream = request.GetRequestStream();
            reqStream.Write(PostData, 0, PostData.Length);
            reqStream.Close();

            return this.ReadResponse(request);
        }

        protected string Upload(string path, RequestParamters param, IDictionary<string, FileItem> fileParams)
        {
            string url = param.MakeUrl(path);

            string boundary = "------" + Guid.NewGuid().ToString() + "------"; // 随机分隔线

            HttpWebRequest request = this.CreateWebRequest(url, "POST");
            request.ContentType = "multipart/form-data;charset=utf-8;boundary=" + boundary;

            Stream reqStream = request.GetRequestStream();
            byte[] itemBoundaryBytes = Encoding.UTF8.GetBytes("\r\n" + boundary + "\r\n");
            byte[] endBoundaryBytes = Encoding.UTF8.GetBytes("\r\n" + boundary + "\r\n");

            // 组装文本请求参数
            string textTemplate = "Content-Disposition:form-data;name=\"{0}\"\r\nContent-Type:text/plain\r\n\r\n{1}";
            foreach (KeyValuePair<string, FileItem> item in fileParams)
            {
                string textEntry = string.Format(textTemplate, item, item.Value.GetFileName());
                byte[] itemBytes = Encoding.UTF8.GetBytes(textEntry);
                reqStream.Write(itemBoundaryBytes, 0, itemBoundaryBytes.Length);
                reqStream.Write(itemBytes, 0, itemBytes.Length);
            }

            // 组装文件请求参数
            string fileTemplate = "Content-Disposition:form-data;name=\"{0}\";filename=\"{1}\"\r\nContent-Type:{2}\r\n\r\n";
            foreach(KeyValuePair<string, FileItem> item in fileParams)
            {
                string key = item.Key;
                FileItem fileItem = item.Value;
                string fileEntry = string.Format(fileTemplate, key, fileItem.GetFileName(), fileItem.GetMimeType());
                byte[] itemBytes = Encoding.UTF8.GetBytes(fileEntry);
                reqStream.Write(itemBoundaryBytes, 0, itemBoundaryBytes.Length);
                reqStream.Write(itemBytes, 0, itemBytes.Length);

                byte[] fileBytes = fileItem.GetContent();
                reqStream.Write(fileBytes, 0, fileBytes.Length);
            }

            reqStream.Write(endBoundaryBytes, 0, endBoundaryBytes.Length);
            reqStream.Close();

            return this.ReadResponse(request);
        }

        public HttpWebRequest CreateWebRequest(string url, string method)
        {
            HttpWebRequest Result = null;

            if (url.Contains("https"))
            {
                ServicePointManager.ServerCertificateValidationCallback = new RemoteCertificateValidationCallback(CheckValidationResult);
                Result = (HttpWebRequest)WebRequest.CreateDefault(new Uri(url));
            }
            else
            {
                Result = (HttpWebRequest)WebRequest.Create(url);
            }

            Result.CookieContainer = new CookieContainer();
            Result.AllowAutoRedirect = true;
            Result.ServicePoint.Expect100Continue = false;
            Result.Method = method;
            Result.KeepAlive = true;

            return Result;
        }

        public string ReadResponse(HttpWebRequest request)
        {
            string Result = String.Empty;

            System.IO.Stream stream = null;
            StreamReader reader = null;
            HttpWebResponse response = null;

            try
            {
                response = request.GetResponse() as HttpWebResponse;

                stream = response.GetResponseStream();
                reader = new StreamReader(stream, Encoding.UTF8);
                Result = reader.ReadToEnd();
            }
            finally
            {
                if (reader != null) reader.Close();
                if (stream != null) stream.Close();
                if (response != null) response.Close();
            }

            return Result;
        }

        protected bool CheckValidationResult(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors errors)
        { 
            //直接确认，否则打不开
            return true;
        }
        
        protected AccessTokenInfo GetAccessToken()
        {
            AccessTokenInfo Result = AccessToken;

            if(Result == null || Result.Expired)
            {
                RequestParamters param = new RequestParamters();
                param.Add("grant_type", "client_credential");
                param.Add("appid", WebChatProof.AppID);
                param.Add("secret", WebChatProof.AppSecret);


                string json = this.Get("token", param);
                Result = Helper.JsonDecode<AccessTokenInfo>(json);
            }

            return Result;
        }

        protected RequestParamters CreateRequestParams()
        {
            RequestParamters param = new RequestParamters();
            param.Add("access_token", this.GetAccessToken().access_token);

            return param;
        }
    }
}
