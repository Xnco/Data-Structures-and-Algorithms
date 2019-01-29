using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0053_最大子序和
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 53_最大子序和 
        /*
        给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

        示例:
        输入: [-2,1,-3,4,-1,2,1,-5,4],
        输出: 6
        解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

        进阶:
        如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

        */
        // 算法1：暴力法，将所有子序的可能性全部算出，得到最大值
        // 复杂度 O(N²) - 1156ms
        static int MaxSubArray(int[] nums)
        {
            int maxSum = int.MinValue;
            for (int i = 0; i < nums.Length; i++)
            {
                int sum = 0;
                for (int j = i; j < nums.Length; j++)
                {
                    sum += nums[j];
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                    }
                }
            }
            return maxSum;
        }

        // 算法2：分治法
        //static int MaxSubArray2(int[] nums)
        //{

        //}

        // 算法3 - O(N)
        // 弊端在于如果数组中的数字全是负数就会错误
        static int MaxSubArray3(int[] nums)
        {
            if (nums.Length == 1)
            {
                return nums[0];
            }
            int thisSum = 0;
            int maxSum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                thisSum += nums[i];

                if (thisSum > maxSum)
                {
                    maxSum = thisSum;
                }
                else if (thisSum < 0)
                {
                    thisSum = 0;
                }
            }
            return maxSum;
        }
        #endregion
    }
}
