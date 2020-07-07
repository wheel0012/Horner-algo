using System;
using System.Diagnostics;

using Abbreviation;

namespace Abbreviation
{
    public class Program
    {
        static void Main()
        {
            var abb = new Abb();
            Trace.WriteLine("sd");
            Console.WriteLine(abb.Find("asdAAsdD", "AASD"));
        }
    }
}