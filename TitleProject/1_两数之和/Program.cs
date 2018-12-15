using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_两数之和
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = TwoSum(new int[] { 2, 7, 11, 15 }, 9);
            Console.WriteLine(a.Length);
        }

        #region 1.两数之和 (简单)
        /*
         给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
        你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
        */
        static int[] TwoSum(int[] nums, int target)
        {
            // 暴力
            //for (int i = 0; i < nums.Length; i++)
            //{
            //    for (int j = i + 1; j < nums.Length; j++)
            //    {
            //        if (nums[i] + nums[j] == target)
            //        {
            //            return new int[] { i, j };
            //        }
            //    }
            //}
            //return null;

            // 一遍哈希表
            Dictionary<int, int> numDic = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                int complement = target - nums[i];
                if (numDic.ContainsKey(complement))
                {
                    return new int[] { numDic[complement], i };
                }

                if (!numDic.ContainsKey(nums[i]))
                {
                    numDic.Add(nums[i], i);
                }

            }
            return null;
        }
        #endregion
    }
}
