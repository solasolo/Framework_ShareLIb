using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Formallor
{
    class Program
    {
        static void Main(string[] args)
        {
            string RootPath;

            if (args.Length > 0)
            {
                RootPath = args[0];

                Solution sln = new Solution(RootPath);
            }

        }
    }
}
