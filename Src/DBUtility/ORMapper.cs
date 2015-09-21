using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Collections.Generic;
using System.Xml;
using System.Reflection;
using System.Diagnostics;

using GLEO.Base;

namespace GLEO.DBUtility
{
    class TableDef
    {
        private string _TableName;
        private string TypeName;
        private Type _ObjectType;
        private bool _HasAuto;
        private List<FieldDef> _KeyFields;
        private List<FieldDef> FieldList;

        public TableDef(string name, string obj_type)
        {
            this._TableName = name;
            this.TypeName = obj_type;
            this._ObjectType = null;
            this._HasAuto = false;

            this.FieldList = new List<FieldDef>();
            this._KeyFields = new List<FieldDef>();
        }

        public void Add(FieldDef field)
        {
            FieldList.Add(field);
        }

        public FieldDef GetField(string name)
        {
            FieldDef Result = null;

            foreach (FieldDef fd in FieldList)
            {
                if (fd.Name.ToUpper() == name.ToUpper())
                {
                    Result = fd;
                    break;
                }
            }

            return Result;
        }

        public string TableName
        {
            get
            {
                return this._TableName;
            }
        }

        public Type ClassType
        {
            get
            {
                if (!String.IsNullOrEmpty(this.TypeName) && this._ObjectType == null)
                {
                    this._ObjectType = ReflectHelper.CreateType(this.TypeName);
                    if (this._ObjectType == null)
                    {
                        this._ObjectType = typeof(DBNull);
                    }
                }

                return this._ObjectType;
            }
        }

        public List<FieldDef> KeyFields
        {
            get
            {
                return this._KeyFields;
            }
        }

        public List<FieldDef> Fields
        {
            get
            {
                return this.FieldList;
            }
        }

        public bool HasAuto
        {
            get
            {
                return this._HasAuto;
            }
        }

        internal void SetAuto()
        {
            this._HasAuto = true;
        }
    }

    class FieldDef
    {
        private TableDef Owner;
        private string _Name;
        private string _Property;
        private CommonDBType _Type;
        private bool _IsKey;
        private bool _IsAuto;
        private bool _IsTable;
        private bool _IsProperty;
        private object _PropertyObject;

        public FieldDef(TableDef owner, string name, string type, string prop)
        {
            this.Owner = owner;
            this._Name = name;
            this._Property = prop;
            this._PropertyObject = null;
            this._IsProperty = false;

            switch (type)
            {
                case "guid":
                    _Type = CommonDBType.Guid;
                    break;

                case "string":
                    _Type = CommonDBType.String;
                    break;

                case "int":
                    _Type = CommonDBType.Integer;
                    break;

                case "long":
                    _Type = CommonDBType.LongInt;
                    break;

                case "datetime":
                case "date":
                case "time":
                    _Type = CommonDBType.DataTime;
                    break;

                case "binary":
                    _Type = CommonDBType.Binary;
                    break;

                case "intid":
                    _Type = CommonDBType.Integer;
                    this.SetAuto();
                    break;

                case "longid":
                    _Type = CommonDBType.LongInt;
                    this.SetAuto();
                    break;

                case "float":
                    _Type = CommonDBType.LongInt;
                    break;
                
                case "money":
                    _Type = CommonDBType.Money;
                    break;

                case "bool":
                    _Type = CommonDBType.Boolean;
                    break;

                case "table":
                    _IsTable = true;
                    break;

                default:
                    throw new Exception(String.Format("不可识别的类型: {0}, 属性: {1}.{2}", type, name, prop));
            }
        }

        public string Name
        {
            get
            {
                return this._Name;
            }
        }

        public string Property
        {
            get
            {
                return this._Property;
            }
        }

