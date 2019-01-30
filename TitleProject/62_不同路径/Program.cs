using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _62_不同路径
{
    class Program
    {
        static void Main(string[] args)
        {
            UniquePaths(36, 7);
        }

        #region 62_不同路径 
        /*
        一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

        机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

        问总共有多少条不同的路径？

        示例 1:
        输入: m = 3, n = 2
        输出: 3
        解释:
        从左上角开始，总共有 3 条路径可以到达右下角。
        1. 向右 -> 向右 -> 向下
        2. 向右 -> 向下 -> 向右
        3. 向下 -> 向右 -> 向右

        示例 2:
        输入: m = 7, n = 3
        输出: 28
        */

        // 72ms
        // 组合问题 m + n 的网格，走到右下角要 m + n - 2 步，其中 m - 1 步是横着走的
        // 所以结果是 C(m+n-2, m-1) 
        static int UniquePaths(int m, int n)
        {
            if (n < m)
            {
                int x = n;
                n = m;
                m = x;
            }

            long sum1 = Times(n, n + m - 2);
            long sum2 = Times(1, m - 1);
            return (int)(sum1 / sum2);

            //int sum1 = Times(1, n + m - 2);
            //int sum2 = Times(1, m - 1);
            //int sum3 = Times(1, n - 1);
            //return sum1 / (sum2 * sum3);
        }

        static long Times(long x, long y)
        {
            long result = 1;
            while (x <= y)
            {
                result *= x;
                x++;
            }
            return result;
        }
        #endregion
    }
}
