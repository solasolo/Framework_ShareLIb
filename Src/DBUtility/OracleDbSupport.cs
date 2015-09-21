using System;
using System.Collections.Generic;
using System.Data.OracleClient;
using System.Data.Common;

namespace GLEO.DBUtility
{
    public class OracleDbSupport : BaseDbSupport
    {

        protected override string GetConnectionString()
        {
            throw new NotImplementedException();
        }

        protected override DbProviderFactory GetFactory()
        {
            return OracleClientFactory.Instance;
        }

        public override void SetParameter(string parameterName, object value, CommonDBType dbType)
        {
            OracleParameterCollection coll = CommandIntf.Parameters as OracleParameterCollection;
            if (!coll.Contains(parameterName))
            {
                coll.Add(parameterName, ConvertParam(dbType));
            }

            if (value != null)
            {
                coll[parameterName].Value = value;
            }
            else
            {
                coll[parameterName].Value = DBNull.Value;
            }
        }

        private OracleType ConvertParam(CommonDBType t)
        {
            OracleType s = OracleType.NChar;
            new OracleParameter();
            switch (t)
            {
                case CommonDBType.Integer:
                    s = OracleType.Int32;
                    break;

                case CommonDBType.String:
                    s = OracleType.VarChar;
                    break;

                case CommonDBType.DataTime:
                    s = OracleType.DateTime;
                    break;

                case CommonDBType.Guid:
                    s = OracleType.VarChar;
                    break;

                case CommonDBType.Binary:
                    s = OracleType.LongRaw;
                    break;
                case CommonDBType.Money:
                    s = OracleType.Double;
                    break;
                case CommonDBType.Boolean:
                    s = OracleType.Double;
                    break;
            }

            return s;
        }

        public override ISQLBuilder GetSQLBuilder() 
        {
            return new OracleSQLBuiler();
        }
    }

    public class OracleSQLBuiler : BaseSQLBuilder
    {
        protected override string MakeFieldName(string field)
        {
            return "" + field + "";
        }

        protected override string MakeParamName(string param)
        {
            return ":" + param;
        }
    }
}
