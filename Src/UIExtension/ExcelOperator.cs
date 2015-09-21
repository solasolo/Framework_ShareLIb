using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NPOI.HSSF.UserModel;
using NPOI.SS.UserModel;
using System.IO;
using System.Data;

namespace GLEO.QcExpress.Common
{
    public interface IExcelSheetOperator
    {
        void WriteCell(int row, int col, object value);
    }

    public class ExcelOperator
    {
        private IWorkbook excel;
        private IDictionary<string, ICellStyle> StyleMap;

        public ExcelOperator()
        { 
            this.StyleMap = new Dictionary<string, ICellStyle>();
        }

        public IWorkbook Book
        {
            get
            {
                return excel;
            }
        }

        public void New()
        {
            this.excel = new HSSFWorkbook();
            this.StyleMap = new Dictionary<string, ICellStyle>();
        }

        public SheetWriter OpenSheet(string name)
        {
            ISheet sheet = this.excel.GetSheet(name);
            
            if(sheet == null)
            {
                sheet = this.excel.CreateSheet(name);
            }

            return new SheetWriter(this, sheet);
        }

        public void Save(string name)
        {
            FileStream stream = new FileStream(name, FileMode.OpenOrCreate);

            using (stream)
            {
                this.excel.Write(stream);
                stream.Close();
            }
        }

        public ICellStyle RegistFormat(string format)
        {
            ICellStyle cellStyle = null;

            if (this.StyleMap.ContainsKey(format))
            {
                cellStyle = this.StyleMap[format];
            }
            else if (excel != null)
            {
                cellStyle = excel.CreateCellStyle();
                IDataFormat formater = excel.CreateDataFormat();
                cellStyle.DataFormat = formater.GetFormat(format);

                this.StyleMap[format] = cellStyle;
            }

            return cellStyle;
        }
    }

    public class SheetWriter : IExcelSheetOperator
    {
        ISheet TheSheet;
        ExcelOperator Operator;

        internal SheetWriter(ExcelOperator oper, ISheet sheet)
        {
            this.TheSheet = sheet;
            this.Operator = oper;
        }

        public void WriteCell(int row, int col, object value)
        {
            this.InnerWriteCell(row, col, value);
        }
        
        public ICell WriteCell(int row, int col, object value, string format)
        {
            ICell cell = this.InnerWriteCell(row, col, value);

            cell.CellStyle = this.Operator.RegistFormat(format);
            return cell;
        }

        public void WriteHeader(IList<string> head_list, int row)
        {
            for (int col = 0; col < head_list.Count; col++)
            {
                this.WriteCell(row, col, head_list[col]);
            }
        }

        public void WriteTable(DataTable table, int row)
        {
            for(int col = 0; col < table.Columns.Count; col++)
            { 
                DataColumn c = table.Columns[col];

                this.WriteCell(row, col, c.Caption);
            }

            row++;
            foreach(DataRow r in table.Rows)
            {
                for (int col = 0; col < table.Columns.Count; col++)
                {
                    object value = r[col];
                    string text = String.Empty;

                    if (value is DateTime)
                    {
                        this.WriteCell(row, col, value, "yyyy-mm-dd");
                    }
                    else if (value is Decimal)
                    {
                        this.WriteCell(row, col, value, "0.00");
                    }
                    else
                    {
                        this.WriteCell(row, col, value.ToString());
                    }
                }

                row++;
            }
        }

        private ICell InnerWriteCell(int row, int col, object value)
        {
            IRow row_obj = this.TheSheet.GetRow(row);
            if (row_obj == null)
            {
                row_obj = this.TheSheet.CreateRow(row);
            }

            ICell cell = row_obj.GetCell(col);
            if (cell == null)
            {
                cell = row_obj.CreateCell(col);
            }

            if (value is String)
            {
                cell.SetCellValue((string)value);
            }
            else if (value is Int16 || value is Int32 || value is Int64)
            {
                cell.SetCellValue(Convert.ToInt32(value));
            }
            else if (value is Decimal || value is Double || value is Single)
            {
                cell.SetCellValue(Convert.ToDouble(value));
            }
            else if (value is DateTime)
            {
                cell.SetCellValue((DateTime)value);
            }
            else if (value is Boolean)
            {
                cell.SetCellValue((bool)value);
            }

            return cell;
        }
    }
}
