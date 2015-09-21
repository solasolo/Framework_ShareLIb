using GLEO.DBUtility;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GLEO.MES.Sys
{
    public interface IDBAction
    {
        void Record(string action, string key);
        List<OperationAction> QueryOperation(OperationCondition cond);
    }

    public class OperationCondition
    {
        public int UserID;
        public string Operation;
        public string Key;
        public DateTime StartTime;
        public DateTime EndTime;
    }

    public class OperationAction
    {
        public OperationAction()
        {
            Time = DateTime.Now;
            UserId = Global.LoginUser.ID;
        }

        public DateTime Time { get; set; }
        public string Action { get; set; }
        public string Key { get; set; }
        public string Data { get; set; }
        public int UserId { get; set; }
        public String UserName { get; set; }
        public string User { get; set; }
        public string Crew { get; set; }

        public string ActionName
        {
            get
            {
                return TranslateLanguage.Instance.doTranslate(Action);
            }

        }
    }

    public class OperationRecorder
    {
        public static IDBInterface Db = null;

        public static void Record(string action, string key)
        {
            //string sql = "insert into operation_log (Operation_Time,Operator_Id,Action,Data) values (:Operation_Time,:Operator_Id,:Action,:Data)";
            //DBAccess dba = new DBAccess();

            //dba.SetParameter(":Operation_Time", DateTime.Now);
            //dba.SetParameter(":Action", action);
            //dba.SetParameter(":Operator_Id", Global.LoginUser.ID);
            //dba.SetParameter(":Data", msg);

            //dba.ExecuteNonQuery(sql);

            OperationAction actions = new OperationAction();
            actions.Action = action;
            actions.Key = key;
            actions.Data = String.Empty;

            ORMapper.Instance.InsertObject(actions, Db);
        }

        public static void Record(string action, string key, List<SQLItem> data)
        {
            StringBuilder sb = new StringBuilder();

            foreach (SQLItem item in data)
            {
                string NewValue = item.Value == null ? "(null)" : item.Value.ToString();
                string OldValue = item.OldValue == null ? "(null)" : item.OldValue.ToString();

                string ItemLog = String.Format("[{0}] {1} => {2};", item.Name, OldValue, NewValue);

                sb.Append(ItemLog);
            }

            OperationAction actions = new OperationAction();
            actions.Action = action;
            actions.Key = key;
            actions.Data =sb.ToString();

            ORMapper.Instance.InsertObject(actions, Db);
        }
    }
}