        public object PropertyObject
        {
            get
            {
                object Result = null;

                Type type = this.Owner.ClassType;

                if (this._PropertyObject == null)
                {
                    PropertyInfo PublicProp = type.GetProperty(this.Property, BindingFlags.Public | BindingFlags.Instance);
                    if (PublicProp != null)
                    {
                        this._IsProperty = true;
                        Result = PublicProp;
                    }
                    else
                    {
                        FieldInfo PublicField = type.GetField(this.Property, BindingFlags.Public | BindingFlags.Instance | BindingFlags.IgnoreCase);
                        if (PublicField != null)
                        {
                            this._IsProperty = false;
                            Result = PublicField;
                        }
                    }

                    if (Result == null)
                    {
                        throw new Exception(String.Format("[{0}] No Property: {1}", this.Type.ToString(), this.Property));
                    }
                    else
                    {
                        this._PropertyObject = Result;
                    }

                }

                return this._PropertyObject;
            }
        }

        public CommonDBType Type
        {
            get
            {
                return this._Type;
            }
        }

        public bool IsKey
        {
            get
            {
                return this._IsKey;
            }
        }

        public bool IsAuto
        {
            get
            {
                return this._IsAuto;
            }
        }

        public bool IsTable
        {
            get
            {
                return this._IsTable;
            }
        }

        public bool IsProperty
        {
            get
            {
                return this._IsProperty;
            }
        }

        internal void SetKey(bool value)
        {
            this._IsKey = value;
        }

        private void SetAuto()
        {
            this._IsAuto = true;
            this.Owner.SetAuto();
        }
    }

    public class ORMapper
    {
        static ORMapper _Instance = null;

        static public ORMapper Create(string cfg_file)
        {
            _Instance = new ORMapper(cfg_file);

            return _Instance;
        }

        static public ORMapper Instance
        {
            get
            {
                if (ORMapper._Instance == null)
                {
                    throw new Exception("ORMapper 没有初始化");
                }

                return _Instance;
            }
        }

        private List<TableDef> TableList;

        private ORMapper(string cfg_file)
        {
            TableList = new List<TableDef>();

            this.Load(cfg_file);
        }

        #region Private Method

        private void Load(string path)
        {
            XmlDocument Doc = new XmlDocument();
            Doc.Load(path);

            XmlNodeList TableNodes = Doc.SelectNodes("/Dictionary/Table");
            foreach (XmlNode t_node in TableNodes)
            {
                string TableName = t_node.Attributes["Name"].Value;
                string ObjectType = t_node.Attributes["Class"].Value;

                TableDef td = new TableDef(TableName, ObjectType);
                TableList.Add(td);

                XmlNodeList FieldNodes = t_node.SelectNodes("Field");
                foreach (XmlNode f_node in FieldNodes)
                {
                    //bool Key = false;

                    string FieldName = f_node.Attributes["Name"].Value;
                    string FieldType = f_node.Attributes["Type"].Value;

                    string ObjectProp = FieldName;
                    XmlAttribute PropertyAttribute = f_node.Attributes["Property"];
                    if(PropertyAttribute != null)
                    {
                        ObjectProp = PropertyAttribute.Value;
                    }

                    FieldDef fd = new FieldDef(td, FieldName, FieldType, ObjectProp);

                    if (f_node.Attributes["Key"] != null)
                    {
                        fd.SetKey(Convert.ToBoolean(f_node.Attributes["Key"].Value));
                        td.KeyFields.Add(fd);
                    }

                    td.Add(fd);
                }
            }
        }

        private TableDef FindByClass(Type type)
        {
            TableDef Result = null;

            foreach (TableDef td in TableList)
            {
                if (td.ClassType == type)
                {
                    Result = td;
                }
            }

            return Result;
        }

        private TableDef FindByName(string name)
        {
            TableDef Result = null;

            foreach (TableDef td in TableList)
            {
                if (td.TableName == name)
                {
                    Result = td;
                }
            }

            return Result;
        }

