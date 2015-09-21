using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GLEO.UI
{
    public interface IVerifiable
    {
        bool Verify();
    }

    public enum VerifyType
    {
        None,
        String,
        Integer,
        Float,
        DateTime, //YYYY-MM-DD hh:mm:ss
        Date, //YYYY-MM-DD

        Customer,
    };

    public class Verification
    {
        public bool Required { get; set; }
        public VerifyType Type { get; set; }
        public string CustomerRule { get; set; }

        public override string ToString()
        {
            return this.Type.ToString();
        }

        public bool Verify(string text)
        {
            bool Result = true;

            if (text != null)
            {
                text = text.Trim();
            }
            
            string RegularExpressions = "";
            switch (this.Type)
            {
                case VerifyType.String:
                    RegularExpressions = "^[A-Za-z0-9\u4E00-\u9FA5]+$";
                    break;

                case VerifyType.Integer:
                    RegularExpressions = "^-?\\d+$";
                    break;

                case VerifyType.Float:
                    RegularExpressions = "^(-?\\d+)(\\.\\d+)?$";
                    break;

                case VerifyType.Date:
                    RegularExpressions = "(([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3})-(((0[13578]|1[02])-(0[1-9]|[12][0-9]|3[01]))|((0[469]|11)-(0[1-9]|[12][0-9]|30))|(02-(0[1-9]|[1][0-9]|2[0-8]))))|((([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00))-02-29)";
                    break;

                case VerifyType.DateTime:
                    RegularExpressions = "^(?:(?!0000)[0-9]{4}-(?:(?:0[1-9]|1[0-2])-(?:0[1-9]|1[0-9]|2[0-8])|(?:0[13-9]|1[0-2])-(?:29|30)|(?:0[13578]|1[02])-31)|(?:[0-9]{2}(?:0[48]|[2468][048]|[13579][26])|(?:0[48]|[2468][048]|[13579][26])00)-02-29)\\s+([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$";
                    break;

                case VerifyType.Customer:
                    RegularExpressions = this.CustomerRule;
                    break;
            }

            if (!String.IsNullOrEmpty(text))
            {
                if(!String.IsNullOrEmpty(RegularExpressions))
                {
                    Match match = Regex.Match(text, RegularExpressions);
                    Result = match.Success;
                }
            }
            else
            {
                if(this.Required)
                {
                    Result = false;
                }
            }

            return Result;
        }
    }
}
