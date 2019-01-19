using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0414_第三大的数
{
    /*
    给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

    示例 1:
    输入: [3, 2, 1]
    输出: 1
    解释: 第三大的数是 1.

    示例 2:
    输入: [1, 2]
    输出: 2
    解释: 第三大的数不存在, 所以返回最大的数 2 .

    示例 3:
    输入: [2, 2, 3, 1]
    输出: 1
    解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
    存在两个值为2的数，它们都排第二。
    */
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ThirdMax(new int[] { 1, 2, int.MinValue })); 
        }

        // 三个循环 - 无脑解法， 先找出最大的，再找第二大， 再找第三大。没有第三大就返回最大啊
        // 最快 144ms
        public static int ThirdMax(int [] nums)
        {
            int first = int.MinValue, second = int.MinValue, third = int.MinValue;
            bool hasThird = false;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > first)
                {
                    first = nums[i];
                } 
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > second && nums[i] != first)
                {
                    second = nums[i];
                }
            }
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] >= third && nums[i] != first && nums[i] != second)
                {
                    hasThird = true; // 只要执行这句，说明有第三大的值
                    third = nums[i];
                }
            }
            return hasThird ? third : first;
        }
    }
}
