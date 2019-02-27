using System;

public class Class1
{
	public Class1()
	{
        Permute2(new int[3] { 1, 2, 3 });
    }

    #region 46_全排列 
    /*
    给定一个没有重复数字的序列，返回其所有可能的全排列。
    示例:
    输入: [1,2,3]
    输出:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
    ]
    */
    // 400ms, 29.7MB
    // 每有一个新的数字就插入到老的集合中， [1] -> [1,2], [2,1] -> [3,1,2], [1,3,2], [1,2,3], [3,2,1], [2,3,1], [2,1,3]
    static IList<IList<int>> Permute(int[] nums)
    {
        List<IList<int>> result = new List<IList<int>>();
        for (int i = 0; i < nums.Length; i++)
        {
            Insert(result, nums[i]);
        }
        return result;
    }

    static void Insert(List<IList<int>> result, int num)
    {
        if (result.Count == 0)
        {
            // 第一个数
            List<int> init = new List<int>();
            init.Add(num);
            result.Add(init);
            return;
        }
        List<IList<int>> all = new List<IList<int>>();
        for (int i = 0; i < result.Count; i++)
        {
            for (int j = 0; j < result[i].Count; j++)
            {
                List<int> tmp = new List<int>(result[i]);
                tmp.Insert(j, num);
                all.Add(tmp);
            }
            result[i].Add(num);
        }
        result.AddRange(all);
    }

    // 652ms, 30.4MB 
    // 显然，这种算法无论是时间还是空间都不如第一种 XD
    // 算法2，直接遍历 [1], [2], [3] -> [1,2], [1,3], [2,1], [2,3], [3,1], [3,2] -> [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
    static IList<IList<int>> Permute2(int[] nums)
    {
        List<IList<int>> result = new List<IList<int>>();
        // 第一次将三个数字都加进去
        for (int i = 0; i < nums.Length; i++)
        {
            List<int> tmp = new List<int>();
            tmp.Add(nums[i]);
            result.Add(tmp);
        }

        // 每次循环都加一个数即可
        for (int i = 0; i < nums.Length - 1; i++)
        {
            result = Add(result, nums);
        }
        return result;
    }

    static List<IList<int>> Add(List<IList<int>> result, int[] nums)
    {
        List<IList<int>> newResult = new List<IList<int>>();
        for (int i = 0; i < result.Count; i++)
        {
            for (int j = 0; j < nums.Length; j++)
            {
                if (!result[i].Contains(nums[j]))
                {
                    List<int> tmp = new List<int>(result[i]);
                    tmp.Add(nums[j]);
                    newResult.Add(tmp);
                }
            }
        }
        return newResult;
    }
    #endregion
}
