using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Reflection;
using System.Diagnostics;

using GLEO.Base;
using GLEO.QcExpress.Common;

namespace GLEO.UI
{
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false)]
    public class UIExtendAttribute : Attribute
    {
        public string ExtendClass { get; set; }
    }

    public interface IUIExtend
    {
        void SetValue(object ctrl, object obj);
        void GetValue(object ctrl, object obj);
        void SetReadOnly(object ctrl, bool value);
    }
    
    public class UIFunctions
    {
        static Dictionary<Type, IUIExtend> UIPlugins;

        static UIFunctions()
        {
            UIPlugins = new Dictionary<Type, IUIExtend>();
        }
        
        static public void Regist(Type type, IUIExtend extend)
        {
            UIPlugins[type] = extend;
        }

        static IUIExtend GetExtendByType(object obj)
        {
            IUIExtend Result = null;
            
            Type type = obj.GetType();

            if (UIPlugins.ContainsKey(type))
            {
                Result = UIPlugins[type];
            }
            else
            {
                object[] attrs = type.GetCustomAttributes(typeof(UIExtendAttribute), false);
                if (attrs.Length == 1)
                {
                    string cls = (attrs[0] as UIExtendAttribute).ExtendClass;
                    object ext = ReflectHelper.CreateObject(cls);

                    UIPlugins[type] = ext as IUIExtend;
                }
            }

            return Result;
        }

        static public void setComboBoxValue(ComboBox box, string value)
        {
            bool match = false;

            for (int i = 0; i < box.Items.Count; i++)
            {
                object SelectValue = box.Items[i];

                /* if (SelectValue is ComboBoxItem<int>)
                 {
                     match = ((SelectValue as ComboBoxItem<int>).Value.ToString() == value);
                 }
                 else if (SelectValue is ComboBoxItem<string>)
                 {
                     match = ((SelectValue as ComboBoxItem<string>).Value == value);
                 }
                 else
                 {*/
                match = (SelectValue.ToString() == value);
                //}

                if (match)
                {
                    box.SelectedIndex = i;
                    break;
                }
            }

            if (!match)
            {
                if (box.DropDownStyle == ComboBoxStyle.DropDown)
                {
                    box.Text = value;
                }
                else
                {
                    box.SelectedIndex = -1;
                }
            }
        }

        #region Object-Control Mapping

        static public void UpdateScreen(object obj, Control form)
        {
            string PropName;

            if (obj != null)
            {
                Type ObjectType = obj.GetType();

                foreach (Control ctrl in form.Controls)
                {
                    object PropValue = null;

                    IUIExtend ex = GetExtendByType(ctrl);
                    
                    if(ex != null)
                    {
                        ex.SetValue(ctrl, obj);
                    }
                    else
                    {
                        if (ctrl.Tag != null)
                        {
                            PropName = ctrl.Tag.ToString().Trim();
                            PropValue = ReflectHelper.GetObjectProp(obj, PropName);

                            if (ctrl is TextBox)
                            {
                                TextBox box = ctrl as TextBox;

                                box.Text = PropValue == null ? "" : PropValue.ToString();
                            }
                            else if (ctrl is DateTimePicker)
                            {
                                DateTimePicker dtp = ctrl as DateTimePicker;
                                dtp.Value = DateTime.Now;
                                if (PropValue != null)
                                {
                                    DateTime t = (DateTime)PropValue;

                                    if (t > DateTime.MinValue && t < DateTime.MaxValue)
                                    {
                                        dtp.Value = t;
                                    }
                                }
                            }
                            else if (ctrl is CheckBox)
                            {
                                CheckBox ckb = ctrl as CheckBox;
                                ckb.Checked = PropValue == null ? false : (bool)PropValue;
                            }

                            else if (ctrl is ComboBox)
                            {
                                ComboBox comb = ctrl as ComboBox;

                                setComboBoxValue(comb, PropValue == null ? "" : PropValue.ToString());
                            }
                        }
                    }
                }
            }
        }

        static public void UpdateData(object obj, Control form)
        {
            string PropName = String.Empty;
            object PropValue = null;

            if (obj != null)
            {
                Type ObjectType = obj.GetType();

                foreach (Control ctrl in form.Controls)
                {
                    IUIExtend ex = GetExtendByType(ctrl);

                    if (ex != null)
                    {
                        ex.GetValue(ctrl, obj);
                    }
                    else
                    {
                        if (ctrl.Tag != null)
                        {
                            if (ctrl is DateTimePicker)
                            {
                                DateTimePicker dtp = ctrl as DateTimePicker;
                                PropValue = dtp.Value;
                            }
                            else if (ctrl is CheckBox)
                            {
                                CheckBox ckb = ctrl as CheckBox;
                                PropValue = ckb.Checked;
                            }
                            else if (ctrl is ComboBox)
                            {
                                ComboBox comb = ctrl as ComboBox;
                                if (comb.SelectedIndex > -1)
                                {
                                    object SelectValue = comb.SelectedItem;

                                    /*if (SelectValue is ComboBoxItem<int>)
                                    {
                                        PropValue = (SelectValue as ComboBoxItem<int>).Value;
                                    }
                                    else if (SelectValue is ComboBoxItem<string>)
                                    {
                                        PropValue = (SelectValue as ComboBoxItem<string>).Value;
                                    }
                                    else
                                    {*/
                                    if (comb.DropDownStyle == ComboBoxStyle.DropDown)
                                    {
                                        PropValue = comb.Text;
                                    }
                                    else
                                    {
                                        PropValue = comb.SelectedItem.ToString();
                                    }
                                    //}
                                }
                                else
                                {
                                    PropValue = null;
                                }
                            }
                            else if (ctrl is TextBox || ctrl.GetType().IsSubclassOf(typeof(TextBox)))
                            {
                            }

                            PropName = ctrl.Tag.ToString().Trim();

                            ReflectHelper.SetObjectProp(obj, PropName, PropValue);

                        }
                    }
                    //}
                }
            }
        }

        static public void ReadOnly(Control form, bool value)
        {
            foreach (Control ctrl in form.Controls)
            {
                IUIExtend ex = GetExtendByType(ctrl);

                if (ex != null)
                {
                    ex.SetReadOnly(ctrl, value);
                }
                else if (ctrl is DataGridView)
                {
                    ctrl.Enabled = !value;
                }
                else if (ctrl is DataGridView)
                {
                    ctrl.Enabled = !value;
                }
                else if (ctrl is TextBox)
                {
                    ctrl.Enabled = !value;
                }
                else if (ctrl is ListBox)
                {
                    ctrl.Enabled = !value;
                }
                else if (ctrl is DateTimePicker)
                {
                    ctrl.Enabled = !value;
                }
                else if (ctrl is ComboBox)
                {
                    ctrl.Enabled = !value;
                }
            }
        }

        static public void ClearForm(Control form)
        {
            foreach (Control ctrl in form.Controls)
            {
                string PropName = String.Empty;

                if (ctrl.Tag != null)
                {
                    PropName = ctrl.Tag.ToString().Trim();
                }

                //if (!String.IsNullOrEmpty(PropName))
                {
                    if (ctrl is DateTimePicker)
                    {
                        DateTimePicker dtp = ctrl as DateTimePicker;
                        dtp.Value = DateTime.Now;
                    }
                    else if (ctrl is CheckBox)
                    {
                        CheckBox ckb = ctrl as CheckBox;
                        ckb.Checked = false;
                    }
                    else if (ctrl is ComboBox)
                    {
                        ComboBox comb = ctrl as ComboBox;

                        setComboBoxValue(comb, String.Empty);
                    }
                    else if (ctrl is TextBox)
                    {
                        TextBox box = ctrl as TextBox;

                        box.Text = String.Empty;
                    }
                }
            }
        }

        static public bool Validate(Control form)
        {
            bool Result = true;

            foreach (Control ctrl in form.Controls)
            {
                IVerifiable ver = ctrl as IVerifiable;

                if (ver != null)
                { 
                    Result = Result && ver.Verify();
                }
            }

            return Result;
        }

        #endregion

        static public void ExportGridToExcel(DataGridView view, string name)
        {
            SaveFileDialog dlg = new SaveFileDialog();
            dlg.Filter = "Excel File | *.xls";
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                string FileName = dlg.FileName;

                ExcelOperator Excel = new ExcelOperator();

                Excel.New();
                SheetWriter write = Excel.OpenSheet(name);

                UIFunctions.GridToExcel(write, view);
                Excel.Save(FileName);

                Process.Start(FileName);
            }
        }

        static public void GridToExcel(IExcelSheetOperator excel, DataGridView view)
        {
            int row = 1;
            List<int> ColIndex = new List<int>();

            int col = 1;
            foreach (DataGridViewColumn view_col in view.Columns)
            {
                if (view_col.Visible)
                {
                    string text = view_col.HeaderText;
                    ColIndex.Add(view_col.Index);

                    excel.WriteCell(row, col, text);
                    ++col;
                }
            }

            ++row;
            foreach (DataGridViewRow view_row in view.Rows)
            {
                col = 1;
                foreach (int ind in ColIndex)
                {
                    object value = view_row.Cells[ind].Value;

                    excel.WriteCell(row, col, value);
                    ++col;
                }
                ++row;
            }
        }

        static public object ReadSelectRowData(DataGridView view)
        {
            object Result = null;
            DataGridViewRow row = null;

            if (view.SelectedRows.Count > 0)
            {
                row = view.SelectedRows[0];            
            }

            if (row != null)
            {
                Result = row.DataBoundItem;
            }

            return Result;
        }

    }
}
