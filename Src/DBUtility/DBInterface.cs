using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;

namespace GLEO.DBUtility
{
    public enum CommonDBType
    {
        Integer,
        Guid,
        String,
        DataTime,
        Binary,
        Money,
        Boolean,
        LongInt,
        Float,
        Double,
        Single,
    }

    public interface IDBInterface
    { 
        int ExecuteNonQuery(string strSQL);
        int ExecuteNonQuery(string strSQL, DbParameter[] parameters);

        ProxyDataReader ExecuteReader(string strSQL);
        ProxyDataReader ExecuteReader(string strSQL, params DbParameter[] Parameters);

        object ExecuteScaler(string strSQL);
        object ExecuteScaler(string strSQL, params DbParameter[] parameters);

        DataTable RetrieveDataTable(string strSQL);
        DataTable RetrieveDataTable(string strSQL, DbParameter[] parameters);

        DataSet RetrieveDataSet(string strSql);
        DataSet RetrieveDataSet(string strSql, DbParameter[] parameters);
        void Update(string strSql, DataSet ds);

        void ClearCmdPara();

        DbParameter CreateParameter(string parameterName, object value);
        DbParameter[] CreateParameters(IDictionary<string, object> nameVlues);

        void SetParameter(string parameterName, object value, CommonDBType dbType);
        void SetParameter(string parameterName, object value);
        void SetParameter(IDictionary<string, object> nameVlues);

        void BeginTransaction();
        void CommitTransaction();
        void RollbackTransaction();

        ISQLBuilder GetSQLBuilder();

        //void AddParameter(string parameterName, object value);
        //void AddParameters(DbParameter[] parameters);
    }

}
