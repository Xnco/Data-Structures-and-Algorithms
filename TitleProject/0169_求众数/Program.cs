using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0169_求众数
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 169_求众数(Majority)
        /*
        给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
        你可以假设数组是非空的，并且给定的数组总是存在众数。

        示例 1:
            输入: [3,2,3]
            输出: 3

        示例 2:
            输入: [2,2,1,1,1,2,2]
            输出: 2
        */
        // 常规做法，记录所有数出现的次数，返回最大的
        // 208 ms
        public int MajorityElement(int[] nums)
        {
            Dictionary<int, int> allNumber = new Dictionary<int, int>();
            int maxKey = nums[0];
            for (int i = 0; i < nums.Length; i++)
            {
                int tmpKey = nums[i];
                if (allNumber.ContainsKey(tmpKey))
                {
                    allNumber[tmpKey]++;
                }
                else
                {
                    allNumber.Add(tmpKey, 1);
                }

                if (allNumber[tmpKey] > allNumber[maxKey])
                {
                    maxKey = tmpKey;
                }
            }
            return maxKey;
        }

        // 摩尔投票法 - 两两抵消，剩者为王 - 200ms
        public int MajorityElement2(int[] nums)
        {
            // 默认从第一个开始
            int majority = 0;
            int score = 0;

            for (int i = 0; i < nums.Length; i++)
            {

                if (score == 0)
                {
                    // 如果当前 score 为0， 说明前面的数相全部抵消了，就从新开始计算
                    majority = nums[i];
                    score = 1;
                }
                else if (nums[i] == majority)
                {
                    // 如果一个数和当前 majority 相同计数器++
                    score++;
                }
                else
                {
                    // 如果一个数和当前 majority 不同计数器--
                    score--;
                }
            }
            return majority;
        }
        #endregion
    }
}
