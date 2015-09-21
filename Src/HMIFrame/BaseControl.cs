using GLEO.MES.Network;
using System.Collections.Generic;
using System.Windows.Forms;
using PictureLib;
using GLEO.DBUtility;
using System;

namespace PictureLib
{
    public class BaseControl : UserControl
    {
        private IDBInterface _Db = null;
        private Form _Owner;

        protected string _Title;

        public BaseControl()
        {
            this._Db = null;
        }

        public BaseControl(Form owner)
        {
            this._Db = null;
            this._Owner = owner;
        }

        protected IDBInterface Db
        {
            get 
            {
                if (this._Db == null)
                {
                    this._Db = (this._Owner as IDbSupply).CreateDatabase();
                }

                return this._Db;
            }
        }

        protected IEditCtrl EditCtrl
        {
            get 
            {
                return this._Owner as IEditCtrl;
            }
        }

        protected IMessageSender MessageSender
        {
            get
            {
                return this._Owner as IMessageSender;
            }
        }

        public string Title
        {
            get 
            { 
                return _Title; 
            }
        }

        public void SetOwner(Form owner)
        {
            this._Owner = owner;
        }

        public virtual void ControlLoad()
        { 
        }

        protected void StandardDatePicker(DateTimePicker ctrl)
        {
            ctrl.Format = DateTimePickerFormat.Custom;
            ctrl.CustomFormat = "yyyy-MM-dd";
            ctrl.Value = DateTime.Now;
        }
    }

    public interface IDbSupply
    {
        BaseDbSupport CreateDatabase();
    }

    public interface IEditCtrl
    {
        void EditEnd();
        void EditStart();
    }

    public interface IMessageSender
    {
        void SendData(short cmd, params object[] data);
    }

    public interface INavigationCtrl
    {
    }

    public interface INavigation
    {
        void Up();
        void Right();
        void Down();
        void Left();
    }

    public interface IEdit
    {
        void Add();
        void Alter();
        void Delete();
        void Save();
    }

    public interface IReport
    {
        void Print();
        void Export();
    }

    public interface ICommunication
    {
        void HandleData(short code, MessageParser parser);
    }

    public class ToolButton
    {
        List<ToolButtonType> items = new List<ToolButtonType>();

        public enum ToolButtonType
        {
            SAVE,
            ALTER,
            DELETE,
            NEW,
            RIGHT,
            DOWN,
            UP,
            LEFT,
            EXPORT,
            IMPORT,
            PRINT,
            LOCK
        }

        public void Add(ToolButtonType item)
        {
            items.Add(item);
        }

        public List<ToolButtonType> Getitems()
        {
            return items;
        }
    }
}


