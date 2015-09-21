using GLEO.DBUtility;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;

namespace GLEO.MES.Sys
{
    public class OptionControl
    {
        private string _opationinterface;
        private BaseDbSupport _Db;
        private string pramaryPerfix;
        private Dictionary<string, Dictionary<int, int>> _Dictionary;
        private List<int> _RolesList;

        public void SetDb(BaseDbSupport db)
        {
            this._Db = db;
            setpramaryPerfix();
        }

        private void setpramaryPerfix()
        {
            if (this._Db is MsSqlDbSupport)
                pramaryPerfix = "@";
            if (this._Db is OracleDbSupport)
                pramaryPerfix = ":";
            if (this._Db is OleDbSupport)
                pramaryPerfix = "?";
            if (this._Db is FirebirdDbSupport)
                pramaryPerfix = "@";
        }

        public Dictionary<string, Dictionary<int, int>> LoadDictionary(string opationinterface)
        {
            Dictionary<string, Dictionary<int, int>> temps = new Dictionary<string, Dictionary<int, int>>();
            DataTable dt = doQuery(opationinterface);
            if (dt.Rows.Count > 0)
            {
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    string key = dt.Rows[i]["optioninterface"].ToString();
                    int roleid = int.Parse(dt.Rows[i]["roleid"].ToString());
                    int rwable = int.Parse(dt.Rows[i]["rwable"].ToString());

                    if (temps.ContainsKey(key))
                    {
                        temps[key].Add(roleid, rwable);
                    }
                    else
                    {
                        Dictionary<int, int> temp = new Dictionary<int, int>();
                        temp.Add(roleid, rwable);
                        temps.Add(key, temp);
                    }

                    //temp = new Dictionary<int, int>();
                    ////Dictionary<int, int> adds = new Dictionary<int, int>();
                    //int key = int.Parse(dt.Rows[i]["rwable"].ToString());
                    //int values = int.Parse(dt.Rows[i]["roleid"].ToString());
                    //temp.Add(key, values);

                    //temps = new Dictionary<string, Dictionary<int, int>>();
                    //string keys = dt.Rows[i]["optioninterface"].ToString();
                    //temps.Add(keys, temp);
                }
            }

            return temps;
        }

        public List<int> LoadRoles()
        {
            List<int> Result = new List<int>();

            string sql = "select id from role  where id <> 0 order by id asc";

            ProxyDataReader dr = this._Db.ExecuteReader(sql);
            using (dr)
            {
                while (dr.Read())
                {
                    int role = dr.GetInt32("id", 0);
                    Result.Add(role);
                }
            }

            return Result;
        }

        private DataTable doQuery(string opationinterface)
        {
            DataTable dt = null;
            if (_Db != null)
            {
                string Sql = "select * from " + opationinterface;
                dt = _Db.RetrieveDataTable(Sql);
                _opationinterface = opationinterface;
            }
            return dt;
        }


        /////////////////////////////////////
        private static OptionControl _Instance;

        public static OptionControl Instance
        {
            get
            {
                if (_Instance == null)
                {
                    _Instance = new OptionControl();
                }

                return _Instance;
            }
        }

        private OptionControl()
        {

        }

        public void Init()
        {
            _RolesList = this.LoadRoles();
            _Dictionary = this.LoadDictionary("options");
        }

        public int ReadDictionary(string ButtonText, int Id)
        {
            int Permission = -1;

            if (_Dictionary != null)
            {
                if (!string.IsNullOrEmpty(ButtonText))
                {
                    if (!_Dictionary.ContainsKey(ButtonText))
                    {
                        //_Dictionary.Add(ButtonText, new string[4]);
                        _Instance.Sava(ButtonText);
                    }
                    else
                    {
                        foreach (KeyValuePair<string, Dictionary<int, int>> kvp in _Dictionary)
                        {
                            if (kvp.Key == ButtonText)
                            {
                                foreach (KeyValuePair<int, int> kvps in kvp.Value)
                                {
                                    if (kvps.Key == Id)
                                    {
                                        Permission = kvps.Value;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            return Permission;
        }

        private int Sava(string ButtonText)
        {
            int Result = 0;
            if (_Db != null && !string.IsNullOrEmpty(ButtonText))
            {
                string check = "select optioninterface from options where optioninterface = " + this.pramaryPerfix + "key";
                _Db.SetParameter("key", ButtonText);

                ProxyDataReader reader = _Db.ExecuteReader(check);
                if (reader != null)
                {
                    if (!reader.Read()) //没有数据
                    {
                        foreach (int role in this._RolesList)
                        {
                            if (role != -1)
                            {
                                string Sql = "insert into options (optioninterface,RWable,Roleid) values (" + this.pramaryPerfix + "key,1," + role + ")";
                                
                                Result &= _Db.ExecuteNonQuery(Sql);
                            }
                        }
                    }
                }
            }

            return Result;
        }

        public void Clear()
        {
            _RolesList.Clear();
            _Dictionary.Clear();
        }
    }
}
