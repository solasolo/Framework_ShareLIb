using System;
using System.Collections.Generic;
using System.Text;

namespace GLEO.MES.Network
{

    public class MessageEnity
    {
        public short Code { get; set; }
        public byte[] Data { get; set; }
    }

    /// <summary>
    /// 
    /// </summary>
    public class SimpleProtocolEncoder
    {
        const char STX = '\x02';
        const char ETX = '\x03';

        private StreamBuffer Buffer;

        public SimpleProtocolEncoder()
        {
            this.Buffer = new StreamBuffer();
        }
        
        public SimpleProtocolEncoder(StreamBuffer buf)
        {
            this.Buffer = buf;
        }

        public void Add(int data)
        {
            this.Buffer.SetData(BitConverter.GetBytes((short)data));
        }

        public void Add(string data)
        {
            byte[] len = BitConverter.GetBytes((short)data.Length);

            this.Buffer.SetData(len);
            this.Buffer.SetData(Encoding.ASCII.GetBytes(data));
        }

        public byte[] GetData(short ID)
        {
            byte[] msg = this.Buffer.BuildData();
            byte[] TelID = BitConverter.GetBytes(ID);
            int size = msg.Length;

            if (size >= 6)
            {
                msg[0] = (byte)STX;
                msg[3] = TelID[0];
                msg[4] = TelID[1];
                msg[size - 1] = (byte)ETX;
            }

            return msg;
        }
    }

    /// <summary>
    /// 
    /// </summary>
    public class SimpleProtocolDecoder
    {
        const char STX = '\x02';
        const char ETX = '\x03';

        private StreamBuffer Buffer;

        public SimpleProtocolDecoder(StreamBuffer buf)
        {
            this.Buffer = buf;
        }

        public bool CheckData(ref MessageEnity msgEntity)
        {
            bool result = false;

            int bufSize = this.Buffer.GetSize();

            if (bufSize > 8)
            {
                while (this.Buffer.GetSize() > 0 && this.Buffer.ReadByte(0) != STX)
                {
                    this.Buffer.PickData(1);//删除无效数据
                }

                if (this.Buffer.ReadByte(0) == STX && bufSize > 8)
                {
                    int telSize = this.Buffer.ReadInt(1);   // 2byte
                    short cmd = this.Buffer.ReadShort(3);  // 2byte

                    this.Buffer.PickData(5);		// 删除cmd及之前的字节1+2+2

                    msgEntity.Code = cmd;
                    msgEntity.Data = new byte[telSize - 4];

                    this.Buffer.PickData(msgEntity.Data, telSize - 4);

                    result = true;
                }
            }

            return result;
        }
    }
}
