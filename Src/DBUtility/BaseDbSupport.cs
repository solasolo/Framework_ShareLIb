using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Transactions;
using System;
using System.Runtime.Serialization;

namespace GLEO.DBUtility
{
    public abstract class BaseDbSupport : IDBInterface
    {
        private bool _InTrans;
        //
        protected DbConnection ConnectionIntf;
        protected DbCommand CommandIntf;
        protected DbTransaction TransactionIntf;

        protected DbDataAdapter AdaperIntf;

        protected string _SqlString;

        protected abstract DbProviderFactory GetFactory();
        protected abstract string GetConnectionString();

        public BaseDbSupport()
        {
            CreateAll();
        }

        internal IDbCommand Command
        {
            get
            {
                return this.CommandIntf;
            }
        }

        protected virtual void CreateAll()
        {
            DbProviderFactory factory = this.GetFactory();

            this.ConnectionIntf = factory.CreateConnection();

            this.CommandIntf = factory.CreateCommand();
            this.CommandIntf.Connection = this.ConnectionIntf;

            this.AdaperIntf = factory.CreateDataAdapter();
            this.AdaperIntf.SelectCommand = this.CommandIntf;
        }

        protected virtual void DoClose()
        {
            if ((ConnectionIntf.State == ConnectionState.Open))
            {
                ConnectionIntf.Close();
            }
        }

        protected virtual void DoOpen()
        {
            this.DoClose();

            if (ConnectionIntf.State != ConnectionState.Open)
            {
                if (string.IsNullOrEmpty(ConnectionIntf.ConnectionString))
                {
                    ConnectionIntf.ConnectionString = GetConnectionString();
                }

                ConnectionIntf.Open();
            }
        }

        protected bool InTrans
        {
            get
            {
                return (this._InTrans || (Transaction.Current != null));
                //return (this._InTrans);
            }
        }

        public string SqlString
        {
            //set { _SqlString = value; }
            get { return CommandIntf.CommandText; }
        }

        public void Open()
        {
            this.DoOpen();
        }

        public void Close()
        {
            if (!this.InTrans)
            {
                this.DoClose();
            }
        }

        #region IDBInterface Members

        public int ExecuteNonQuery(string strSQL)
        {
            return ExecuteNonQuery(strSQL, null);
        }

