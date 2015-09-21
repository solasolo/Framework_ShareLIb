using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.OleDb;
using System.Data;

namespace GLEO.DBUtility
{
    public enum ExcelOLEVersion
    { 
        OLE4,
        OLE12,
    }

    public class ExcelDbSupport : OleDbSupport
    {
        private ExcelOLEVersion Version;

        private const string PROVIDER_CONNECTION_12 = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source={0};Extended Properties=\"Excel 12.0 Xml;";
        private const string PROVIDER_CONNECTION_4 = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source={0};Extended Properties=\"Excel 8.0";
 
        private string ExcelFile;

        public ExcelDbSupport(string file, ExcelOLEVersion version)
        {
            this.ExcelFile = file;
            this.Version = version;
        }

        public DataTable ReadSchema()
        {
            this.Open();

            OleDbConnection conn = this.ConnectionIntf as OleDbConnection;

            DataTable SchemaTable = conn.GetOleDbSchemaTable(OleDbSchemaGuid.Tables, null);

            return SchemaTable;
        }

        protected override string GetConnectionString()
        {
            string ProviderString = String.Empty;

            switch (Version)
            { 
                case ExcelOLEVersion.OLE12:
                    ProviderString = PROVIDER_CONNECTION_12;
                    break;

                case ExcelOLEVersion.OLE4:
                    ProviderString = PROVIDER_CONNECTION_4;
                    break;
            }

            return  String.Format(ProviderString,  this.ExcelFile) + ";HDR=YES;IMEX=1\"";
        }
    }
}
