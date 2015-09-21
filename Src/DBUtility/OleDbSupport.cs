using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.OleDb;
using System.Data.Common;

namespace GLEO.DBUtility
{
    public abstract class OleDbSupport : BaseDbSupport
    {
        protected override DbProviderFactory GetFactory()
        {
            return OleDbFactory.Instance;
        }

        public override void SetParameter(string parameterName, object value, CommonDBType dbType)
        {
            OleDbParameterCollection coll = CommandIntf.Parameters as OleDbParameterCollection;
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

                    coll[parameterName].Value = DateTimeValue;
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

        private OleDbType ConvertParam(CommonDBType t)
        {
            OleDbType s = OleDbType.VarChar;

            switch (t)
            {
                case CommonDBType.Integer:
                    s = OleDbType.Integer;
                    break;

                case CommonDBType.Float:
                    s = OleDbType.Double;
                    break;

                case CommonDBType.Double:
                    s = OleDbType.Double;
                    break;

                case CommonDBType.Single:
                    s = OleDbType.Single;
                    break;

                case CommonDBType.String:
                    s = OleDbType.VarChar;
                    break;

                case CommonDBType.DataTime:
                    s = OleDbType.DBTimeStamp;
                    break;

                case CommonDBType.Guid:
                    s = OleDbType.Guid;
                    break;

                case CommonDBType.Binary:
                    s = OleDbType.Binary;
                    break;

                case CommonDBType.Money:
                    s = OleDbType.Decimal;
                    break;

                case CommonDBType.Boolean:
                    s = OleDbType.Boolean;
                    break;
            }

            return s;
        }

        public override ISQLBuilder GetSQLBuilder()
        {
            return new OledbSQLBuilder();
        }
    }

    public class OledbSQLBuilder : BaseSQLBuilder
    {
        protected override string MakeParamName(string param)
        {
            return "?" + param;
        }
    }
}
