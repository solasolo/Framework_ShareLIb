using System;
using System.Data;
using System.IO;
using System.Windows.Forms;
using Microsoft.Reporting.WinForms;
using System.Text;
using System.ComponentModel;
using Microsoft.Reporting.WinForms;
using System.Drawing;
using fyiReporting.RdlViewer;
using System.Drawing.Printing;
using System.Collections.Generic;
using fyiReporting.RDL;

namespace GLEO.MES.UI
{
    interface ICommonReportviewer
    {
        int PageCount { get; }
        int CurrentPage { get; set; }

        void Load(string filePath);
        void SetData(string name, DataTable data);

        void Clean();
        void Generate();
        void ExportExcel(String filePath);
        void Print();
    }

    public class Report : UserControl
    {
        private string _Title;
        protected Dictionary<string, string> _ParameterList;

        private ReportType _ReportType;

        private ICommonReportviewer Viewer;

        public Report()
        {
            this._Title = String.Empty;
            this._ParameterList = new Dictionary<string, string>();

            this.ReportType = UI.ReportType.Fyi;
            this.HScroll = true;

            this.LoadReportView();
        }

        private void LoadReportView()
        {
            this.Controls.Clear();

            switch(this._ReportType)
            {
                case UI.ReportType.Fyi:
                    this.InitializeFyiReport();
                    break;

                case UI.ReportType.Microsoft:
                    this.InitializeMSReport();                    
                    break;
            }

            Control ctrl = this.Viewer as Control;

            this.Controls.Add(ctrl);
            ctrl.Dock = DockStyle.Fill;
            ctrl.Name = "ReportViewer";
        }

        private void InitializeMSReport()
        {
            MSReportViewer viewer = new MSReportViewer(this);
            this.Viewer = viewer;

            viewer.ShowBackButton = false;
            viewer.ShowContextMenu = false;
            viewer.ShowDocumentMapButton = false;
            viewer.ShowFindControls = false;
            viewer.ShowZoomControl = false;
        }

        private void InitializeFyiReport()
        {
            FyiReportViewer viewer = new FyiReportViewer(this);
            this.Viewer = viewer;

            viewer.ShowParameterPanel = false;
            viewer.ShowWaitDialog = true;
            viewer.ZoomMode = ZoomEnum.FitWidth;
            viewer.ScrollMode = ScrollModeEnum.SinglePage;
        }

        public Dictionary<string, string> ParameterList
        {
            get
            {
                return this._ParameterList;
            }
        }

        public void Load(String filePath)
        {
            this.Viewer.Load(filePath);
        }
        
        public string Title
        {
            get
            {
                return this._Title;
            }

            set
            {
                this._Title = value;
            }
        }

        public void Clean()
        { 
        
        }

        public void SetParamter(string key, string value)
        {
            if (this._ParameterList.ContainsKey(key))
            {
                this._ParameterList[key] = value;
            }
            else
            {
                this._ParameterList.Add(key, value);
            }
        }

        public void SetData(String dataSetName, DataTable data)
        {
            this.Viewer.SetData(dataSetName, data);
        }

        public void Generate()
        {
            this.Viewer.Generate();
        }

        public void ExportExcel()
        {
            string filePath = this.Title + ".xlsx";

            SaveFileDialog sfd = new SaveFileDialog();

            sfd.Filter = "Excel files(*.xlsx)|*.xlsx";
            sfd.FilterIndex = 0;
            sfd.FileName = filePath;

            if (sfd.ShowDialog(this) == DialogResult.OK)
            {
                filePath = sfd.FileName;

                this.Viewer.ExportExcel(filePath);
            }
        }

        public void Print()
        {
            this.Viewer.Print();
        }

        public int PageCount
        {
            get
            {
                return this.Viewer.PageCount;
            }
        }

        public int CurrentPage
        {
            get
            {
                return this.Viewer.CurrentPage;
            }

            set 
            {
                this.Viewer.CurrentPage = value;
            }
        }

