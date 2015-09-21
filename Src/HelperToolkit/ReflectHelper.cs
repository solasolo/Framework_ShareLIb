using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.Remoting;
using System.Reflection;
using System.IO;

namespace GLEO.Base
{
    public delegate void AssemblyCallback(Assembly assm);

    public static class ReflectHelper
    {
        static IDictionary<string, HashSet<string>> SearchPathList = new Dictionary<string, HashSet<string>>();

        static ReflectHelper()
        {
        }

        static public void RegistSearchPath(string path)
        {
            SearchPathList[path] = new HashSet<string>();
        }

        // Create Type

        static public Type CreateType(string name)
        {
            Type Result = Type.GetType(name);

            if (Result == null)
            {
                Result = GetMemoryType(name);
                if (Result == null)
                {
                    Result = GetTypeFromSearchPath(name);
                }
                if (Result == null)
                {
                    Result = GetSplitParadigmType(name);
                }
            }

            return Result;
        }

        static public Type CreateType(string genic_name, string para_name)
        {
            Type genic_type = CreateType(genic_name);
            Type para_type = CreateType(para_name);

            return CreateType(genic_type, para_type);
        }

        static public Type CreateType(Type genic_type, Type para_type)
        {
            Type type = null;

            if (genic_type.IsGenericType)
            {
                type = genic_type.MakeGenericType(new Type[1] { para_type });
            }

            return type;
        }

        // Create Object

        static public object CreateObject(Type type)
        {
            return Activator.CreateInstance(type);
        }

        static public object CreateObject(Type genic_type, Type para_type, params object[] paras)
        {
            Type type = CreateType(genic_type, para_type);

            return Activator.CreateInstance(type, paras);
        }

        static public object CreateObject(string type_name)
        {
            Type type = CreateType(type_name);

            return Activator.CreateInstance(type);
        }

        static public object CreateObject(Type type, params object[] paras)
        {
            return Activator.CreateInstance(type, paras);
        }

        static public object CreateObject(string type_name, params object[] paras)
        {
            Type type = CreateType(type_name);

            return Activator.CreateInstance(type, paras);
        }

        //

        static public void SetFieldValue(object obj, string field_name, object value)
        {
            FieldInfo objFieldinfo = obj.GetType().GetField(field_name, BindingFlags.Instance | BindingFlags.NonPublic);
            if (objFieldinfo == null)
            {
                objFieldinfo = obj.GetType().BaseType.GetField(field_name, BindingFlags.Instance | BindingFlags.NonPublic);
            }

            objFieldinfo.SetValue(obj, value);
        }

        static public object GetFieldValue(object obj, string field_name)
        {
            FieldInfo objFieldinfo = GetFieldValueByType(obj.GetType(), field_name);

            return objFieldinfo.GetValue(obj);
        }

        static public object GetPropertyValue(object obj, string field_name)
        {
            PropertyInfo objFieldinfo = GetPropertyValueByType(obj.GetType(), field_name);

            return objFieldinfo.GetValue(obj, null);
        }


        static public void SetObjectProp(object obj, string propName, object value)
        {
            Type type = obj.GetType();

            if (!String.IsNullOrEmpty(propName))
            {
                PropertyInfo Prop = type.GetProperty(propName);
                if (Prop != null)
                {
                    if (Prop.CanWrite)
                    {
                        Type FieldType = Prop.PropertyType;
                        value = ConvertValue(FieldType, value);

                        Prop.SetValue(obj, value, null);
                    }
                }
                else
                {
                    FieldInfo Field = type.GetField(propName);
                    if (Field != null)
                    {
                        Type FieldType = Field.FieldType;
                        value = ConvertValue(FieldType, value);

                        Field.SetValue(obj, value);
                    }
                }
            }
        }

        static public object GetObjectProp(object obj, string propName)
        {
            object Result = null;

            if (obj != null)
            {
                Type type = obj.GetType();

                if (!String.IsNullOrEmpty(propName))
                {
                    PropertyInfo Prop = type.GetProperty(propName);
                    if (Prop != null)
                    {
                        if (Prop.CanRead)
                        {
                            Result = Prop.GetValue(obj, null);
                        }
                    }
                    else
                    {
                        FieldInfo Field = type.GetField(propName);
                        if (Field != null)
                        {
                            Type FieldType = Field.FieldType;
                            if (FieldType == typeof(decimal))
                            {
                                Result = ((decimal)Field.GetValue(obj)).ToString("0.00");
                            }
                            else
                            {
                                Result = Field.GetValue(obj);
                            }
                        }
                    }
                }
            }

            return Result;
        }

        static public object InvokeMethod(object obj, string MethodName, object[] Parameters)
        {
            Type objType = obj.GetType();

            MethodInfo ObjMethod = objType.GetMethod(MethodName);

            return ObjMethod.Invoke(obj, Parameters);
        }

