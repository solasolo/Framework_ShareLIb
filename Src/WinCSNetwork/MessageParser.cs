using System;
using System.Collections.Generic;
using System.Text;

namespace GLEO.MES.Network
{
    public class MessageParser
    {
        private byte[] Data;
        private int pos;
        private int size;

        public MessageParser(byte[] data)
        {
            Data = data;
            pos = 0;
            size = data.Length;
        }

        /// <summary>
        /// 获得一个short类型的数据
        /// </summary>
        /// <returns></returns>
        public short GetInt()
        {
            if (pos + 2 > size)
            {
                throw new Exception("超出数据范围");
            }

            short ret;

            ret = BitConverter.ToInt16(Data, pos);
            //ret = (short)((short)(Data[pos + 1] << 8) + (short)Data[pos]);

            pos += 2;

            return ret;
        }

        public float GetFloat()
        {
            if (pos + 4 > size)
            {
                throw new Exception("超出数据范围");
            }

            float ret;
              
            ret = BitConverter.ToSingle(Data, pos);

            pos += 4;

            return ret;
        }
        
        /// <summary>
        /// 获得一个string
        /// </summary>
        /// <returns></returns>
        public string GetString()
        {
            string str = string.Empty;
            short len = GetInt();

            if (pos + len > size)
            {
                throw new Exception("超出数据范围");
            }

            byte[] bytebuffer = new byte[len];            
            Array.Copy(Data, pos, bytebuffer, 0, len);

            str = Encoding.ASCII.GetString(bytebuffer, 0, len);

            pos += len;

            return str;
        }

        public string GetUnicodeString()
        {
            if (pos >= size)
            {
                throw new Exception("超出数据范围");
            }

            string str = string.Empty;
            short len = GetInt();
            len = (short)(len * 2);

            if (pos + len > size)
            {
                throw new Exception("超出数据范围");
            }

            byte[] bytebuffer = new byte[len];
            Array.Copy(Data, pos, bytebuffer, 0, len);

            str = Encoding.Unicode.GetString(bytebuffer, 0, len);
            
            pos += len;

            return str;
        }
    }
}
