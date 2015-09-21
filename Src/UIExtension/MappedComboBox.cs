using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GLEO.UI
{
        class ComboBoxItem<T>
        {
            private string _Text = string.Empty;
            private T _Value;

            public ComboBoxItem(string text, T value)
            {
                this._Text = text;
                this._Value = value;
            }

            public string Text
            {
                get
                {
                    return this._Text;
                }
            }

            public T Value
            {
                get
                {
                    return this._Value;
                }

            }

            public override string ToString()
            {
                return this._Text;
            }
        }
    
    public class StringMapComboBox : ComboBox
    {
        public StringMapComboBox()
        {
            this.DropDownStyle = ComboBoxStyle.DropDownList;
        }

        public string Value
        {
            get
            {
                string Result = null;

                if (this.SelectedItem != null)
                {
                    Result = ((ComboBoxItem<string>)this.SelectedItem).Value;
                }

                return Result;
            }

            set
            {
                int index = -1;

                if (value != null)
                {
                    for (int i = 0; i < this.Items.Count; i++)
                    {
                        ComboBoxItem<string> item = (ComboBoxItem<string>)this.Items[i];

                        if (item.Value == value)
                        {
                            index = i;
                            break;
                        }
                    }
                }

                this.SelectedIndex = index;
            }
        }

        public void SetItemList(Dictionary<string, string> list)
        {
            this.Items.Clear();

            foreach (KeyValuePair<string, string> list_item in list)
            {
                this.Items.Add(new ComboBoxItem<string>(list_item.Value, list_item.Key));
            }

            this.SelectedIndex = this.Items.Count > 0 ? 0 : -1;
        }

        public void SetItem(string text, string value)
        {
            this.Items.Add(new ComboBoxItem<string>(text, value));
        }

        public void InsertItem(int index, string text, string value)
        {
            this.Items.Insert(index, new ComboBoxItem<string>(text, value));
        }
    }

    public class IntMapComboBox : ComboBox
    {
        public IntMapComboBox()
        {
            this.DropDownStyle = ComboBoxStyle.DropDownList;
        }

        public int Value
        {
            get
            {
                int Result = 0;

                if (this.SelectedItem != null)
                {
                    Result = ((ComboBoxItem<int>)this.SelectedItem).Value;
                }

                return Result;
            }

            set
            {
                int index = -1;

                if (value != null)
                {
                    for (int i = 0; i < this.Items.Count; i++)
                    {
                        ComboBoxItem<int> item = (ComboBoxItem<int>)this.Items[i];

                        if (item.Value == value)
                        {
                            index = i;
                            break;
                        }
                    }
                }

                this.SelectedIndex = index;
            }
        }

        public void SetItemList(Dictionary<int, string> list)
        {
            this.Items.Clear();

            foreach (KeyValuePair<int, string> list_item in list)
            {
                this.Items.Add(new ComboBoxItem<int>(list_item.Value, list_item.Key));
            }

            this.SelectedIndex = this.Items.Count > 0 ? 0 : -1;
        }

        public void SetItem(string text, int value)
        {
            this.Items.Add(new ComboBoxItem<int>(text, value));
        }
        
        public void InsertItem(int index, string text, int value)
        {
            this.Items.Insert(index, new ComboBoxItem<int>(text, value));
        }
    }
}
