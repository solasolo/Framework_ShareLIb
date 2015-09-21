using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;

namespace GLEO.OA.System
{
    public abstract class DBLoggerWriter : LoggerWriter
    {
        protected string TableName = String.Empty;
        protected string ConnectionString = String.Empty;


        protected IDbConnection Connection;
        protected IDbCommand Command;

        public DBLoggerWriter(string conn_str, string table_name)
        {
            ConnectionString = conn_str;
            TableName = table_name;

            this.Init();
        }

        protected abstract void Init();

        public override void Log(LogInfo[] infos)
        {
            if (Connection.State == ConnectionState.Closed)
            {
                Connection.Open();
            }

            foreach (LogInfo li in infos)
            {
                (Command.Parameters["Time"] as DbParameter).Value = li.Time;
                (Command.Parameters["Type"] as DbParameter).Value = (int)li.Type;
                (Command.Parameters["MouduleName"] as DbParameter).Value = li.ModuleName;
                (Command.Parameters["Content"] as DbParameter).Value = li.Message;
                (Command.Parameters["Computer"] as DbParameter).Value = li.Computer;

                this.Command.ExecuteNonQuery();
            }

            Connection.Close();
        }
    }

    public class MSSQLDBLoggerWriter : DBLoggerWriter
    {
        public MSSQLDBLoggerWriter(string conn_str, string table_name)
            : base(conn_str, table_name)
        {
        }


        protected override void Init()
        {
            Connection = new SqlConnection(this.ConnectionString);

            Command = new SqlCommand("insert into " + TableName + " ([Time], [Type], [MouduleName], [Content], [Computer]) values (@Time, @Type, @MouduleName, @Content, @Computer)");
            Command.Parameters.Add(new SqlParameter("Time", SqlDbType.DateTime));
            Command.Parameters.Add(new SqlParameter("Type", SqlDbType.Int));
            Command.Parameters.Add(new SqlParameter("MouduleName", SqlDbType.NChar));
            Command.Parameters.Add(new SqlParameter("Content", SqlDbType.NVarChar));
            Command.Parameters.Add(new SqlParameter("Computer", SqlDbType.NChar));

            Command.Connection = Connection;
        }
    }
}
