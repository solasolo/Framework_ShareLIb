using System;
using System.Data;
using System.Data.SqlClient;
using Microsoft.Win32;
using System.Data.OleDb;
using System.Data.Common;
using FirebirdSql.Data.FirebirdClient;

using GLEO.DBUtility;
using System.Collections.Generic;

namespace GLEO.DBUtility
{
    public abstract class FirebirdDbSupport : BaseDbSupport
    {
        protected override DbProviderFactory GetFactory()
        {
            return FirebirdClientFactory.Instance;
        }

        public override void SetParameter(string parameterName, object value, CommonDBType dbType)
        {
            FbParameterCollection coll = CommandIntf.Parameters as FbParameterCollection;
            if (!coll.Contains(parameterName))
            {
                coll.Add(parameterName, ConvertParam(dbType));
            }

            if (value != null)
            {
                if (dbType == CommonDBType.DataTime)
                {

                    DateTime DateTimeValue;
                    if (value is DateTime)
                    {
                        DateTimeValue = (DateTime)value;
                    }
                    else
                    {
                        DateTimeValue = DateTime.Parse(value.ToString());
                    }

                    if ((DateTime)DateTimeValue == DateTime.MinValue)
                    {
                        coll[parameterName].Value = DBNull.Value;
                    }
                    else
                    {
                        coll[parameterName].Value = DateTimeValue;
                    }
                }
                else
                {
                    coll[parameterName].Value = value;
                }
            }
            else
            {
                coll[parameterName].Value = DBNull.Value;
            }
        }

        private FbDbType ConvertParam(CommonDBType t)
        {
            FbDbType s = FbDbType.Char;

            switch (t)
            {
                case CommonDBType.Integer:
                    s = FbDbType.Integer;
                    break;

                case CommonDBType.String:
                    s = FbDbType.Char;
                    break;

                case CommonDBType.DataTime:
                    s = FbDbType.TimeStamp;
                    break;

                case CommonDBType.Binary:
                    s = FbDbType.Binary;
                    break;

                case CommonDBType.Guid:
                    s = FbDbType.Char;
                    break;
            }

            return s;
        }


        public override ISQLBuilder GetSQLBuilder()
        {
            return new FirebirdSQLBuiler();
        }
    }

    public class FirebirdSQLBuiler : BaseSQLBuilder
    {
        protected override string MakeFieldName(string field)
        {
            return "\"" + field + "\"";
        }

        protected override string MakeParamName(string param)
        {
            return "@" + param;
        }
    }
}