        private List<SQLItem> MakeKeyItems(TableDef td, object obj)
        {
            List<SQLItem> Result = new List<SQLItem>();

            foreach (FieldDef fd in td.KeyFields)
            {
                object key_value = this.GetObjectField(fd, obj);
                SQLItem Item = new SQLItem(fd.Name, key_value, fd.Type);
                Result.Add(Item);
            }

            return Result;
        }

        private void SetStringValue(object obj, FieldInfo fd, string val_str)
        {
            fd.SetValue(obj, val_str);
        }

        private object GetObjectField(FieldDef fd, object obj)
        {
            object FieldValue = null;
            object PropertyObject = fd.PropertyObject;

            if (PropertyObject != null)
            {
                if (!fd.IsProperty)
                {
                    FieldValue = (PropertyObject as FieldInfo).GetValue(obj);
                }
                else
                {
                    PropertyInfo PublicProp = PropertyObject as PropertyInfo;
                    if (PublicProp != null)
                    {
                        if (PublicProp.CanRead)
                        {
                            FieldValue = PublicProp.GetValue(obj, null);
                        }
                    }
                    else
                    {
                        throw new Exception("No Property to Read:" + fd.Property);
                    }
                }
            }

            return FieldValue;
        }

        private void SetObjectField(FieldDef fd, object obj, object value)
        {
            object PropertyObject = fd.PropertyObject;

            if (PropertyObject != null)
            {
                if (!fd.IsProperty)
                {
                    FieldInfo PublicField = PropertyObject as FieldInfo;

                    if(PublicField.FieldType == typeof(Single))
                    {
                        PublicField.SetValue(obj, Convert.ToSingle(value));
                    }
                    else
                    {
                        PublicField.SetValue(obj, value);
                    }
                }
                else
                {
                    PropertyInfo PublicProp = PropertyObject as PropertyInfo;
                    if (PublicProp.CanWrite)
                    {
                        if(PublicProp.PropertyType == typeof(Single))
                        {                    
                            PublicProp.SetValue(obj, Convert.ToSingle(value), null);
                        }
                        else if (PublicProp.PropertyType == typeof(Int32))
                        {
                            PublicProp.SetValue(obj, Convert.ToInt32(value), null);
                        }
                        else
                        {
                            PublicProp.SetValue(obj, value, null);
                        }
                    }
                }
            }
        }

        private void FetchFromReader(object obj, IDataReader reader, TableDef td)
        {
            Type type = obj.GetType();

            foreach (FieldDef fd in td.Fields)
            {
                if (fd == null) continue;

                string FieldName = fd.Name;
                string PropName = fd.Property;
                object val_obj = null;

                if (!fd.IsTable)
                {
                    int FieldIndex = reader.GetOrdinal(FieldName);
                    val_obj = reader.GetValue(FieldIndex);

                    if (val_obj != null && val_obj != DBNull.Value)
                    {
                        switch (fd.Type)
                        {
                            case CommonDBType.Guid:
                                SetObjectField(fd, obj, new Guid(val_obj.ToString()));
                                break;

                            case CommonDBType.DataTime:
                                SetObjectField(fd, obj, DateTime.Parse(val_obj.ToString()));
                                break;

                            //case CommonDBType.String:
                            //    SetObjectField(type, obj, PropName, val_obj.ToString());
                            //    break;

                            default:
                                SetObjectField(fd, obj, val_obj);
                                break;
                        }
                    }
                    else
                    {
                        SetObjectField(fd, obj, null);
                    }
                }
                else
                {
                    object table_obj = null;
                    TableDef table_fd = this.FindByName(fd.Name);

                    FieldInfo ObjField = type.GetField(fd.Property, BindingFlags.Public | BindingFlags.Instance);
                    if (ObjField != null)
                    {
                        table_obj = ObjField.GetValue(obj);
                        if (table_obj != null)
                        {
                            this.FetchFromReader(table_obj, reader, table_fd);
                        }
                        else
                        {
                            //TODO:
                        }
                    }
                }
            }
        }

