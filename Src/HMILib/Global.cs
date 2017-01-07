using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GLEO.MES.Sys
{
    public static class Global
    {
        private static Dictionary<string, object> Data = new Dictionary<string, object>();

        public static string AppTitle;
        public static string AppName;

        public const string SuperUser = "admin";
        
        public static UserBean LoginUser { get; set; }
        public static string WorkGroup { get; set; }
    
        public static string BasePath = Application.StartupPath;
        public static string RptPath = BasePath + "\\..\\Reports\\";

        public static object Get(string name)
        {
            object Result = null;

            if (Data.ContainsKey(name))
            {
                Result = Data[name];
            }

            return Result;
        }

        public static void Set(string name, object value)
        {
            Data[name] = value;
        }
    }
}
