using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0009_回文数
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 9_回文数 
        /*
        判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

        示例 1:
            输入: 121
            输出: true

        示例 2:
            输入: -121
            输出: false
            解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

        示例 3:
            输入: 10
            输出: false
            解释: 从右向左读, 为 01 。因此它不是一个回文数。

        进阶:
            你能不将整数转为字符串来解决这个问题吗？

        */
        // 转换成 string 做 - 200ms - 188ms
        public bool IsPalindrome(int x)
        {
            if (x < 0)
            {
                return false;
            }

            if (x < 10)
            {
                return true;
            }

            if (x % 10 == 0)
            {
                return false;
            }

            string str = x.ToString();
            for (int i = 0; i < str.Length / 2; i++)
            {
                if (str[i] != str[str.Length - 1 - i])
                {
                    return false;
                }
            }
            return true;
        }

        // 不转换成 string 做 - 除了将每一位数字存起来分别对比没有其他思路，感觉和字符串没差
        // 有更好的思路的时候再写
        //public bool IsPalindrome2(int x)
        //{

        //}
        #endregion
    }
}
