using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GLEO.MES.Sys;
using System.Drawing;

namespace GLEO.MES.UI
{
    /// <summary>
    /// Author Ls
    /// Date   UnKnown
    /// Version 1.0
    /// 
    /// EditBy Gk
    /// Date   2013.10.23
    /// Support I18N
    /// 滚动条
    /// </summary>
    public class DataGridViewFx : DataGridView
    {
        public ScrollBars ScrollBars { get; set; }

        public DataGridViewFx()
        {
            this.AllowUserToAddRows = false;
            this.AllowUserToResizeRows = false;
            this.AutoGenerateColumns = false;
            this.MultiSelect = false;
            this.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        }

        // Bug Fix
        protected override void OnRowEnter(DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0 && e.ColumnIndex >= 0)
            {
                base.OnRowEnter(e);
            }
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            for (int i = 0; i < this.ColumnCount; i++)
            {
                if (this.Columns[i].Visible)
                {
                    if (this.Columns[i] is DataGridViewCloumnFx)
                    {
                        //if (!string.IsNullOrEmpty(TransText(this.Columns[i].Name)))
                        //{
                        //    this.Columns[i].HeaderText = TransText(this.Columns[i].Name);
                        //}
                        //else
                        //{
                        //}
                    }
                }
            }

            base.OnPaint(e);
        }

        protected override void OnRowPostPaint(DataGridViewRowPostPaintEventArgs e)
        {
            if (this.RowHeadersVisible)
            {
                string RowNnString = (e.RowIndex + 1).ToString();

                Rectangle rectangle = new Rectangle(e.RowBounds.Location.X, e.RowBounds.Location.Y, this.RowHeadersWidth, e.RowBounds.Height);

                TextRenderer.DrawText(e.Graphics, RowNnString, this.RowHeadersDefaultCellStyle.Font, rectangle, this.RowHeadersDefaultCellStyle.ForeColor, TextFormatFlags.VerticalCenter | TextFormatFlags.Right);
            }

            //this.Rows[e.RowIndex].Cells[0].Value = (e.RowIndex + 1).ToString();
        }
        // public override 

        protected string TransText(string text)
        {
            return TranslateLanguage.Instance.doTranslate(text);
        }
    }
}
