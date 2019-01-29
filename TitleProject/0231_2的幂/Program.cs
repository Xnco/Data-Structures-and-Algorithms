using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0231_2的幂
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 231_2的幂 
        /*
         给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

        示例 1:
        输入: 1
        输出: true
        解释: 20 = 1

        示例 2:
        输入: 16
        输出: true
        解释: 24 = 16

        示例 3:
        输入: 218
        输出: false
        */
        // 2^n 次方 转换成二进制即 1000...(n个0)
        // 84ms
        static bool IsPowerOfTwo(int n)
        {
            return n > 0 && (n & n - 1) == 0;
        }
        #endregion
    }
}
