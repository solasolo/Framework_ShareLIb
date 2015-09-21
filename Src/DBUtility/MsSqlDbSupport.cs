using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using Microsoft.Win32;
using System.Configuration;
using System.Data.Common;

namespace GLEO.DBUtility
{
    public abstract class MsSqlDbSupport : BaseDbSupport
    {
        static DateTime MIN_DATE = DateTime.Parse("1900-01-01");
        
        protected override DbProviderFactory GetFactory()
        {
            return SqlClientFactory.Instance;
        }

        public MsSqlDbSupport()
            : base()
        {
            this.ConnectionIntf.ConnectionString = this.GetConnectionString();
        }

        public override void SetParameter(string parameterName, object value, CommonDBType dbType)
        {
            SqlParameterCollection coll = CommandIntf.Parameters as SqlParameterCollection;
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

                    if ((DateTime)DateTimeValue < MIN_DATE)
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

        private SqlDbType ConvertParam(CommonDBType t)
        {
            SqlDbType s = SqlDbType.NChar;

            switch (t)
            {
                case CommonDBType.Integer:
                    s = SqlDbType.Int;
                    break;

                case CommonDBType.String:
                    s = SqlDbType.NVarChar;
                    break;

                case CommonDBType.DataTime:
                    s = SqlDbType.DateTime;
                    break;

                case CommonDBType.Guid:
                    s = SqlDbType.UniqueIdentifier;
                    break;

                case CommonDBType.Binary:
                    s = SqlDbType.Binary;
                    break;

                case CommonDBType.Money :
                    s = SqlDbType.Money;
                    break;

                case CommonDBType.Boolean :
                    s = SqlDbType.Bit;
                    break;

                case CommonDBType.LongInt:
                    s = SqlDbType.BigInt;
                    break;

                case CommonDBType.Float:
                    s = SqlDbType.Float;
                    break;
            }

            return s;
        }

        public ISQLBuilder GetISQLBuilder()
        {
            return new MSSQLBuilder();
        }
    }

    public class MSSQLBuilder : BaseSQLBuilder
    {
        protected override string MakeParamName(string param)
        {
            return "@" + param;
        }
    }
}