        static public void InvokeEventMethod(object obj, string MethodName)
        {
            Type objType = obj.GetType();

            MethodInfo ObjMethod = objType.GetMethod(MethodName);

            if (ObjMethod != null)
            {
                ObjMethod.Invoke(obj, null);
            }
        }

        static public bool IfImplementInterface(Type type, Type intf)
        {
            bool Result = false;

            foreach (Type i in type.GetInterfaces())
            {
                if (i == intf)
                {
                    Result = true;
                    break;
                }
            }

            return Result;
        }

        static public bool IsInterface(Type type)
        {
            return type.IsInterface;
        }

        static public void WalkThrowAssembly(AssemblyCallback callback)
        {
            foreach (string path in SearchPathList.Keys)
            {

            }
        }

        #region Private Members

        static private Type GetTypeFromAssembly(string name, string path)
        {
            Type TempType = null;
            AppDomain currentDomain = AppDomain.CurrentDomain;

            if (SearchPathList.ContainsKey(path))
            {
                HashSet<string> AssemblyInPath = SearchPathList[path];

                DirectoryInfo di = new DirectoryInfo(path);
                FileInfo[] fi = di.GetFiles("*.dll");
                foreach (FileInfo file in fi)
                {
                    if (!AssemblyInPath.Contains(file.Name))
                    {
                        Assembly TempAssembly = null;
                        try
                        {
                            TempAssembly = Assembly.LoadFile(file.FullName);
                            AssemblyInPath.Add(file.Name);
                        }
                        catch (BadImageFormatException ex)
                        {
                            // TODO: if (Doctor != null) Doctor.Log(MessageType.Warning, ex.Message);
                        }

                        if (TempAssembly != null)
                        {
                            TempType = TempAssembly.GetType(name);
                        }

                        if (TempType != null) break;
                    }
                }
            }

            return TempType;
        }

        static private Type GetTypeFromSearchPath(string name)
        {
            Type Result = null;

            RefreshAssemlyLoadedState();

            foreach (string p in SearchPathList.Keys)
            {
                Result = GetTypeFromAssembly(name, p);

                if (Result != null) break;
            }

            return Result;
        }

        static private Type GetMemoryType(string name)
        {
            Type temp = null;
            AppDomain currentDomain = AppDomain.CurrentDomain;
            Assembly[] assems = currentDomain.GetAssemblies();

            foreach (Assembly assem in assems)
            {
                temp = assem.GetType(name);
                if (temp != null)
                {
                    break;
                }
            }

            return temp;
        }

        static private FieldInfo GetFieldValueByType(Type type, string field_name)
        {
            FieldInfo objFieldinfo = type.GetField(field_name, BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
            if (objFieldinfo == null)
            {
                objFieldinfo = GetFieldValueByType(type.BaseType, field_name);
            }
            return objFieldinfo;
        }

        static private PropertyInfo GetPropertyValueByType(Type type, string field_name)
        {
            PropertyInfo objFieldinfo = type.GetProperty(field_name, BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
            if (objFieldinfo == null)
            {
                objFieldinfo = GetPropertyValueByType(type.BaseType, field_name);
            }
            return objFieldinfo;
        }

        static private void RefreshAssemlyLoadedState()
        {
            AppDomain currentDomain = AppDomain.CurrentDomain;
            Assembly[] asms = currentDomain.GetAssemblies();

            foreach (Assembly asm in asms)
            {
                string Location = string.Empty;
                try
                {
                    Location = asm.Location;
                }
                catch
                {
                    continue;
                }

                string Path = Location.Substring(0, Location.LastIndexOf('\\') + 1);
                string BinName = Location.Substring(Path.Length);

                if (SearchPathList.ContainsKey(Path))
                {
                    SearchPathList[Path].Add(BinName);
                }

            }
        }

        static private Type GetSplitParadigmType(string name)
        {
            Type Result = null;
            string[] StrList = name.Split('[');
            if (StrList.Length > 1)
            {
                string Paradigm = StrList[0];
                string ObjType = StrList[1].Substring(0, StrList[1].Length - 1);
                Result = CreateType(Paradigm, ObjType);
            }

            return Result;
        }

        static private object ConvertValue(Type type, object value)
        {
            object Result = value;

            if (value != null)
            {
                if (type != typeof(string) && value.GetType() == typeof(string))
                {
                    string valueStr = value.ToString();

                    if (!String.IsNullOrEmpty(valueStr))
                    {
                        if (type == typeof(int))
                        {
                            Result = Convert.ToInt32(value);
                        }
                        else if (type == typeof(decimal))
                        {
                            Result = Convert.ToDecimal(value);
                        }
                        else if (type == typeof(float))
                        {
                            Result = Convert.ToSingle(value);
                        }
                        else if (type == typeof(double))
                        {
                            Result = Convert.ToDouble(value);
                        }
                        else if (type == typeof(DateTime))
                        {
                            Result = Convert.ToDateTime(value);
                        }
                    }
                }
            }

            return Result;
        }

        #endregion
    }

}
