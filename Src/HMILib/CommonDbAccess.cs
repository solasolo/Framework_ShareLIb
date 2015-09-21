using GLEO.DBUtility;
using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Security.Cryptography;
using System.Text;

namespace GLEO.MES.Sys
{
    public interface IDBUserManager
    {
        UserBean Login(string code, string password);
    }

    class MESDbHelper
    {
        public static string GetMD5Hash(String input)
        {
            MD5 md5 = new MD5CryptoServiceProvider();
            byte[] res = md5.ComputeHash(Encoding.Default.GetBytes(input), 0, input.Length);

            string temp = Convert.ToBase64String(res);

            return temp;
        }

        static internal Dictionary<string, string[]> LoadDictionary(ProxyDataReader reader)
        {
            Dictionary<string, string[]> Result = null;

            Result = new Dictionary<string, string[]>();
            using (reader)
            {
                while (reader.Read())
                {
                    string key = reader["OrigenalName"].ToString();
                    string[] values = new string[reader.FieldCount - 1];
                    for (int i = 0; i < reader.FieldCount - 1; i++)
                    {
                        values[i] = reader[i + 1].ToString();
                    }

                    Result.Add(key, values);
                }
            }

            return Result;
        }

        static internal UserBean Login(ProxyDataReader reader)
        {
            UserBean Result = null;

            using (reader)
            {
                if (reader.Read())
                {
                    Result = new UserBean();

                    ORMapper.Instance.FetchFromReader(Result, reader);
                }
            }

            return Result;
        }

        static internal List<AlarmBean> ReadAlarmList(ProxyDataReader reader)
        {
            List<AlarmBean> Result = new List<AlarmBean>();
            using (reader)
            {
                while (reader.Read())
                {
                    string code = reader["ALERT_NO"].ToString();
                    string para = reader["ALERT_PARA"].ToString();
                    DateTime time = (DateTime)reader["ALERT_TIME"];
                    int type = Int32.Parse(reader["ALERT_TYPE"].ToString());

                    AlarmBean alarm = new AlarmBean();
                    alarm.Code = code;
                    alarm.Time = time;
                    alarm.Info = para;
                    alarm.Type = (AlarmType)Enum.ToObject(typeof(AlarmType), type);

                    Result.Add(alarm);
                }
            }

            return Result;
        }

        static internal Dictionary<LanguageType, Dictionary<string, AlarmDef>> LoadAlarmDefines(ProxyDataReader reader)
        {
            List<LanguageType> LangList = new List<LanguageType>();

            Dictionary<LanguageType, Dictionary<string, AlarmDef>> Result;
            Result = new Dictionary<LanguageType, Dictionary<string, AlarmDef>>();

            foreach (int mylang in Enum.GetValues(typeof(LanguageType)))
            {
                LanguageType type = (LanguageType)mylang;
                LangList.Add(type);

                Dictionary<String, AlarmDef> LangDict = new Dictionary<string, AlarmDef>();
                Result.Add(type, LangDict);
            }

            using (reader)
            {
                while (reader.Read())
                {
                    string code = reader["ALERT_NO"].ToString();

                    foreach (LanguageType lang in LangList)
                    {
                        string langName = lang.ToString(); //获取名称
                        string format = reader["FORMAT_INFO_" + langName].ToString();
                        int type = Convert.ToInt32(reader["ALERT_TYPE"]);

                        AlarmDef def = new AlarmDef();
                        def.Code = code;
                        def.Info = format;
                        def.Type = (AlarmType)Enum.ToObject(typeof(AlarmType), type);

                        Dictionary<String, AlarmDef> curLangDict = Result[lang];
                        curLangDict.Add(code, def);
                    }
                }
            }

            return Result;
        }
    }

    public abstract class MsSqlMESDbAccess : MsSqlDbSupport, IDBLanguageTranslator, IDBAlarmTranslator, IDBUserManager, IDBAction
    {
        static protected string ConnectionStringCache = null;

