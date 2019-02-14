using System;

public class Class1
{
	public Class1()
	{
        Generate(5);
    }
    #region 118_杨辉三角 
    /*
    给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
    在杨辉三角中，每个数是它左上方和右上方的数的和。

    示例:
    输入: 5
    输出:
    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]
    */
    // 328ms
    static IList<IList<int>> Generate(int numRows)
    {
        List<IList<int>> result = new List<IList<int>>();
        if (numRows == 0)
        {
            return result;
        }
        result.Add(new List<int>() { 1 });
        if (numRows == 1)
        {
            return result;
        }
        result.Add(new List<int>() { 1, 1 });
        for (int i = 3; i < numRows; i++)
        {
            List<int> single = new List<int>();
            single.Add(1);
            for (int j = 1; j < i - 1; j++)
            {
                single.Add(result[i - 2][j - 1] + result[i - 2][j]);
            }
            single.Add(1);
            result.Add(single);
        }
        return result;
    }
    #endregion
}
