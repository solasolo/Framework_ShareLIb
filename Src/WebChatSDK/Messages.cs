using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace GLEO.WebChatSDK
{
    /// <summary>
    /// 事件类型
    /// </summary>
    public enum EventType
    {
        UnKnown,
        Subscribe,
        UnSubscribe,
        Scan,
        Location,
        Click
    }

    public enum MsgType
    {
        UnKnown,
        Text,
        Image,
        Voice,
        News,
        VoiceResult,
        Video,
        Location,
        Link,
        Event
    }

    /// <summary>
    /// 接收到的消息基类
    /// </summary>
    public class MessageBase
    {
        public string MessageBody { get; set; }
        public MsgType MsgType { get; set; }
        public string ToUserName { get; set; }
        public string FromUserName { get; set; }
        public DateTime CreateTime { get; set; }

        public MessageBase()
        {
            this.CreateTime = DateTime.Now;
        }

        virtual protected void MakeXML(XMLBuilder xb)
        {
            xb.AddString("ToUserName", this.ToUserName);
            xb.AddString("FromUserName", this.FromUserName);
            xb.AddString("MsgType", this.MsgType.ToString().ToLower());
            xb.AddDateTime("CreateTime", this.CreateTime);
        }

        public string ToXMLString()
        {
            XMLBuilder xb = new XMLBuilder();

            this.MakeXML(xb);

            return xb.GetResult();
        }
    }

    /// <summary>
    /// 接收消息实体类
    /// </summary>
    public class Message : MessageBase
    {
        public long MsgId { get; set; }

        static public Message Parse(XmlDocument data)
        {
            Message Result = null;
            XmlElement rootElement = data.DocumentElement;

            Func<string, string> ReadNode = (key) =>
            {
                XmlNode temp_node = rootElement.SelectSingleNode(key);
                return (temp_node == null) ? String.Empty : temp_node.InnerText.Trim();
            };


            string MessageType = ReadNode("MsgType").ToLower();

            switch (MessageType)
            {
                case "text":
                    {
                        TextMessage msg = new TextMessage()
                        {
                            Content = ReadNode("Content")
                        };

                        Result = msg;
                    }
                    break;

                case "image":
                    {
                        ImageMessage msg = new ImageMessage()
                        {
                            MediaId = ReadNode("MediaId"),
                            PicUrl = ReadNode("PicUrl")
                        };

                        Result = msg;
                    }
                    break;

                case "voice":
                    {
                        XmlNode node1 = rootElement.SelectSingleNode("Recognition");

                        VoiceMessage msg = new VoiceMessage()
                        {
                            MsgType = ((node1 == null) ? MsgType.Voice : MsgType.VoiceResult),
                            Recognition = ReadNode("Recognition"),
                            Format = ReadNode("Format"),
                            MediaId = ReadNode("MediaId")
                        };

                        Result = msg;
                    }
                    break;

                case "video":
                    {
                        VideoMessage msg = new VideoMessage()
                        {
                            MediaId = ReadNode("MediaId"),
                            ThumbMediaId = ReadNode("ThumbMediaId")
                        };

                        Result = msg;
                    }
                    break;

                case "location":
                    {
                        LocationMessage msg = new LocationMessage()
                        {
                            Label = ReadNode("Label"),
                            Location_X = ReadNode("Location_X"),
                            Location_Y = ReadNode("Location_Y "),
                            Scale = ReadNode("Scale")
                        };

                        Result = msg;
                    }
                    break;

                case "link":
                    {
                        LinkMessage msg = new LinkMessage()
                        {
                            Description = ReadNode("Description"),
                            Title = ReadNode("Title"),
                            Url = ReadNode("Url ")
                        };

                        Result = msg;
                    }
                    break;

                case "event":
                    XmlNode eventNode = rootElement.SelectSingleNode("Event");
                    if (eventNode != null)
                    {
                        switch (eventNode.InnerText.Trim().ToLower())
                        {
                            case "subscribe":
                                {
                                    SubscribeEventMessage msg = new SubscribeEventMessage()
                                    {
                                        EventKey = ReadNode("EventKey"),
                                        Ticket = ReadNode("Ticket")
                                    };

                                    Result = msg;
                                }
                                break;

                            case "unsubscribe":
                                {
                                    UnSubscribeEventMessage msg = new UnSubscribeEventMessage();

                                    Result = msg;
                                }
                                break;

                            case "scan":
                                {
                                    ScanEventMessage msg = new ScanEventMessage()
                                    {
                                        EventKey = ReadNode("EventKey"),
                                        Ticket = ReadNode("Ticket"),
                                    };

                                    Result = msg;
                                }
                                break;

                            case "location":
                                {
                                    UploadLocationEventMessage msg = new UploadLocationEventMessage()
                                    {
                                        Latitude = ReadNode("Latitude"),
                                        Longitude = ReadNode("Longitude"),
                                        Precision = ReadNode("Precision"),
                                    };

                                    Result = msg;
                                }
                                break;

                            case "click":
                                {
                                    MenuEventMessage msg = new MenuEventMessage()
                                    {
                                        EventKey = ReadNode("EventKey"),
                                    };

                                    Result = msg;
                                }
                                break;

                            default:
                                {
                                    EventMessages msg = new EventMessages();

                                    Result = msg;
                                }
                                break;
                        }
                    }

                    break;
            }

            if (Result != null)
            {
                Result.FromUserName = ReadNode("FromUserName");
                Result.ToUserName = ReadNode("ToUserName");
                Result.CreateTime = Helper.Long2DateTime(Int32.Parse(ReadNode("CreateTime")));
                Result.MsgId = Int64.Parse(ReadNode("CreateTime"));
            }

            return Result;
        }
    }

    /// <summary>
    /// 文本消息
    /// </summary>
    public class TextMessage : Message
    {
        public string Content { get; set; }

        public TextMessage()
            : base()
        {
            this.MsgType = MsgType.Text;
        }

        override protected void MakeXML(XMLBuilder xb)
        {
            base.MakeXML(xb);
            xb.AddString("Content", this.Content);
        }
    }

    /// <summary>
    /// 图片信息
    /// </summary>
    public class ImageMessage : Message
    {
        public string PicUrl { get; set; }
        public string MediaId { get; set; }

        public ImageMessage()
            : base()
        {
            this.MsgType = MsgType.Image;
        }

        override protected void MakeXML(XMLBuilder xb)
        {
            base.MakeXML(xb);
            xb.AddString("MediaId", this.MediaId);
        }
    }

    public class NewsMessageItem
    {
        public string Title { get; set; }
        public string Description { get; set; }
        public string PicUrl { get; set; }
        public string Url { get; set; }
    }

    /// <summary>
    /// 图片信息
    /// </summary>
    public class NewsMessage : Message
    {
        public string PicUrl { get; set; }
        public string MediaId { get; set; }
        public List<NewsMessageItem> Items { get; set; }

        public NewsMessage()
            : base()
        {
            this.MsgType = MsgType.News;
            this.Items = new List<NewsMessageItem>();
        }

        override protected void MakeXML(XMLBuilder xb)
        {
            base.MakeXML(xb);
            xb.AddInt("ArticleCount", this.Items.Count);

            xb.AddTag("Articles");
            foreach (NewsMessageItem item in this.Items)
            {
                xb.AddTag("item");
                xb.AddString("Title", item.Title);
                xb.AddString("Description", item.Description);
                xb.AddString("PicUrl", item.PicUrl);
                xb.AddString("Url", item.Url);
                xb.CloseTag("item");
            }
            xb.CloseTag("Articles");
        }
    }

    /// <summary>
    /// 语音消息
    /// </summary>
    public class VoiceMessage : Message
    {
        public string MediaId { get; set; }
        public string Format { get; set; }
        public string Recognition { get; set; }

        public VoiceMessage()
            : base()
        {
            this.MsgType = MsgType.Voice;
        }
    }

    /// <summary>
    /// 视频信息
    /// </summary>
    public class VideoMessage : Message
    {
        public string MediaId { get; set; }
        public string ThumbMediaId { get; set; }

        public VideoMessage()
            : base()
        {
            this.MsgType = MsgType.Video;
        }
    }

    /// <summary>
    /// 地理位置消息
    /// </summary>
    public class LocationMessage : Message
    {
        public string Location_X { get; set; }
        public string Location_Y { get; set; }
        public string Scale { get; set; }
        public string Label { get; set; }

        public LocationMessage()
            : base()
        {
            this.MsgType = MsgType.Location;
        }
    }

    /// <summary>
    /// 链接消息
    /// </summary>
    public class LinkMessage : Message
    {
        public string Title { get; set; }
        public string Description { get; set; }
        public string Url { get; set; }

        public LinkMessage()
            : base()
        {
            this.MsgType = MsgType.Link;
        }
    }


    /// <summary>
    /// 事件推送消息
    /// </summary>
    public class EventMessages : Message
    {
        public EventType EventType { get; set; }

        public EventMessages()
            : base()
        {
            this.MsgType = MsgType.Event;
            this.EventType = EventType.UnKnown;
        }
    }

    /// <summary>
    /// 关注事件消息
    /// </summary>
    public class SubscribeEventMessage : EventMessages
    {
        //扫描二维码关注事件消息时，以下属性有效
        public string EventKey { get; set; }
        public string Ticket { get; set; }

        public SubscribeEventMessage()
            : base()
        {
            this.EventType = EventType.Subscribe;
        }
    }

    /// <summary>
    /// 取消关注事件
    /// </summary>
    public class UnSubscribeEventMessage : EventMessages
    {
        public UnSubscribeEventMessage()
            : base()
        {
            this.EventType = EventType.UnSubscribe;
        }
    }

    /// <summary>
    /// 扫描二维码事件消息 Event = scan
    /// </summary>
    public class ScanEventMessage : EventMessages
    {
        public string EventKey { get; set; }
        public string Ticket { get; set; }

        public ScanEventMessage()
            : base()
        {
            this.EventType = EventType.Scan;
        }
    }

    /// <summary>
    /// 上报地理位置事件消息 Event = LOCATION
    /// </summary>
    public class UploadLocationEventMessage : EventMessages
    {
        public string Latitude { get; set; }
        public string Longitude { get; set; }
        public string Precision { get; set; }

        public UploadLocationEventMessage()
            : base()
        {
            this.EventType = EventType.Location;
        }
    }

    /// <summary>
    /// 自定义菜单事件 Event = CLICK
    /// </summary>
    public class MenuEventMessage : EventMessages
    {
        public string EventKey { get; set; }

        public MenuEventMessage()
            : base()
        {
            this.EventType = EventType.Click;
        }
    }

    [Serializable]
    public class AccessTokenInfo
    {
        private DateTime CreateTime;

        public string access_token { get; set; }
        public int expires_in { get; set; }

        public AccessTokenInfo()
        {
            this.CreateTime = DateTime.Now;
        }

        public string AccessToken
        {
            get
            {
                return this.access_token;
            }
        }

        public bool Expired
        {
            get
            {
                return DateTime.Now > this.CreateTime.AddSeconds(this.expires_in - 100);
            }
        }
    }

    [Serializable]
    public class CallResult
    { 
        public int errcode { get; set; }
        public string errmsg { get; set; }
    }
}
