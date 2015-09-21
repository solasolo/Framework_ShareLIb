using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace GLEO.System
{
    public class ObjectHelper
    {
        static public void Clone(object src, object dest)
        {
            Type type = src.GetType();
            foreach (FieldInfo item in type.GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic))
            {
                Type FieldType = item.FieldType;

                if (FieldType.IsValueType || FieldType == typeof(string))
                {
                    item.SetValue(dest, item.GetValue(src));
                }
            }
        }
    }
}
