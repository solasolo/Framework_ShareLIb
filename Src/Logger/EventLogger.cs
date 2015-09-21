using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace GLEO.OA.System
{
    class EventLoggerWriter : LoggerWriter
    {
        IDictionary<MessageType, EventLogEntryType> EventTypeMap;

        public EventLoggerWriter()
        { 
            this.EventTypeMap = new Dictionary<MessageType, EventLogEntryType>();

            this.EventTypeMap.Add(MessageType.Information, EventLogEntryType.Information);
            this.EventTypeMap.Add(MessageType.Message, EventLogEntryType.Information);
            this.EventTypeMap.Add(MessageType.Warning, EventLogEntryType.Warning);
            this.EventTypeMap.Add(MessageType.Error, EventLogEntryType.Error);
            this.EventTypeMap.Add(MessageType.Trace, EventLogEntryType.Information);
            this.EventTypeMap.Add(MessageType.Debug, EventLogEntryType.Information);
        }

        public override void Log(LogInfo[] infos)
        {
            foreach (LogInfo li in infos)
            {
                EventLog.WriteEntry(li.ModuleName, li.ToString(), this.EventTypeMap[li.Type]);
            }
        }
    }
}
