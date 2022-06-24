using System;
using System.Collections.Generic;
using System.Text;

namespace GLEO.MES.Network
{

    //
    //  STX
    //  LEN  Include LEN, CMD, Payload
    //  CMD
    //  Payload
    //  ETX
    //

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
        const int CMD_SIZE = 2;
        const int LEN_SIZE = 4;
        const int HEAD_SIZE = CMD_SIZE + LEN_SIZE;

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
            this.Buffer.SetData(BitConverter.GetBytes(data));
        }

        public void Add(string data)
        {
            byte[] len = BitConverter.GetBytes((short)data.Length);

            this.Buffer.SetData(len);
            this.Buffer.SetData(Encoding.ASCII.GetBytes(data));
        }

        public byte[] GetData(short ID)
        {
            byte[] msg = this.Buffer.BuildData(HEAD_SIZE + 2, HEAD_SIZE + 1);
            int size = msg.Length;

            msg[0] = (byte)STX;

            byte[] data_Len = BitConverter.GetBytes(size - 2);
            msg[1] = data_Len[0];
            msg[2] = data_Len[1];
            msg[3] = data_Len[2];
            msg[4] = data_Len[3];

            byte[] TelID = BitConverter.GetBytes(ID);
            msg[LEN_SIZE + 1] = TelID[0];
            msg[LEN_SIZE + 2] = TelID[1];

            msg[size - 1] = (byte)ETX;

            return msg;
        }
    }

    /// <summary>
    /// 
    /// </summary>
    public class SimpleProtocolDecoder : IProtocolDecoder
    {
        const int CMD_SIZE = 2;
        const int LEN_SIZE = 4;
        const int HEAD_SIZE = CMD_SIZE + LEN_SIZE;

        const char STX = '\x02';
        const char ETX = '\x03';

        public bool CheckData(StreamBuffer buf, ref MessageEnity msgEntity)
        {
            bool result = false;
            bool remain = false;

            do
            {
                int bufSize = buf.GetSize();

                while (buf.GetSize() > 0 && buf.ReadByte(0) != STX)
                {
                    buf.PickData(1);//删除无效数据
                }

                if (bufSize >= HEAD_SIZE + 2)
                {
                    if (buf.ReadByte(0) == STX)  // Meet Head
                    {
                        int telSize = buf.ReadInt(1);   // 4 bytes Len
                        if (telSize >= HEAD_SIZE && bufSize >= telSize + 2)
                        {
                            if (buf.ReadByte(telSize + 1) == ETX)
                            {
                                short cmd = buf.ReadShort(LEN_SIZE + 1);  // 2 bytes Cmd
                                msgEntity.Code = cmd;

                                buf.PickData(HEAD_SIZE + 1);        // 删除cmd及之前的字节 1 + 2 + 4


                                if (telSize > HEAD_SIZE)
                                {
                                    msgEntity.Data = new byte[telSize - HEAD_SIZE];

                                    buf.PickData(msgEntity.Data, telSize - HEAD_SIZE);
                                }
                                else
                                {
                                    msgEntity.Data = null;
                                }

                                buf.PickData(1); // Remove ETX
                                result = true;
                            }
                            else
                            {
                                buf.PickData(1); // Remove STX
                                remain = true;
                            }
                        }
                    }
                }
            }
            while (!result && remain);

            return result;
        }
    }
}
