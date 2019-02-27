using System;

public class Class1
{
	public Class1()
	{
        Combine(4, 2);
    }

    #region 77_组合 
    /*
    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
    示例:
    输入: n = 4, k = 2
    输出:
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
    */
    // 1076ms, 113MB, 就是多次迭代
    static IList<IList<int>> Combine(int n, int k)
    {
        List<IList<int>> result = new List<IList<int>>();
        // 第一次 n - k + 1 个数字都加进去
        for (int i = 1; i <= n - k + 1; i++)
        {
            List<int> tmp = new List<int>();
            tmp.Add(i);
            result.Add(tmp);
        }

        for (int i = 0; i < k - 1; i++)
        {
            result = Add(result, n);
        }
        return result;
    }

    static List<IList<int>> Add(List<IList<int>> result, int n)
    {
        List<IList<int>> newResult = new List<IList<int>>();
        for (int i = 0; i < result.Count; i++)
        {
            IList<int> tmp = result[i];
            for (int j = tmp[tmp.Count - 1] + 1; j <= n; j++)
            {
                List<int> newTemp = new List<int>(tmp);
                newTemp.Add(j);
                newResult.Add(newTemp);
            }
        }
        return newResult;
    }
    #endregion
}
