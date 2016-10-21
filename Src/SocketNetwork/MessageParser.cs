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

            size = data == null ? 0 : data.Length;
        }

        /// <summary>
        /// 获得一个short类型的数据
        /// </summary>
        /// <returns></returns>
        public short GetShort()
        {
            this.Check(2);

            short ret;

            ret = BitConverter.ToInt16(Data, pos);

            pos += 2;

            return ret;
        }

        public short GetShortReverse()
        {
            short ret;

            byte[] Temp = this.GetReverse(2);
            ret = BitConverter.ToInt16(Temp, 0);

            pos += 2;

            return ret;
        }
        
        public int GetInt()
        {
            this.Check(4);

            int ret;

            ret = BitConverter.ToInt16(Data, pos);

            pos += 4;

            return ret;
        }

        public int GetIntReverse()
        {
            int ret;

            byte[] Temp = this.GetReverse(2);
            ret = BitConverter.ToInt16(Temp, 0);

            pos += 4;

            return ret;
        }

        public int GetLong()
        {
            this.Check(4);

            int ret;

            ret = BitConverter.ToInt32(Data, pos);

            pos += 4;

            return ret;
        }

        public int GetLongReverse()
        {
            int ret;

            byte[] Temp = this.GetReverse(4);
            ret = BitConverter.ToInt32(Temp, 0);

            pos += 4;

            return ret;
        }
        
        public float GetFloat()
        {
            this.Check(4);

            float ret;
              
            ret = BitConverter.ToSingle(Data, pos);

            pos += 4;

            return ret;
        }

        public float GetFloatReserve()
        {
            float ret;

            byte[] Temp = this.GetReverse(4);
            ret = BitConverter.ToSingle(Temp, 0);

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
            short len = GetShort();

            this.Check(len);

            byte[] bytebuffer = new byte[len];            
            Array.Copy(Data, pos, bytebuffer, 0, len);

            str = Encoding.ASCII.GetString(bytebuffer, 0, len);

            pos += len;

            return str;
        }

        public string GetString(int len)
        {
            string str = string.Empty;
            this.Check(len);

            byte[] bytebuffer = new byte[len];
            Array.Copy(Data, pos, bytebuffer, 0, len);

            str = Encoding.ASCII.GetString(bytebuffer, 0, len);

            pos += len;

            return str;
        }
        
        public string GetUnicodeString()
        {
            string str = string.Empty;
            short len = GetShort();
            len *= 2;

            this.Check(len);
            byte[] bytebuffer = new byte[len];
            Array.Copy(Data, pos, bytebuffer, 0, len);

            str = Encoding.Unicode.GetString(bytebuffer, 0, len);
            
            pos += len;

            return str;
        }

        private void Check(int len)
        {
            if (pos + len > size)
            {
                throw new Exception("超出数据范围");
            }        
        }

        private byte[] GetReverse(int len)
        {
            this.Check(len);

            byte[] ret = new byte[len];
            Array.Copy(Data, pos, ret, 0, len);

            Array.Reverse(ret);

            return ret;
        }
    }
}
