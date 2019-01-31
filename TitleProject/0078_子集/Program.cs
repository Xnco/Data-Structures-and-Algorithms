using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0078_子集
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 78_子集 
        /*
        给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
        说明：解集不能包含重复的子集。

        示例:
        输入: nums = [1,2,3]
        输出:
        [
          [3],
          [1],
          [2],
          [1,2,3],
          [1,3],
          [2,3],
          [1,2],
          []
        ]
        */
        // 每多一个数就在现有的基础上全部 + 1 - 380ms 击败67%
        static IList<IList<int>> Subsets(int[] nums)
        {
            List<IList<int>> result = new List<IList<int>>();
            result.Add(new List<int>()); // 空集

            for (int i = 0; i < nums.Length; i++)
            {
                AddNum(result, nums[i]);
            }

            return result;
        }

        static void AddNum(List<IList<int>> result, int num)
        {
            List<IList<int>> list = new List<IList<int>>();
            for (int i = 0; i < result.Count; i++)
            {
                List<int> tmp = new List<int>(result[i]);
                tmp.Add(num);
                list.Add(tmp);
            }

            result.AddRange(list);
        }
        #endregion
    }
}
