using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using GLEO.MES.Sys;

namespace HMI
{
    public partial class AlertGridView : DataGridView
    {
        private List<AlarmBean> _Data;
        private Brush[] BrushSet;
        private Pen DefaultCellPen;
        private Brush DefaultCellBrush;
        private Brush SelectCellBrush;

        public AlertGridView()
        {
            InitializeComponent();

            this.DefaultCellPen = new Pen(Color.Gray, 1);
            this.DefaultCellBrush = new SolidBrush(Color.Black);
            this.SelectCellBrush = new SolidBrush(Color.DarkSeaGreen);

            this.BrushSet = new Brush[5];
            this.BrushSet[(int)AlarmType.Error] = new SolidBrush(Color.Red);
            this.BrushSet[(int)AlarmType.Warning] = new SolidBrush(Color.Yellow);
            this.BrushSet[(int)AlarmType.Message] = new SolidBrush(Color.Green);
            this.BrushSet[(int)AlarmType.Unknown] = new SolidBrush(Color.Black);
        }

        public List<AlarmBean> Data
        {
            set
            {
                this._Data = value;
            }
        }

        protected override void OnCellPainting(DataGridViewCellPaintingEventArgs e)
        {
            Graphics g = e.Graphics;

            if (e.RowIndex >= 0)
            {
                DataGridViewRow row = this.Rows[e.RowIndex];
                AlarmBean alarm = (AlarmBean)row.DataBoundItem;

                if (e.State == DataGridViewElementStates.Selected)
                {
                    g.FillRectangle(this.SelectCellBrush, e.CellBounds);
                }
                else
                {
                    g.FillRectangle(this.DefaultCellBrush, e.CellBounds);
                }
                g.DrawRectangle(this.DefaultCellPen, e.CellBounds);

                if (e.Value != null)
                {
                    g.DrawString(e.Value.ToString(), this.Font, this.BrushSet[(int)alarm.Type], e.CellBounds.X + 3, e.CellBounds.Y + 3);
                }

                e.Handled = true;
            }
            else
            {
            }
        }
    }
}
