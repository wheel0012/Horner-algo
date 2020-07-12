using System;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

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

        private string orgnlCapped;

        private int orgnlCapCursor;

        public Abb()
        {
            this.anchorPos = 0;
            this.cursor = 0;
            this.orgnlCapCursor = 0;
            this.n2bCursor = 0;
        }

        public bool Find(string str, string capStr)
        {
            this.orgnlStr = str;
            this.n2bStr = capStr;
            return this.Process();
        }

        private bool Process()
        {
            this.CollectCapFromOrgnl();

            var target = this.LocateTarget(this.orgnlCapArr, n2bStr);

            var result =  FindInRange(target);
            return result;
        }

        private int[] LocateTarget(int[] aCapedArr, string b)
        {
            var result = Enumerable.Repeat<int>(-1, b.Length).ToArray();

            for (int bC = 0, aC = 0; bC < b.Length; ++bC)
            {
                if (orgnlCapped[aC] == b[bC])
                {
                    result[bC] = aCapedArr[aC];
                    ++aC;
                }
            }

            return result;
        }

        private bool FindInRange(int[] targetArr)
        {
            for (int i = 0; i < targetArr.Length; ++i)
            {
                if (targetArr[i] != -1)
                    continue;

                if (i == 0)
                {

                }
                else if (i == targetArr.Length - 1)
                {

                }
                else
                {
                    var start = targetArr[i - 1];
                    var end = targetArr[i + 1];
                    if (start != -1 && end != -1)
                        if (FindBetween(targetArr, i))
                            continue;
                        else
                            return false;
                }
            }

            return true;
        }

        private bool FindBetween(int[] targetArr, int target)
        {
            int start = targetArr[target - 1];
            int end = targetArr[target + 1];
            int targetCh = this.n2bStr[target];

            for (; start <= end; ++start)
            {
                if (TryMake2Cap(orgnlStr[start]) == targetCh)
                    return true;
            }

            return false;
        }

        /*
        private bool FindLeft()
        {

        }

        private bool FindRight()
        {

        }*/


        private char TryMake2Cap(char ch)
        {
            ch -= (char)0x20;

            return ch;
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
            if (this.orgnlCapCursor < this.orgnlCapArr.Length - 1)
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
            var capped = new StringBuilder();
            for (int i = 0; i < orgnlStr.Length; ++i)
            {
                if (IsCap(orgnlStr[i]))
                {
                    capList.Add(i);
                    capped.Append(orgnlStr[i]);
                }
            }

            this.orgnlCapped = capped.ToString();
            this.orgnlCapArr = capList.ToArray();
        }
    }

}