        private void MakeUpdateData(TableDef td, object obj, object old_obj, List<SQLItem> items)
        {
            foreach (FieldDef fd in td.Fields)
            {
                string FieldName = fd.Name;
                string PropName = fd.Property;
                object FieldValue;
                object OldFieldValue;

                FieldValue = null;

                if (fd.IsTable)
                {
                    TableDef table_td = this.FindByName(fd.Name);
                    FieldInfo ObjField = td.ClassType.GetField(fd.Property);
                    object table_obj = ObjField.GetValue(obj);
                    object old_table_obj = ObjField.GetValue(old_obj);

                    this.MakeUpdateData(table_td, table_obj, old_table_obj, items);
                }
                else
                {
                    if (!fd.IsAuto)
                    {
                        FieldValue = GetObjectField(fd, obj);
                        OldFieldValue = GetObjectField(fd, old_obj);

                        if (fd.Type == CommonDBType.Guid)
                        {
                            FieldValue = FieldValue == null ? null : FieldValue.ToString();
                            OldFieldValue = OldFieldValue == null ? null : OldFieldValue.ToString();
                        }
                        if (fd.Type == CommonDBType.DataTime)
                        {
                            if ((DateTime)FieldValue == DateTime.MinValue)
                            {
                                FieldValue = null;
                            }

                            if ((DateTime)OldFieldValue == DateTime.MinValue)
                            {
                                OldFieldValue = null;
                            }
                        }

                        if ( (FieldValue == null ^ OldFieldValue == null) || (FieldValue != null && !FieldValue.Equals(OldFieldValue)) )
                        {
                            items.Add(new SQLItem(FieldName, FieldValue, OldFieldValue, fd.Type));
                        }
                    }
                }
            }
        }

        private void MakeUpdateData(TableDef td, object obj, List<SQLItem> items)
        {
            foreach (FieldDef fd in td.Fields)
            {
                string FieldName = fd.Name;
                string PropName = fd.Property;
                object FieldValue;

                FieldValue = null;

                if (fd.IsTable)
                {
                    TableDef table_td = this.FindByName(fd.Name);
                    FieldInfo ObjField = td.ClassType.GetField(fd.Property);
                    object table_obj = ObjField.GetValue(obj);

                    this.MakeUpdateData(table_td, table_obj, items);
                }
                else
                {
                    if (!fd.IsAuto)
                    {
                        FieldValue = GetObjectField(fd, obj);

                        if (fd.Type == CommonDBType.Guid)
                        {
                            FieldValue = FieldValue == null ? null : FieldValue;
                        }
                        if (fd.Type == CommonDBType.DataTime)
                        {
                            if ((FieldValue != null) && ((DateTime)FieldValue == DateTime.MinValue))
                            {
                                FieldValue = null;
                            }
                        }

                        items.Add(new SQLItem(FieldName, FieldValue, fd.Type));
                    }
                }
            }
        }

        private long UpdateObject(object obj, IDBInterface db, TableDef td, List<SQLItem> SQLData)
        {
            long Result = 0;

            if (this.IfExist(td, obj, db))
            {
                List<SQLItem> CondData = this.MakeKeyItems(td, obj);
                string sql = db.GetSQLBuilder().PrepareUpdate(td.TableName, SQLData, CondData, db);
                Result = -db.ExecuteNonQuery(sql);
            }
            else
            {
                this.InsertObject(obj, db, td, SQLData);
            }

            return Result;
        }

        private long InsertObject(object obj, IDBInterface db, TableDef td, List<SQLItem> SQLData)
        {
            long Result = 0;

            string sql = db.GetSQLBuilder().PrepareInsert(td.TableName, SQLData, db);
            if (td.HasAuto)
            {
                sql += " SELECT @@IDENTITY;";
                object rt = db.ExecuteScaler(sql);
                if (rt != DBNull.Value)
                {
                    Result = Convert.ToInt64(rt);
                }
            }
            else
            {
                Result = -db.ExecuteNonQuery(sql);
            }

            return Result;
        }

