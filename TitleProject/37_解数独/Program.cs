using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _37_解数独
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now.Millisecond);
            char[,] test = new char[9, 9]
            {
                { '5', '3', '.', '.', '7', '.','.','.','.'},
                { '6', '.', '.', '1', '9', '5','.','.','.'},
                { '.', '9', '8', '.', '.', '.','.','6','.'},

                { '8', '.', '.', '.', '6', '.','.','.','3'},
                { '4', '.', '.', '8', '.', '3','.','.','1'},
                { '7', '.', '.', '.', '2', '.','.','.','6'},

                { '.', '6', '.', '.', '.', '.','2','8','.'},
                { '.', '.', '.', '4', '1', '9','.','.','5'},
                { '.', '.', '.', '.', '8', '.','.','7','9'},
            };
            new Solution().SolveSudoku(test);

            for (int i = 0; i < test.GetLength(0); i++)
            {
                for (int j = 0; j < test.GetLength(1); j++)
                {
                    Console.Write(test[i, j]);
                    Console.Write(" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine(DateTime.Now.Millisecond);
            Console.ReadKey();
        }

        #region 37. 解数独 -- 暴力解决
        /*
         一个数独的解法需遵循如下规则：
         
        数字 1-9 在每一行只能出现一次。
        数字 1-9 在每一列只能出现一次。
        数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

        给定的数独序列只包含数字 1-9 和字符 '.' 。 char - 48 就是数字
        你可以假设给定的数独只有唯一解。
        给定数独永远是 9x9 形式的。
        */
        static void SolveSudoku(char[,] board)
        {
            StartWork(board, 0, 0);
        }

        static bool StartWork(char[,] board, int beginX, int beginY)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i, j] == '.') // 只找到一个空的
                    {
                        List<char> canNum = GetNumber(board, i, j);
                        for (int index = 0; index < canNum.Count; index++)
                        {
                            board[i, j] = canNum[index]; // 有得填 -> 填完之后继续下一个
                            // 递归， 由于当前这个填了， 下次填的就是下一个
                            if (StartWork(board, i, j))
                            {
                                // 如果下次填成功， OK
                                return true;
                            }
                        }
                        // 直到遍历完了还没成功， 说明没可能成功了， 返回 false, 当前填的也不能不算数
                        board[i, j] = '.';
                        return false;
                    }
                }
            }
            return true;
        }

        static List<char> GetNumber(char[,] board, int x, int y)
        {
            List<char> chars = new List<char> { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

            // 横向
            for (int v = 0; v < 9; v++)
            {
                char target = board[x, v];
                if (target != '.')
                {
                    chars.Remove(target);
                }
            }

            //纵向 
            for (int v = 0; v < 9; v++)
            {
                char target = board[v, y];
                if (target != '.')
                {
                    chars.Remove(target);
                }
            }

            // 判断在哪个九宫格
            int beginX = 0;
            if (x >= 6)
            {
                beginX = 6;
            }
            else if (x >= 3)
            {
                beginX = 3;
            }

            int beginY = 0;
            if (y >= 6)
            {
                beginY = 6;
            }
            else if (y >= 3)
            {
                beginY = 3;
            }

            for (int i = beginX; i < beginX + 3; i++)
            {
                for (int j = beginY; j < beginY + 3; j++)
                {
                    char target = board[i, j];
                    if (target != '.')
                    {
                        chars.Remove(target);
                    }
                }
            }
            return chars;
        }
        #endregion
    }
    public class Solution
    {
        public void SolveSudoku(char[,] board)
        {
            StartWork(board, 0, 0);
        }

        bool StartWork(char[,] board, int beginX, int beginY)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i, j] == '.') // 只找到一个空的
                    {
                        List<char> canNum = GetNumber(board, i, j);
                        for (int index = 0; index < canNum.Count; index++)
                        {
                            board[i, j] = canNum[index]; // 有得填 -> 填完之后继续下一个
                                                         // 递归， 由于当前这个填了， 下次填的就是下一个
                            if (StartWork(board, i, j))
                            {
                                // 如果下次填成功， OK
                                return true;
                            }
                        }
                        // 直到遍历完了还没成功， 说明没可能成功了， 返回 false, 当前填的也不能不算数
                        board[i, j] = '.';
                        return false;
                    }
                }
            }
            return true;
        }

        // 效率太低问题就出在这， 一共获取了 9 * 9 * 9 次值， 实际只要获取一次即可
        List<char> GetNumber(char[,] board, int x, int y)
        {
            List<char> chars = new List<char> { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

            // 横向
            for (int v = 0; v < 9; v++)
            {
                char target = board[x, v];
                if (target != '.')
                {
                    chars.Remove(target);
                }
            }

            //纵向 
            for (int v = 0; v < 9; v++)
            {
                char target = board[v, y];
                if (target != '.')
                {
                    chars.Remove(target);
                }
            }

            // 判断在哪个九宫格
            int beginX = 0;
            if (x >= 6)
            {
                beginX = 6;
            }
            else if (x >= 3)
            {
                beginX = 3;
            }

            int beginY = 0;
            if (y >= 6)
            {
                beginY = 6;
            }
            else if (y >= 3)
            {
                beginY = 3;
            }

            for (int i = beginX; i < beginX + 3; i++)
            {
                for (int j = beginY; j < beginY + 3; j++)
                {
                    char target = board[i, j];
                    if (target != '.')
                    {
                        chars.Remove(target);
                    }
                }
            }
            return chars;
        }
    }
}
