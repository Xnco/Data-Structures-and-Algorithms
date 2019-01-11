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
        //bool[,] rowNumber; // 某行某个数字是否存在，不管他存在什么地方
        //bool[,] colNumber; // 某列某个数字是否存在，不管他存在什么地方
        //bool[,] blockNumber; // 某块某个数字是否存在， 不管他存在什么地方

        public void SolveSudoku(char[,] board)
        {
            bool[,] rowNumber = new bool[9, 9];
            bool[,] colNumber = new bool[9, 9];
            bool[,] blockNumber = new bool[9, 9];

            // 初始化
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i, j] != '.')
                    {
                        int value = board[i, j] - 48 - 1; // char - 48 得到具体的数字， 再 -1 是将1-9转换成0-8
                        int block = (i / 3) * 3 + (j / 3);
                        rowNumber[i, value] = true;
                        colNumber[j, value] = true;
                        blockNumber[block, value] = true;
                    }
                }
            }

            StartWork(board, rowNumber, colNumber, blockNumber);
        }

        bool StartWork(char[,] board, bool[,] rowNumber, bool[,] colNumber, bool[,] blockNumber)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i, j] == '.') // 只需要找到一个空的
                    {
                        // 得到当前位置可能的值
                        //List<char> canNum = GetNumber(board, i, j);
                        // 将每个数字都填入一遍
                        for (int index = 0; index <= 8; index++)
                        {
                            // 判断这个数字能不能填 三个方向都要判断
                            int block = (i / 3) * 3 + (j / 3);
                            if (!rowNumber[i, index] && !colNumber[j, index] && !blockNumber[block, index])
                            {
                                // 能填 -> 填完之后继续下一个
                                board[i, j] = (char)(index + 48 + 1);
                                rowNumber[i, index] = true;
                                colNumber[j, index] = true;
                                blockNumber[block, index] = true;
                                // 递归， 由于当前这个填了， 下次填的就是下一个
                                if (StartWork(board, rowNumber, colNumber, blockNumber))
                                {
                                    // 如果下次填成功， OK (只有最后一个数都成功了才会返回true)
                                    return true;
                                }
                                else
                                {
                                    // 下一个填失败了 - 当前个重置，继续试下一个树
                                    board[i, j] = '.';
                                    rowNumber[i, index] = false;
                                    colNumber[j, index] = false;
                                    blockNumber[block, index] = false;
                                }
                            }
                        }
                        // 直到遍历完了还没成功， 说明当前数没可能成功了， 返回 false 告诉上一个数我这里路断了
                        return false;
                    }
                }
            }
            return true;
        }

        // 效率太低问题就出在这， 一共获取了 9 * 9 * 9 次值， 实际只要获取 1 次即可
        /*
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
        */

        // 根据行列数得到当前的块数
        int GetBlockIndex(int x, int y)
        {
            /* x决定行数 ， y决定列数
             * 012
             * 345
             * 678
            */
            return (x / 3) * 3 + (y / 3);
        }
    }
}
