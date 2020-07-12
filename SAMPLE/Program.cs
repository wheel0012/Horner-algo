using System;

namespace Abbreviation
{
    public class Program
    {
        static void Main()
        {
            var abb = new Abb();
            Console.WriteLine(abb.Find("asdAAsdD", "AASD"));
            Console.ReadLine();
        }
    }
}