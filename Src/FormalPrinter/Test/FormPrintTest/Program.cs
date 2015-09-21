using GLEO.Utility;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FormPrintTest
{
    class Program
    {
        class TestObject
        {
            public string T1 { get; set; }
            public string T2 { get; set; }
            public string T3 { get; set; }
        }
        
        static void Main(string[] args)
        {
            FormalPrint print = new FormalPrint(@"f:\Works\山弈重工\BaotouSteel\Lib\FormalPrinter\Test\FormTest.xml");

            TestObject to = new TestObject();
            to.T1 = "Hello World";
            to.T2 = "MNI 叶问";
            to.T3 = "1234一二三四";

            print.Print(to);
        }
    }
}
