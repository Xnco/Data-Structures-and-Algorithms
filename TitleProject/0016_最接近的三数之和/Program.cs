using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0016_最接近的三数之和
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 16 最接近的三数之和 
        /*
         给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

        例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
            与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
        */

        // 176ms 击败68%
        // 和15题雷同，找到和target之间的最小偏移量即可
        public int ThreeSumClosest(int[] nums, int target)
        {
            Array.Sort(nums);
            int minOffset = int.MaxValue; // 最小差值
            for (int i = 0; i < nums.Length; i++)
            {
                // 判断重复 i 重复就只做一次作用, 这种逻辑建立在数字排好序的情况下
                //if (numi == nums[i])
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int numi = nums[i];
                int j = i + 1;
                int k = nums.Length - 1;
                while (j < k)
                {
                    int numj = nums[j];
                    int numk = nums[k];
                    int sum = numi + numj + numk;
                    int offset = sum - target;
                    if (Math.Abs(offset) < Math.Abs(minOffset))
                    {
                        minOffset = offset; // 更新最小插值
                    }
                    if (offset > 0) // 三数和比0要大， 说明后面的数太大
                    {
                        k--;
                    }
                    else if (offset < 0)
                    {
                        j++;
                    }
                    else
                    {
                        return target;
                    }
                }
            }
            return target + minOffset;
        }
        #endregion
    }
}
