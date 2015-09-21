using System;
using System.Collections.Generic;
using System.Text;

namespace GLEO.MES.Network
{
    public interface IProtocolDecoder
    {
        bool CheckData(StreamBuffer buf, ref MessageEnity msgEntity);
    }

    public class MessageEnity
    {
        public int Code { get; set; }
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
    public class SimpleProtocolDecoder: IProtocolDecoder
    {
        const char STX = '\x02';
        const char ETX = '\x03';

        public bool CheckData(StreamBuffer buf, ref MessageEnity msgEntity)
        {
            bool result = false;

            int bufSize = buf.GetSize();

            if (bufSize > 8)
            {
                while (buf.GetSize() > 0 && buf.ReadByte(0) != STX)
                {
                    buf.PickData(1);//删除无效数据
                }

                if (buf.ReadByte(0) == STX && bufSize > 8)
                {
                    int telSize = buf.ReadShort(1);   // 2byte
                    short cmd = buf.ReadShort(3);  // 2byte

                    buf.PickData(5);		// 删除cmd及之前的字节1+2+2

                    msgEntity.Code = cmd;
                    msgEntity.Data = new byte[telSize - 4];

                    buf.PickData(msgEntity.Data, telSize - 4);

                    result = true;
                }
            }

            return result;
        }
    }
}
