using System;
using System.Collections.Generic;
using System.Text;

namespace Abbreviation
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int temp = 0;
            temp = Convert.ToInt32(Console.ReadLine());
            Abbreviater instance = new Abbreviater();
            Queue<string> str_a = new Queue<string>();
            Queue<string> str_b = new Queue<string>();
            for (int i = 0; i < temp; i++)
            {
                str_a.Enqueue(Console.ReadLine());
                str_b.Enqueue(Console.ReadLine());
                Console.WriteLine(instance.Abbreviate(str_a.Dequeue(), str_b.Dequeue()));
            }
        }

    }
    class Abbreviater
    {
        public Abbreviater()
        {
        }
        public int[] CmpEachStr(byte[] a, byte[] b)
        {
            List<int> result = new List<int>();
            if(a.Length==0||b.Length==0)return result.ToArray();
            int a_anchor = 0;
            for (int i = 0; i < b.Length; i++)
            {
                //Console.WriteLine(a_anchor+"__"+i);
                if (a[a_anchor] == b[i])
                {
                    a_anchor++;
                    result.Add(i);
                    if (a_anchor == a.Length) return result.ToArray();
                }
            }
            return result.ToArray();
        }
        public bool Compare(byte[] a, byte[] b)
        {
            if (a.Length == b.Length)
            {
                for (int i = 0; i < a.Length; i++)
                    if (a[i] != b[i]) return false;
                return true;
            }
            return false;
        }
        public string Abbreviate(string a, string b)
        {
            bool result = false;
            byte[] a_barr = Encoding.ASCII.GetBytes(a);
            byte[] b_barr = Encoding.ASCII.GetBytes(b);
            if (a.Length >= b.Length)
            {
                List<int> a_cap = new List<int>();
                List<int> a_small = new List<int>();
                List<byte> a_caped = new List<byte>();
                for (int i = 0; i < a_barr.Length; i++)
                    if (a_barr[i] < 97) a_cap.Add(i);
                    else a_small.Add(i);
                for (int i = 0; i < a_cap.Count; i++)
                    a_caped.Add(a_barr[a_cap[i]]);
                foreach (char temp in a_caped) Console.WriteLine(temp.ToString());
                Console.WriteLine("---");
                foreach (char v in b_barr)
                    Console.WriteLine(v.ToString());
                Console.WriteLine("------");
                if (Compare(a_caped.ToArray(), b_barr))
                   return "YES";
                else
                {
                    if (b_barr.Length <= a_cap.Count) return "NO";
                    //TODO: NEED TO CHECK a2bIndex 
                    int[] a2bIndex = CmpEachStr(a_caped.ToArray(), b_barr);
                    Console.WriteLine("####");
                    foreach(int i in a2bIndex)Console.WriteLine(i);
                    if(a2bIndex.Length == 0)
                    {
                        int b_anchor = 0;
                        for (int i = 0; i < a_small.Count; i++)
                        {
                            if ((a_barr[i] - 32) == b_barr[b_anchor]) b_anchor++;
                        }
                        if (b_anchor < b_barr.Length) return "NO";
                        else return "YES";
                    }
                    {
                        int b_anchor = 0;
                        for (int i = 0; i < a2bIndex[0]; i++)
                        {
                            if ((a_barr[i] - 32) == b_barr[b_anchor]) b_anchor++;
                        }
                        if (b_anchor < a2bIndex[0]) {Console.WriteLine("##"); return "NO";}
                    }
                        
                        for (int i = 1; i < a2bIndex.Length; i++)
                        {
                            int b_anchor = 0;
                            Console.WriteLine("@@@@");
                            Console.WriteLine(a2bIndex[i-1]);
                            Console.WriteLine(a2bIndex[i]);
                            for (int j = a2bIndex[i-1]; j >= a2bIndex[i-1]&&j<a2bIndex[i]; j++)
                            {
                                if ((a_barr[i] - 32) == b_barr[b_anchor]) b_anchor++;
                                Console.WriteLine(a_barr[i].ToString() +":" + b_barr[b_anchor].ToString());
                            }
                            for(int j = a2bIndex[a2bIndex.Length-1]; j < b_barr.Length; j++)
                            {

                            }
                            Console.WriteLine("@@@@@@");
                            if (b_anchor < a2bIndex[i]) return "NO";
                        }
                    return "YES";
                    //int lastIndex = 0;
                }
                /*
                List<int> a_after = new List<int>();
                int b_temp = 0;
                for(int j = 0; j<a.Length; j++)
                {
                    if(a_barr[j] < 97||(a_barr[j]-32) == b_barr[b_temp]||a_barr[j] == b_barr[b_temp])a_after.Add(j);
                    if(a_barr[j] == b_barr[b_temp] || (a_barr[j]-32) == b_barr[b_temp])
                    {
                        if(b_temp <b.Length-1)b_temp++;
                    }

                    //else if(b_temp<b.Length-1)b_temp = 0;
                }
                
                b_temp++;
                int checkChar = 0;
                Console.WriteLine("A-AFTER: "+a_after.Count);
                Console.WriteLine("B-TEMP: "+b_temp);
                
                if(b_temp>=b.Length&&a_after.Count == b.Length)result = true;
                for(int j = b_temp; j< a.Length; j++)
                {
                    if(a_barr[j] >96)result = false;
                }
                */
            }
            if (result) return "YES";
            else return "NO";
        }
    }
}
