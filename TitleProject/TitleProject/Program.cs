using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TitleProject
{
    class Program
    {
        static void Main(string[] args)
        {
            
        }

        #region 0 
        /*
         
        */
        static void Func()
        {

        }
        #endregion
        #region 1.两数之和 (简单)
        /*
         给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
        你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
        */
        static int[] TwoSum(int[] nums, int target)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return new int[] {i, j };
                    }
                }
            }
            return null;
        }
        #endregion

        #region 771. 宝石和石头 (简单)
        /*
          给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
        J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。 
        */
        static int NumJewelsInStones(string J, string S)
        {
            // 暴力
            int num = 0;
            for (int i = 0; i < S.Length; i++)
            {
                for (int j = 0; j < J.Length; j++)
                {
                    if (S[i] == J[ j ])
                    {
                        num++;
                    }
                }
            }
            return num;
        }
        #endregion 

        #region 807. 保持城市天际线 (中等)
        /*
            在二维数组grid中，grid[i][j]代表位于某处的建筑物的高度。 我们被允许增加任何数量（不同建筑物的数量可能不同）的建筑物的高度。 高度 0 也被认为是建筑物。
            最后，从新数组的所有四个方向（即顶部，底部，左侧和右侧）观看的“天际线”必须与原始数组的天际线相同。 
            城市的天际线是从远处观看时，由所有建筑物形成的矩形的外部轮廓。 请看下面的例子。
            建筑物高度可以增加的最大总和是多少？ 
            例子：
            输入： grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
            输出： 35
            解释： 
            The grid is:
            [ [3, 0, 8, 4], 
              [2, 4, 5, 7],
              [9, 2, 6, 3],
              [0, 3, 1, 0] ]
            从数组竖直方向（即顶部，底部）看“天际线”是：[9, 4, 8, 7]
            从水平水平方向（即左侧，右侧）看“天际线”是：[8, 7, 9, 3]
            在不影响天际线的情况下对建筑物进行增高后，新数组如下：
            gridNew = [ [8, 4, 8, 7],
                                [7, 4, 7, 7],
                                [9, 4, 8, 7],
                                [3, 3, 3, 3] ]
         */
        static int MaxIncreaseKeepingSkyline(int[][] grid)
        {
            int num = 0;
            // 暴力
            for (int i = 0; i < grid.Length; i++)
            {
                for (int j = 0; j < grid[i].Length; j++)
                {
                    // 先找到一行中最大的数
                    int maxRow = grid[i][0];
                    for (int k = 1; k < grid[i].Length; k++)
                    {
                        if (grid[i][k] > maxRow)
                        {
                            maxRow = grid[i][k];
                        }
                    }

                    // 再找一列中的最大数
                    int maxCol = grid[0][j];
                    for (int k = 1; k < grid[j].Length; k++)
                    {
                        if (grid[k][j] > maxCol)
                        {
                            maxCol = grid[k][j];
                        }
                    }

                    // 行列上两个最大值中取小的, 就是增长的最大值
                    int max = maxRow < maxCol ? maxRow : maxCol;
                    num += max - grid[i][j];
                    grid[i][j] = max;
                }
            }
            return num;
        }
        #endregion
    }
}