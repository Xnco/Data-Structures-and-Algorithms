using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0136_只出现一次的数字
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 136_只出现一次的数字
        /*
        给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
        说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

        示例 1:
            输入: [2,2,1]
            输出: 1

        示例 2:
            输入: [4,1,2,1,2]
            输出: 4
        */
        // 常规做法， 使用了额外的开销 -180ms
        public static int SingleNumber(int[] nums)
        {
            Dictionary<int, int> all = new Dictionary<int, int>();
            foreach (var item in nums)
            {
                if (all.ContainsKey(item))
                {
                    all[item]++;
                }
                else
                {
                    all.Add(item, 1);
                }
            }

            foreach (var item in all)
            {
                if (item.Value == 1)
                {
                    return item.Key;
                }
            }
            return 0;
        }

        // 亦或做法 ^ - 184ms -- 更慢了也是够了
        // 两个相同的数异或结果为0。 
        public static int SingleNumber2(int[] nums)
        {
            int single = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                single = single ^ nums[i];
            }
            return single;
        }

        #endregion
    }
}
