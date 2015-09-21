using GLEO.DBUtility;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBTest
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int Result = 0;
                DBAcess db = new DBAcess();
                string check = "select OrigenalName from MultiyLang where OrigenalName = :key";
                //db.SetParameter("key", "UYT");
                db.SetParameter("key", "UTK", CommonDBType.String);
                ProxyDataReader reader = db.ExecuteReader(check);
                if (reader != null)
                {
                    if (!reader.Read()) //没有数据
                    {
                        string Sql = "insert into MultiyLang (OrigenalName,Chinese,English,Germany,Japanese) values (:key,'','','','')";
                        Result = db.ExecuteNonQuery(Sql);
                    }
                }
            }catch(Exception e)
            {
                string msg = e.Message;
            }
        }
    }

    public class DBAcess : MsSqlDbSupport
    {
        protected override string GetConnectionString()
        {
            return "Password=dbmaster;Persist Security Info=True;User ID=sa;Initial Catalog=WeiQiao;Data Source=AS-GLEO\\TEST";
        }
    }
}
