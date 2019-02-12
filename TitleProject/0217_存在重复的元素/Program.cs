using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0217_存在重复的元素
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 217_存在重复的元素 
        /*
        给定一个整数数组，判断是否存在重复元素。
        如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

        示例 1:
        输入: [1,2,3,1]
        输出: true

        示例 2:
        输入: [1,2,3,4]
        输出: false

        示例 3:
        输入: [1,1,1,3,3,4,3,2,4,2]
        输出: true
        */
        // 216ms
        // 先排序 - 相邻相等就返回 true
        static bool ContainsDuplicate(int[] nums)
        {
            Array.Sort(nums);

            for (int i = 0; i < nums.Length - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    return true;
                }
            }
            return false;
        }

        // 180ms
        // 用 Dictionary 存, 重复就true 
        static bool ContainsDuplicate2(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(nums[i]))
                {
                    return true;
                }
                else
                {
                    dic.Add(nums[i], 0);
                }
            }
            return false;
        }

        // 超出时间限制了， List效率太低
        // 用list判断
        static bool ContainsDuplicate3(int[] nums)
        {
            List<int> list = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (list.Contains(nums[i]))
                {
                    return true;
                }
                else
                {
                    list.Add(nums[i]);
                }
            }
            return false;
        }
        #endregion
    }
}
