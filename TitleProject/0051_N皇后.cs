using System;
using System.Collections;
using System.Collections.Generic;

public class Class1
{
	public Class1()
	{
        var temp = SolveNQueens(5);

        Console.WriteLine(temp.Count);
        foreach (var item in temp)
        {
            foreach (var line in item)
            {
                Console.WriteLine(line);
            }
            Console.WriteLine();
        }
    }

    #region 51_n皇后
    /*
    n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    上图为 8 皇后问题的一种解法。
    给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
    每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

    示例:
    输入: 4
    输出: [
     [".Q..",  // 解法 1
      "...Q",
      "Q...",
      "..Q."],
     ["..Q.",  // 解法 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
    解释: 4 皇后问题存在两个不同的解法。
    */
    // 回溯算法 - 436ms
    static IList<IList<string>> SolveNQueens(int n)
    {
        bool[,] map = new bool[n, n];
        List<IList<string>> result = new List<IList<string>>();
        List<string> single = new List<string>();
        SetQueen(map, 0, n, result);
        return result;
    }

    // 递归
    static void SetQueen(bool[,] map, int line, int n, List<IList<string>> result)
    {
        if (line == n)
        {
            return;
        }
        for (int i = 0; i < n; i++)
        {
            // 判断该位置能不能放皇后
            if (!canSetQueen(map, line, i))
            {
                continue;
            }

            map[line, i] = true; // 放一个皇后
            if (line == n - 1)
            {
                // 最后一行如果还能放皇后，说明符合条件，保存一个解法
                List<string> single = CreateResultByMap(map, n);
                result.Add(single);
            }
            else
            {
                // 没到最后一行就继续放下一行的皇后
                SetQueen(map, line + 1, n, result);
            }
            map[line, i] = false; // 拿起该皇后
        }
    }

    // 根据地图生成解法
    static List<string> CreateResultByMap(bool[,] map, int n)
    {
        List<string> single = new List<string>();
        for (int i = 0; i < n; i++)
        {
            string line = "";
            for (int j = 0; j < n; j++)
            {
                line += map[i, j] ? "Q" : ".";
            }
            single.Add(line);
        }
        return single;
    }

    // 是否能放置皇后 - 每次放置都要判断是否满足，很多重复的计算
    static bool canSetQueen(bool[,] map, int x, int y)
    {
        // 上方， 左上方，右上方 三个方向不能有棋子
        for (int i = 1; i <= x; i++)
        {
            if ((map[x - i, y])
                || (y - i >= 0 && map[x - i, y - i])
                || (y + i < map.GetLength(1) && map[x - i, y + i]))
            {
                return false;
            }

        }
        // 没有符合条件的就可以放置皇后
        return true;
    }
    #endregion
}
