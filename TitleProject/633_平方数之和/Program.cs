using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _633_平方数之和
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(JudgeSquareSum(2147483645));
        }

        #region 633_平方数之和
        /*
            给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
        */
        static bool JudgeSquareSum(int c)
        {
            int max = (int)Math.Sqrt(c);
            for (int i = 0; i <= max; i++)
            {
                int b = c - i * i;
                if (Math.Sqrt(b) % 1 == 0)
                {
                    return true;
                }
            }
            return false;
        }
        #endregion
    }
}