        public ReportType ReportType
        {
            get
            {
                return this._ReportType;
            }

            set
            {
                this._ReportType = value;
 
                this.LoadReportView();
            }
        }
    }

    class MSReportViewer : ReportViewer, ICommonReportviewer
    {
        private Report Owner;

        internal MSReportViewer(Report report)
        {
            Owner = report;
        }

        public new void Load(string filePath)
        {
            this.LocalReport.ReportPath = filePath;
        }

        public void SetData(string name, DataTable data)
        {
            ReportDataSource ds = new ReportDataSource(name, data);
            this.LocalReport.DataSources.Clear();

            if (data != null)
            {
                this.LocalReport.DataSources.Add(ds);
            }
        }

        public void Clean()
        {
        }

        public void Generate()
        {

            this.RefreshReport();
        }

        public void ExportExcel(string filePath)
        {
            Microsoft.Reporting.WinForms.Warning[] warnings;
            string[] strStreamIds;
            string strMimeType;
            string strEncoding;
            string strFileNameExtension;

            byte[] bytes = this.LocalReport.Render("Excel", null, out strMimeType, out strEncoding, out strFileNameExtension, out strStreamIds, out warnings);

            FileStream stream = File.OpenWrite(filePath);
            stream.Write(bytes, 0, bytes.Length);
            stream.Close();
        }

        public new void Print()
        {
            this.PrintDialog();
        }

        public int PageCount
        {
            get
            {
                return this.GetTotalPages();
            }
        }
    }

    class FyiReportViewer : fyiReporting.RdlViewer.RdlViewer, ICommonReportviewer
    {
        private Report Owner;

        internal FyiReportViewer(Report report)
        {
            Owner = report;
        }

        public new void Load(string filePath)
        {
            this.SourceFile = new Uri(filePath);
        }

        public void SetData(string name, DataTable data)
        {
            this.Report.DataSets[name].SetData(data);
        }

        public void Clean()
        {
            foreach (UserReportParameter param in this.Report.UserReportParameters)
            {
                param.Value = null;
            }
        }

        public void Generate()
        {
            this.Title = this.Owner.Title;

            foreach (UserReportParameter param in this.Report.UserReportParameters)
            { 
                if(this.Owner.ParameterList.ContainsKey(param.Name))
                {
                    param.Value = this.Owner.ParameterList[param.Name];
                }
            }

            this.Rebuild();
        }

        public void ExportExcel(string filePath)
        {
            this.SaveAs(filePath, fyiReporting.RDL.OutputPresentationType.Excel);
        }

        public void Print()
        {
            PrintDocument Doc = new PrintDocument();

            Doc.PrinterSettings.FromPage = 1;
            Doc.PrinterSettings.ToPage = this.PageCount;
            Doc.PrinterSettings.MaximumPage = this.PageCount;
            Doc.PrinterSettings.MinimumPage = 1;

            if (this.PageWidth > this.PageHeight)
                Doc.DefaultPageSettings.Landscape = true;
            else
                Doc.DefaultPageSettings.Landscape = false;

            PrintDialog Dlg = new PrintDialog();

            Dlg.Document = Doc;
            Dlg.AllowSelection = true;
            Dlg.AllowSomePages = true;
            if (Dlg.ShowDialog() == DialogResult.OK)
            {
                if (Doc.PrinterSettings.PrintRange == PrintRange.Selection)
                {
                    Doc.PrinterSettings.FromPage = this.PageCurrent;
                }

                this.Print(Doc);
            }
        }

        public string Title
        {
            get
            {
                return "";
            }
            set
            {
                this.Report.Name = value;
            }
        }


        public int CurrentPage
        {
            get
            {
                return this.PageCurrent;
            }
            set
            {
                this.PageCurrent = value;
            }
        }
    }

    public enum ExportType
    {
        Excel, Pdf, Cvs
    }

    public enum ReportType
    {
        Microsoft,
        Fyi,
    }
}