        private bool IfExist(TableDef td, object obj, IDBInterface db)
        {
            bool Result = false; 

            List<SQLItem> ItemList = this.MakeKeyItems(td, obj);

            if (ItemList.Count > 0)
            {
                string sql = db.GetSQLBuilder().PrepareExist(td.TableName, ItemList, db);

                Result = (db.ExecuteScaler(sql) != null);
            }

            return Result;
        }

        #endregion

        #region Public Method

        public List<SQLItem> MakeInsertData(object obj)
        {
            List<SQLItem> Items = new List<SQLItem>();

            Type type = obj.GetType();
            TableDef td = this.FindByClass(type);

            this.MakeUpdateData(td, obj, Items);

            return Items;
        }

        public List<SQLItem> MakeUpdateData(object obj)
        {
            List<SQLItem> Items = new List<SQLItem>();

            Type type = obj.GetType();
            TableDef td = this.FindByClass(type);

            this.MakeUpdateData(td, obj, Items);

            return Items;
        }

        public void FetchFromReader<T>(T obj, IDataReader reader)
        {
            Type ObjectType = typeof(T);
            TableDef td = this.FindByClass(ObjectType);

            FetchFromReader(obj, reader, td);
        }

        public bool IfExist<T>(T obj, IDBInterface db)
        {
            Type type = typeof(T);
            TableDef td = this.FindByClass(type);


            return this.IfExist(td, obj, db);
        }

        public long InsertObject<T>(T obj, IDBInterface db)
        {
            Type type = obj.GetType();
            TableDef td = this.FindByClass(type);

            List<SQLItem> SQLData = new List<SQLItem>();
            this.MakeUpdateData(td, obj, SQLData);

            return InsertObject(obj, db, td, SQLData);
        }

        public long UpdateObject<T>(T obj, IDBInterface db)
        {
            Type type = obj.GetType();
            TableDef td = this.FindByClass(type);

            List<SQLItem> SQLData = new List<SQLItem>();
            this.MakeUpdateData(td, obj, SQLData);

            return UpdateObject(obj, db, td, SQLData);
        }

        public List<SQLItem> UpdateObject<T>(T obj, T old_obj, IDBInterface db)
        {
            Type type = typeof(T);

            TableDef td = this.FindByClass(type);

            List<SQLItem> SQLData = new List<SQLItem>();
            if (old_obj != null)
            {
                this.MakeUpdateData(td, obj, old_obj, SQLData);

                if (SQLData.Count > 0)
                {
                    List<SQLItem> CondData = this.MakeKeyItems(td, obj);
                    string sql = db.GetSQLBuilder().PrepareUpdate(td.TableName, SQLData, CondData, db);

                    int rt = db.ExecuteNonQuery(sql);
                    if (rt != 1) SQLData = null;
                }
            }
            else
            {
                this.MakeUpdateData(td, obj, SQLData);
                this.UpdateObject(obj, db, td, SQLData);
            }

            return SQLData;
        }

        public void SelectObject<T>(T obj, IDBInterface db)
        {
            Type type = typeof(T);
            TableDef td = this.FindByClass(type);

            List<SQLItem> ItemList = null;
            //if (td.KeyFields.Count > 1)
            {
                ItemList = this.MakeKeyItems(td, obj);
            }
            //else
            //{
            //    ItemList = new List<SQLItem>();
            //    ItemList.Add(new SQLItem(td.KeyFields[0].Name, obj, td.KeyFields[0].Type));
            //}

            string sql = db.GetSQLBuilder().PrepareSelect(td.TableName, ItemList, db);
            IDataReader Reader = db.ExecuteReader(sql);

            using (Reader)
            {
                if (Reader.Read())
                {
                    FetchFromReader(obj, Reader, td);
                }
            }
        }

        #endregion
    }
}
