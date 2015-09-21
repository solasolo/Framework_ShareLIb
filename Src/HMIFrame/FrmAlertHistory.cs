using System;
using System.Collections.Generic;
using System.Data;
using GLEO.DBUtility;
using System.Windows.Forms;
using GLEO.MES.Sys;
using System.Drawing;

namespace PictureLib
{
    public partial class FrmAlertHistory : BaseControl
    {
        AlarmTranslator AlarmTrans;

        Dictionary<AlarmType, string> alarmTyps;
        AlarmType[] types;
        string[] items;

        public FrmAlertHistory()
        {
            InitializeComponent();

            this.AlarmTrans = null;
            this.dataGridViewFx1.AutoGenerateColumns = false;

            this.types = new AlarmType[] { AlarmType.Unknown, AlarmType.Message, AlarmType.Warning, AlarmType.Error };
            this.items = new string[] { "所有", "信息", "警告", "故障" };

            this.cbType.Items.AddRange(items);
        }

        public void LoadAlarms()
        {
            AlarmQueryRequest request = new AlarmQueryRequest();

            if (this.cbType.SelectedIndex < 0)
            {
                request.Type = AlarmType.Unknown;
            }
            else
            {
                request.Type = this.types[this.cbType.SelectedIndex];
            }

            request.StartTime = this.dateTimePicker1.Value.Date;
            //request.EndTime = this.dateTimePicker2.Value.Date;
            request.EndTime = request.StartTime.AddDays(1);

            string code = txtCode.Text.Trim().ToUpper();
            request.Code = String.IsNullOrEmpty(code) ? null : code;

            List<AlarmBean> alarms = (this.Db as IDBAlarmTranslator).ReadAlarmList(request);

            if (this.AlarmTrans == null)
            {
                this.AlarmTrans = new AlarmTranslator(this.Db as IDBAlarmTranslator);
            }

            foreach (AlarmBean al in alarms)
            {
                AlarmType type = AlarmType.Unknown;
                al.Message = AlarmTrans.ReadAlarmString(al.Code, al.Info, ref type);
            }

            this.dataGridViewFx1.DataSource = alarms;
        }

        private void FrmEditFault_Load(object sender, EventArgs e)
        {
            this.AlarmTrans = new AlarmTranslator(this.Db as IDBAlarmTranslator);
            this.dateTimePicker1.Value = DateTime.Now;

            //this.LoadAlarms();
        }

        private void cbType_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.LoadAlarms();
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            this.LoadAlarms();
        }

        //根据代码查询指定月的数据
        private void btnSearch_Click(object sender, EventArgs e)
        {
            this.LoadAlarms();
        }
 
        private void txtCode_KeyUp(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            if (e.KeyValue == 13 && txtCode.Text.Trim() != "")
            {
                this.LoadAlarms();
            }
        }
    }
}