        protected static string MakeConnectionString(string OleString)
        {
            DbConnectionStringBuilder OleBuilder = new DbConnectionStringBuilder();
            OleBuilder.ConnectionString = OleString;

            DbConnectionStringBuilder Builder = new DbConnectionStringBuilder();
            Builder["server"] = OleBuilder["Data Source"];
            Builder["uid"] = OleBuilder["User ID"];
            Builder["pwd"] = OleBuilder["Password"];
            Builder["database"] = OleBuilder["Initial Catalog"];

           return Builder.ConnectionString;
        }

        public Dictionary<string, string[]> LoadDictionary()
        {
            ProxyDataReader reader = this.ExecuteReader("select * from MultiyLang");

            return MESDbHelper.LoadDictionary(reader);
        }

        public bool CreateLanguageKey(string key)
        {
            bool Result = false;

            if (!string.IsNullOrEmpty(key))
            {
                //查询是否存在
                string CheckSQL = "select null from MultiyLang where OrigenalName = " + "@key";

                this.SetParameter("@key", key);

                if (this.IfExist(CheckSQL))
                {
                    string Sql = "insert into MultiyLang (OrigenalName,Chinese,English,Germany,Japanese) values (@key,null,null,null,null)";
                    Result = (this.ExecuteNonQuery(Sql) == 1);
                }
            }

            return Result;
        }

        public UserBean Login(string code, string password)
        {
            string sql = "select id, role, name, crew, code from operator where (code = @name or name = @name) and password = @password";

            this.ClearCmdPara();
            this.SetParameter("@name", code);
            this.SetParameter("@password", MESDbHelper.GetMD5Hash(password));
            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.Login(reader);
        }

        public List<AlarmBean> ReadAlarmList(AlarmQueryRequest cond)
        {
            string sql = "SELECT h.ALERT_NO, d.ALERT_TYPE, h.ALERT_TIME, h.ALERT_PARA from ALERT_HISTORY h join  ALERT_INFO d on h.ALERT_NO = d.ALERT_NO where h.ALERT_TIME between @data1 and @data2";

            this.ClearCmdPara();
            this.SetParameter("@data1", cond.StartTime, CommonDBType.DataTime);
            this.SetParameter("@data2", cond.EndTime, CommonDBType.DataTime);

            if (cond.Code != null)
            {
                sql += " and h.ALERT_NO = @code";
                this.SetParameter("@code", cond.Code, CommonDBType.String);
            }
            else
            {
                if (cond.Type != AlarmType.Unknown)
                {
                    sql += " and d.ALERT_TYPE = @type";
                    this.SetParameter("@type", (int)cond.Type, CommonDBType.Integer);
                }
            }

            sql += " order by h.ALERT_TIME desc";

            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.ReadAlarmList(reader);
        }

        public Dictionary<LanguageType, Dictionary<string, AlarmDef>> LoadAlarmDefines()
        {
            string sql = "SELECT * from Alert_Info ";

            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.LoadAlarmDefines(reader);
        }

        public void Record(string action, string key)
        {
        }


        public List<OperationAction> QueryOperation(OperationCondition cond)
        {
            List<OperationAction> Result = new List<OperationAction>();

            string sqls = "select l.*, o.code, o.id, o.name, o.crew from operation_log l ,operator o where o.id = l.operator_id and l.operation_time >= @date1 and l.operation_time < @date2";

            if (!string.IsNullOrEmpty(cond.Operation))
            {
                sqls += " and l.action = @action";
                this.SetParameter("@action", cond.Operation);
            }
            if (cond.UserID > 0)
            {
                sqls += " and o.id = @id";
                this.SetParameter("@id", cond.UserID);
            }

            sqls += " order by l.operation_time desc";

            DateTime d = cond.StartTime.Date;
            this.SetParameter("@date1", d);
            this.SetParameter("@date2", d.AddDays(1));
            ProxyDataReader reader = this.ExecuteReader(sqls);

            List<OperationAction> operatorList = new List<OperationAction>();
            using (reader)
            {
                while (reader.Read())
                {
                    OperationAction operation = new OperationAction();
                    ORMapper.Instance.FetchFromReader(operation, reader);

                    Result.Add(operation);

                }
            }

            return Result;
        }
    }

    public abstract class OracleMESDbAccess : OracleDbSupport, IDBLanguageTranslator, IDBAlarmTranslator, IDBUserManager, IDBAction
    {
        static protected string ConnectionStringCache = null;

