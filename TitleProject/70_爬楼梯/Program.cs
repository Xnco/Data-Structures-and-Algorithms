using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _70_爬楼梯
{
    class Program
    {
        /* 
        70 - 爬楼梯问题

        假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
        每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
        注意：给定 n 是一个正整数。

        示例 1：
        输入： 2
        输出： 2
        解释： 有两种方法可以爬到楼顶。
        1.  1 阶 + 1 阶
        2.  2 阶

        示例 2：
        输入： 3
        输出： 3
        解释： 有三种方法可以爬到楼顶。
        1.  1 阶 + 1 阶 + 1 阶
        2.  1 阶 + 2 阶
        3.  2 阶 + 1 阶
        */

        static void Main(string[] args)
        {
            Console.WriteLine(ClimbStairs_Recursive(2));
        }

        // 不用递归做， 因为这种时候递归会重复计算，效率低 Leetcode 68ms
        static int ClimbStairs(int n)
        {
            //if (n == 1) return 1; // 防止n=1时，dp[2] = 2下标越界

            //int[] dp = new int[n + 1];
            //dp[1] = 1;
            //dp[2] = 2;

            //for (int i = 3; i <= n; i++)
            //{
            //    dp[i] = dp[i - 1] + dp[i - 2];
            //}
            //return dp[n];

            int stepDecTwo = 1, stepDecOne = 1, steps = 1;

            for (int i = 2; i <= n; i++)
            {
                steps = stepDecTwo + stepDecOne;
                stepDecTwo = stepDecOne;
                stepDecOne = steps;
            }

            return steps;
        }

        // 递归 - Leetcode 超出时间限制
        static int ClimbStairs_Recursive(int n)
        {
            if (n == 0 || n == 1)
            {
                return 1;
            }

            return ClimbStairs_Recursive(n - 1) + ClimbStairs_Recursive(n - 2);
        }
    }
}
