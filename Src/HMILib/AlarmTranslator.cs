using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GLEO.DBUtility;

namespace GLEO.MES.Sys
{
    public enum AlarmType
    { 
        Unknown = 0,
 	    Message = 1,
	    Warning = 2,
	    Error = 3,

        // TODO 枚举翻译
        //public override string Tostring
        //{
        //    get
        //    {
        //        return TranslateLanguage.Instance.doTranslate(Action);
        //    }
        //}
    } 

    public class AlarmQueryRequest
    {
        public DateTime StartTime;
        public DateTime EndTime;
        public AlarmType Type;
        public string Code;
    }

    public class AlarmBean
    {
        public AlarmType Type { get; set; }
        public DateTime Time { get; set; }
        public String Code { get; set; }
        public String Info { get; set; }
        public String Message { get; set; }
    }

    public class AlarmDef
    {
        public AlarmType Type { get; set; }
        public String Code { get; set; }
        public String Info { get; set; }        
    }

    public interface IDBAlarmTranslator
    {
        List<AlarmBean> ReadAlarmList(AlarmQueryRequest cond);
        Dictionary<LanguageType, Dictionary<string, AlarmDef>> LoadAlarmDefines();
    }

    public class AlarmTranslator
    {
        private IDBAlarmTranslator TransDB;

        Dictionary<LanguageType, Dictionary<String, AlarmDef>> AlarmBaseData;

        public AlarmTranslator(IDBAlarmTranslator db)
        {
            this.TransDB = db;
            
            AlarmBaseData = this.TransDB.LoadAlarmDefines();
        }

        public String ReadAlarmString(string id, String param, ref AlarmType type)
        {
            String result = "";

            Dictionary<String, AlarmDef> curLangDict = AlarmBaseData[TranslateLanguage.Instance.CurrentLang];
            if (curLangDict != null)
            {
                if (curLangDict.Keys.Contains(id))
                {
                    AlarmDef def = curLangDict[id];
                    result = translateString(def.Info, param);
                    type = def.Type;
                }
            }

            return result;
        }

        private String translateString(string fmtString, string para)
        {
            string result = "";
            String[] paraAlarm = para.Split('`');
            int paraCount = paraAlarm.Length;

            for (int i = 0; i < paraCount; i++)
            {
                //result = String.Format(fmtString,paraErr[i]);
                fmtString = fmtString.Replace("{" + i + "}", paraAlarm[i]);
            }

            result = fmtString;

            return result;
        }
    }
}
