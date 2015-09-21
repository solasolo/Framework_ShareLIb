using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GLEO.MES.Network
{
    public class StreamBuffer
    {
        //
        struct Cursor
        {
            public int ListIndex;
            public int Pos;
        }

        //
        private List<byte[]> Buffer;

        //
        public StreamBuffer()
        {
            Buffer = new List<byte[]>();
        }

        public void Clear()
        {
            this.Buffer.Clear();
        }

        public static StreamBuffer operator +(StreamBuffer buffer, byte[] data)
        {
            buffer.Buffer.Add(data);

            return buffer;
        }

        private bool locate(int pos, ref Cursor cur)
        {
            bool bret = false;

            if (this.Buffer.Count > 0)
            {
                cur.ListIndex = 0;
                cur.Pos = 0;

                if (pos == 0)
                {
                    bret = true;
                }
                else
                {
                    while (cur.ListIndex < this.Buffer.Count && pos > 0)
                    {
                        int n = this.Buffer[cur.ListIndex].Length;

                        if (pos >= n)
                        {
                            pos -= n;
                            cur.ListIndex++;
                        }
                        else
                        {
                            cur.Pos = pos;
                            bret = true;

                            break;
                        }
                    }
                }
            }

            return bret;
        }

        public void SetData(byte[] data)
        {
            this.Buffer.Add(data);
        }

        public int GetSize()
        {
            int size = 0;

            List<byte[]>.Enumerator it = this.Buffer.GetEnumerator();
            while (it.MoveNext())
            {
                size += it.Current.Length;
            }

            return size;
        }

        private bool ReadData(byte[] buffer, int pos, int len)
        {
            bool bret = false;

            Cursor cur = new Cursor();
            bret = locate(pos, ref cur);

            if (bret)
            {
                int c = 0;

                do
                {
                    if (len - c == 0)
                    {
                        break;
                    }

                    int n = this.Buffer[cur.ListIndex].Length;
                    n -= cur.Pos;
                    if (len - c < n)
                    {
                        n = len - c;
                    }

                    Array.Copy(this.Buffer[cur.ListIndex], cur.Pos, buffer, c, n);
                    c += n;
                    cur.Pos = 0;
                } 
                while (cur.ListIndex < this.Buffer.Count && c < len);

                if (len != c) bret = false;
            }

            return bret;
        }

        public bool ReadData(byte[] buffer, int len)
        {
            bool bret = false;
            int c = 0;

            if (this.GetSize() >= len)
            {
                List<byte[]>.Enumerator it = this.Buffer.GetEnumerator();
                while (it.MoveNext() && c < len)
                {
                    int n = it.Current.Length;
                    if (len - c < n)
                    {
                        n = len - c;
                    }

                    Array.Copy(it.Current, 0, buffer, c, n);

                    c += n;
                }

                bret = true;
            }

            return bret;
        }

        public void PickData(byte[] buffer, int len)
        {
            bool bret = this.ReadData(buffer, len);

            if (bret)
            {
                this.PickData(len);
            }
        }

        public void PickData(int len)
        {
            // 删除解析完成的数据

            if (GetSize() >= len)
            {
                int c = 0;
                int n = 0;
                int n_len = 0;

                for (int i = 0; i < this.Buffer.Count; i++)
                {
                    if (len - c == 0)
                    {
                        break;
                    }

                    n = this.Buffer[i].Length;
                    n_len = n;

                    if (len - c < n)
                    {
                        n = len - c;
                        n_len -= n;
                        //it->erase(0, n);
                        byte[] n_buffer = new byte[n_len];

                        Array.Copy(this.Buffer[i], n, n_buffer, 0, n_len);

                        this.Buffer[i] = n_buffer;

                        break;
                    }
                    else
                    {
                        //it = Buffer.erase(it);
                        this.Buffer.RemoveAt(i);
                    }

                    c += n;
                }

            }
        }

        public byte ReadByte(int pos)
        {
            byte data = 0;

            byte[] b = new byte[1];

            this.ReadData(b, pos, 1);
            data = b[0];

            return data;
        }

        public int ReadInt(int pos)
        {
            int data = 0;

            byte[] b = new byte[4];

            this.ReadData(b, pos, 4);

            data = BitConverter.ToInt32(b, 0);

            return data;
        }

        public short ReadShort(int pos)
        {
            short data = 0;

            byte[] b = new byte[2];

            this.ReadData(b, pos, 2);

            data = BitConverter.ToInt16(b, 0);

            return data;
        }

        public string ReadString(int pos)
        {
            string data = string.Empty;

            short len = this.ReadShort(pos);
            byte[] temp = new byte[len];

            if (this.ReadData(temp, pos + 2, len))
            {
                data = Encoding.ASCII.GetString(temp);
            }

            return data;
        }

        public string ReadString(int pos, int len)
        {
            string data = string.Empty;

            byte[] temp = new byte[len];

            if (this.ReadData(temp, pos, len))
            {
                data = Encoding.ASCII.GetString(temp);
            }

            return data;
        }


        /// <summary>
        /// 返回一个字节数组
        /// </summary>
        /// <returns></returns>
        public byte[] BuildData()
        {
            int size = this.GetSize() + 6;//头尾各1  总长2位   电文号2位

            byte[] msg = new byte[size];
            byte[] data_Len = BitConverter.GetBytes(size - 2);
            msg[1] = data_Len[0];
            msg[2] = data_Len[1];
            int n = 5;  //电文体起始位置 

            List<byte[]>.Enumerator it = this.Buffer.GetEnumerator();

            while (it.MoveNext())
            {
                Array.Copy(it.Current, 0, msg, n, it.Current.Length);
                n += it.Current.Length;
            }


            this.Buffer.Clear();

            return msg;
        }
    }
}
