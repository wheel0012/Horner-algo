using System;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;

namespace Abbreviation
{
    class Abb
    {
        public string orgnlStr;

        public string n2bStr;

        private int anchorPos;

        private int cursor;

        private int n2bCursor;

        private int[] orgnlCapArr;

        private int orgnlCapCursor;

        public Abb()
        {
            this.orgnlStr = orgnlStr;
            this.n2bStr = n2bStr;
            this.anchorPos = 0;
            this.cursor = 0;
            this.orgnlCapCursor = 0;
            this.n2bCursor = 0;
        }

        public string Find(string str, string capStr)
        {
            this.orgnlStr = str;
            this.n2bStr = capStr;
            return this.Process();
        }

        private string Process()
        {
            this.CollectCapFromOrgnl();

                var a = new StringBuilder();
            while (n2bCursor < n2bStr.Length)
            {

                if (n2bStr[n2bCursor] == orgnlStr[
                    orgnlCapArr[orgnlCapCursor]
                    ])
                {
                    this.N2BMoveNext();

                    this.OrgnlCapMoveNext();

                    a.Append(orgnlStr[
                    orgnlCapArr[orgnlCapCursor]
                    ]);
                }
                else
                {
                    a.Append('x');
                    orgnlCapCursor++;
                }
            }

            return a.ToString();
        }

        private bool FindCap()
        {
            for (int i = 0; i < cursor; ++this.anchorPos)
            {
                var ch = this.orgnlStr[i];
                if (TryMake2Cap(ref ch))
                {
                    if (this.n2bStr[n2bCursor] == ch)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            return false;
        }

        private bool TryMake2Cap(ref char ch)
        {
            if (ch < 0x7b && ch > 0x60)
            {
                ch -= (char)0x20;

                return true;
            }
            else
            {
                return false;
            }
        }

        private bool IsCap(char ch)
        {
            if (ch < 0x5B && ch > 0x40)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private bool N2BMoveNext()
        {
            if (this.n2bCursor < this.n2bStr.Length)
            {
                ++this.n2bCursor;

                return true;
            }
            else
            {
                return false;
            }
        }


        private bool MoveNext()
        {
            if (this.cursor < this.orgnlStr.Length)
            {
                ++this.cursor;

                return true;
            }
            else
            {
                return false;
            }
        }

        private bool OrgnlCapMoveNext()
        {
            if (this.orgnlCapCursor < this.orgnlCapArr.Length)
            {
                ++this.orgnlCapCursor;

                return true;
            }
            else
            {
                return false;
            }
        }

        private void CollectCapFromOrgnl()
        {
            var capList = new List<int>();
            for (int i = 0; i < orgnlStr.Length; ++i)
            {
                if (IsCap(orgnlStr[i]))
                {
                    capList.Add(orgnlStr[i]);
                }
            }

            this.orgnlCapArr = capList.ToArray();
        }
    }
}