        public int ExecuteNonQuery(string strSQL, DbParameter[] parameters)
        {
            int result = 0;
            CommandIntf.CommandText = strSQL;
            if (parameters != null)
            {
                CommandIntf.Parameters.AddRange(parameters);
            }

            Open();
            try
            {
                try
                {

                    result = CommandIntf.ExecuteNonQuery();
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }

            return result;
        }

        public ProxyDataReader ExecuteReader(string strSQL)
        {
            return ExecuteReader(strSQL, null);
        }

        public ProxyDataReader ExecuteReader(string strSQL, params DbParameter[] parameters)
        {
            ProxyDataReader Result = null;

            CommandIntf.CommandText = strSQL;
            if (parameters != null)
            {
                CommandIntf.Parameters.AddRange(parameters);
            }

            Open();
            try
            {
                Result = new ProxyDataReader(this);
            }
            catch (Exception ex)
            {
                throw new SQLError(CommandIntf, ex);
            }

            return Result;
        }

        public object ExecuteScaler(string strSQL)
        {
            return ExecuteScaler(strSQL, null);
        }

        public object ExecuteScaler(string strSQL, DbParameter[] parameters)
        {
            object Result = null;
            CommandIntf.CommandText = strSQL;

            if (parameters != null)
            {
                CommandIntf.Parameters.AddRange(parameters);
            }

            Open();
            try
            {
                try
                {
                    Result = CommandIntf.ExecuteScalar();
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }

            return Result;
        }

        public bool IfExist(string strSQL)
        {
            bool Result = false;
            IDataReader dr;

            CommandIntf.CommandText = strSQL;
            Open();
            try
            {
                try
                {
                    dr = CommandIntf.ExecuteReader();

                    using (dr)
                    {
                        if (dr.Read()) Result = true;
                    }
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }

            return Result;
        }

        public DataTable RetrieveDataTable(string strSQL)
        {
            return RetrieveDataTable(strSQL, null);
        }

        public DataTable RetrieveDataTable(string strSQL, DbParameter[] parameters)
        {
            DataTable dt = new DataTable();

            CommandIntf.CommandText = strSQL;
            if (parameters != null)
            {
                CommandIntf.Parameters.AddRange(parameters);
            }

            Open();
            try
            {
                try
                {
                    AdaperIntf.Fill(dt);
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }

            return dt;
        }

        public DataSet RetrieveDataSet(string strSql)
        {
            return RetrieveDataSet(strSql, null);
        }

        public DataSet RetrieveDataSet(string strSql, DbParameter[] parameters)
        {
            DataSet ds = new DataSet();

            CommandIntf.CommandText = strSql;
            if (parameters != null)
            {
                CommandIntf.Parameters.AddRange(parameters);
            }

            Open();
            try
            {
                try
                {
                    AdaperIntf.Fill(ds);
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }

            return ds;
        }

        public void Update(string strSql, DataSet ds)
        {
            Open();
            try
            {
                try
                {
                    DbProviderFactory factroy = GetFactory();
                    CommandIntf.CommandText = strSql;
                    DbCommandBuilder builder = factroy.CreateCommandBuilder();
                    builder.DataAdapter = AdaperIntf;
                    AdaperIntf.Update(ds);
                }
                catch (Exception ex)
                {
                    throw new SQLError(CommandIntf, ex);
                }
            }
            finally
            {
                Close();
            }           
        }

        public virtual void ClearCmdPara()
        {
            CommandIntf.Parameters.Clear();
        }

        public DbParameter CreateParameter(string parameterName, object value)
        {
            DbParameter param = CommandIntf.CreateParameter();
            param.ParameterName = parameterName;
            param.Value = value;

            return param;
        }

        public DbParameter[] CreateParameters(IDictionary<string, object> nameVlues)
        {
            foreach (KeyValuePair<string, object> pair in nameVlues)
            {
                Type ValueType = pair.Value.GetType();

                if (ValueType == typeof(Int32))
                {

                }

                this.CreateParameter(pair.Key, pair.Value);
            }

            return null;
        }

        public abstract void SetParameter(string parameterName, object value, CommonDBType dbType);

        public void SetParameter(string name, object value)
        {
            CommonDBType DbType = CommonDBType.String;

            if (value != null)
            {
                Type ValueType = value.GetType();

                if (ValueType == typeof(Int32))
                {
                    DbType = CommonDBType.Integer;
                }
                else if (ValueType == typeof(Int64))
                {
                    DbType = CommonDBType.LongInt;
                }
                else if (ValueType == typeof(String))
                {
                    DbType = CommonDBType.String;
                }
                else if (ValueType == typeof(DateTime))
                {
                    DbType = CommonDBType.DataTime;
                }
                else if (ValueType == typeof(Guid))
                {
                    DbType = CommonDBType.Guid;
                }
                else if (ValueType == typeof(Decimal))
                {
                    DbType = CommonDBType.Money;
                }
                else if (ValueType == typeof(Boolean))
                {
                    DbType = CommonDBType.Boolean;
                }
                else if (ValueType == typeof(Double) || ValueType == typeof(Single))
                {
                    DbType = CommonDBType.Float;
                }
            }

            if (DbType == CommonDBType.String)
            {
                if (value != null)
                {
                    this.SetParameter(name, value.ToString(), CommonDBType.String);
                }
                else
                {
                    this.SetParameter(name, null, CommonDBType.String);
                }
            }
            else
            {
                this.SetParameter(name, value, DbType);
            }

        }

        public void SetParameter(IDictionary<string, object> nameVlues)
        {
            foreach (KeyValuePair<string, object> pair in nameVlues)
            {
                this.SetParameter(pair.Key, pair.Value);
            }
        }

        public virtual void BeginTransaction()
        {
            if (!InTrans)
            {
                Open();
                TransactionIntf = ConnectionIntf.BeginTransaction();
                CommandIntf.Transaction = TransactionIntf;
                this._InTrans = true;
            }
            else
            {
                this.DoOpen();
            }
        }

        public virtual void CommitTransaction()
        {
            if (Transaction.Current != null)
            {
                this.DoClose();
            }
            else if (this._InTrans)
            {
                try
                {
                    TransactionIntf.Commit();
                }
                finally
                {
                    CommandIntf.Transaction = null;
                    this._InTrans = false;

                    Close();
                }
            }
        }

        public virtual void RollbackTransaction()
        {
            if (Transaction.Current != null)
            {
                this.DoClose();
            }
            else if (this._InTrans)
            {
                try
                {
                    TransactionIntf.Rollback();
                }
                finally
                {
                    CommandIntf.Transaction = null;
                    this._InTrans = false;

                    Close();
                }
            }
        }

        public virtual ISQLBuilder GetSQLBuilder() 
        {
            return new BaseSQLBuilder();
        }

        #endregion

    }

    public class SQLItem
    {
        public readonly string Name;
        public readonly CommonDBType Type;
        public readonly object Value;
        public readonly object OldValue;

        public SQLItem(string name, object value, CommonDBType type)
        {
            this.Name = name;
            this.OldValue = null;
            this.Value = value;
            this.Type = type;
        }

        public SQLItem(string name, object value, object old_value, CommonDBType type)
            : this(name, value, type)
        {
            this.OldValue = old_value;
        }
    }

    public struct SQLPrepare
    {
        public string SQL;
        public List<SQLItem> Parameters;
    }

    public interface ISQLBuilder
    {
        string PrepareExist(string table, List<SQLItem> conds, IDBInterface db);

        string PrepareDelete(string table, List<SQLItem> conds, IDBInterface db);

        string PrepareSelect(string table, List<SQLItem> fields, IDBInterface db);

        string PrepareUpdate(string table, List<SQLItem> fields, List<SQLItem> conds, IDBInterface db);

        string PrepareInsert(string table, List<SQLItem> fields, IDBInterface db);
    }

    public class BaseSQLBuilder : ISQLBuilder
    {
        public string PrepareExist(string table, List<SQLItem> conds, IDBInterface db)
        {
            string SQL;

            SQL = "select null from " + table;
            db.ClearCmdPara();

            SQL += MakeCondiction(conds, db);

            return SQL;
        }

        public string PrepareDelete(string table, List<SQLItem> conds, IDBInterface db)
        {
            string SQL;

            SQL = "delete from " + table;
            db.ClearCmdPara();

            SQL += MakeCondiction(conds, db);

            return SQL;
        }

        public string PrepareSelect(string table, List<SQLItem> fields, IDBInterface db)
        {
            string SQL = String.Empty;

            SQL = "select * from " + table;
            db.ClearCmdPara();

            SQL += MakeCondiction(fields, db);

            return SQL;
        }

        public string PrepareUpdate(string table, List<SQLItem> fields, List<SQLItem> conds, IDBInterface db)
        {
            string SQL = String.Empty;

            if (fields.Count > 0)
            {
                SQL = "update " + table + " set ";
                db.ClearCmdPara();

                for (int i = 0; i < fields.Count; i++)
                {
                    SQLItem item = fields[i];

                    string FieldName = MakeFieldName(item.Name);
                    string ParamName = MakeParamName(item.Name);

                    if (i > 0) SQL += ",";
                    SQL += FieldName + "=" + ParamName;

                    db.SetParameter(ParamName, item.Value, item.Type);
                }
            }

            SQL += MakeCondiction(conds, db);

            return SQL;
        }

        public string PrepareInsert(string table, List<SQLItem> fields, IDBInterface db)
        {
            string SQL = String.Empty;
            string FieldsPart = string.Empty;
            string ValuePart = string.Empty;

            db.ClearCmdPara();
            if (fields.Count > 0)
            {
                SQL = "insert into " + table;

                for (int i = 0; i < fields.Count; i++)
                {
                    SQLItem item = fields[i];

                    string FieldName = MakeFieldName(item.Name);
                    string ParamName = MakeParamName(item.Name);

                    if (i > 0)
                    {
                        FieldsPart += ",";
                        ValuePart += ",";
                    }

                    FieldsPart += FieldName;
                    ValuePart += ParamName;

                    db.SetParameter(ParamName, item.Value, item.Type);
                }

                SQL += " (" + FieldsPart + ") values (" + ValuePart + ")";
            }

            return SQL;
        }

        private string MakeCondiction(List<SQLItem> conds, IDBInterface db)
        {
            string Result = String.Empty;

            for (int i = 0; i < conds.Count; i++)
            {
                SQLItem item = conds[i];

                string FieldName = MakeFieldName(item.Name);
                string ParamName = MakeParamName(item.Name);

                Result += (i > 0) ? " and " : " where ";
                Result += FieldName + "=" + ParamName;

                db.SetParameter(ParamName, item.Value, item.Type);
            }

            return Result;
        }

        protected virtual string MakeFieldName(string field)
        {
            return "[" + field + "]";
        }

        protected virtual string MakeParamName(string param) 
        {
            return "@" + param;
        }
    }
}