        protected static string MakeConnectionString(string OleString)
        {
            DbConnectionStringBuilder OleBuilder = new DbConnectionStringBuilder();
            OleBuilder.ConnectionString = OleString;

            DbConnectionStringBuilder Builder = new DbConnectionStringBuilder();
            Builder["Data Source"] = OleBuilder["Data Source"];
            Builder["User Id"] = OleBuilder["User ID"];
            Builder["Password"] = OleBuilder["Password"];

            return Builder.ConnectionString;
        }

        public UserBean Login(string code, string password)
        {
            string sql = "select id, role, name, crew, code from operator where (code = :name or name = :name) and password = :password";

            this.ClearCmdPara();
            this.SetParameter(":name", code);
            this.SetParameter(":password", MESDbHelper.GetMD5Hash(password));
            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.Login(reader);
        }

        public Dictionary<string, string[]> LoadDictionary()
        {
            ProxyDataReader reader = this.ExecuteReader("select * from MultiyLang");

            return MESDbHelper.LoadDictionary(reader);
        }

        public bool CreateLanguageKey(string key)
        {
            bool Result = false;

            if (!string.IsNullOrEmpty(key))
            {
                //查询是否存在
                string CheckSQL = "select null from MultiyLang where OrigenalName = " + ":key";

                this.SetParameter(":key", key);

                if(!this.IfExist(CheckSQL))
                {
                    string Sql = "insert into MultiyLang (OrigenalName,Chinese,English,Germany,Japanese) values (:key,null,null,null,null)";
                    Result = (this.ExecuteNonQuery(Sql) == 1);
                }
            }

            return Result;
        }

        public List<AlarmBean> ReadAlarmList(AlarmQueryRequest cond)
        {
            string sql = "SELECT h.ALERT_NO, d.ALERT_TYPE, h.ALERT_TIME, h.ALERT_PARA from ALERT_HISTORY h join  ALERT_INFO d on h.ALERT_NO = d.ALERT_NO where h.ALERT_TIME between :data1 and :data2";

            this.ClearCmdPara();
            this.SetParameter(":data1", cond.StartTime, CommonDBType.DataTime);
            this.SetParameter(":data2", cond.EndTime, CommonDBType.DataTime);

            if (cond.Code != null)
            {
                sql += " and h.ALERT_NO = :code";
                this.SetParameter(":code", cond.Code, CommonDBType.String);
            }
            else
            {
                if (cond.Type != AlarmType.Unknown)
                {
                    sql += " and d.ALERT_TYPE = :type";
                    this.SetParameter(":type", (int)cond.Type, CommonDBType.Integer);
                }
            }

            sql += " order by h.ALERT_TIME desc";

            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.ReadAlarmList(reader);
        }

        public Dictionary<LanguageType, Dictionary<string, AlarmDef>> LoadAlarmDefines()
        {
            string sql = "SELECT * from Alert_Info ";

            ProxyDataReader reader = this.ExecuteReader(sql);

            return MESDbHelper.LoadAlarmDefines(reader);
        }

        public void Record(string action, string key)
        {
        }

        public List<OperationAction> QueryOperation(OperationCondition cond)
        {
            List<OperationAction> Result = new List<OperationAction>();

            string sqls = "select l.*, o.code, o.id, o.name, o.crew from operation_log l ,operator o where o.id = l.operator_id and to_char(l.operation_time,'yyyy-MM-dd') = :date1";

            if (!string.IsNullOrEmpty(cond.Operation))
            {
                sqls += " and l.action = :action";
                this.SetParameter(":action", cond.Operation);
            }
            if (cond.UserID > 0)
            {
                sqls += " and o.id = :id";
                this.SetParameter(":id", cond.UserID);
            }

            sqls += " order by l.operation_time desc";

            this.SetParameter(":date1", cond.StartTime.ToString("yyyy-MM-dd"));
            ProxyDataReader reader = this.ExecuteReader(sqls);

            List<OperationAction> operatorList = new List<OperationAction>();
            using (reader)
            {
                while (reader.Read())
                {
                    OperationAction operation = new OperationAction();
                    ORMapper.Instance.FetchFromReader(operation, reader);

                    Result.Add(operation);

                }
            }

            return Result;
        }
    }
}
