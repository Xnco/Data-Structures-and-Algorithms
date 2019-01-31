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
            //Console.WriteLine(Convert("LEETCODEISHIRING", 3)); 

            
        }

        #region 0 
        /*
         
        */
        static void Func()
        {

        }
        #endregion
        #region 54_螺旋矩阵
        /*
        给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

        示例 1:
        输入:
        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        输出: [1,2,3,6,9,8,7,4,5]

        示例 2:
        输入:
        [
          [1, 2, 3, 4],
          [5, 6, 7, 8],
          [9,10,11,12]
        ]
        输出: [1,2,3,4,8,12,11,10,9,5,6,7]
        */
        static IList<int> SpiralOrder(int[,] matrix)
        {

        }
        #endregion
        #region 6_Z字形变换
        /*
        将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
        比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
        L   C   I   R
        E T O E S I I G
        E   D   H   N
        之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
        请你实现这个将字符串进行指定行数变换的函数：
        string convert(string s, int numRows);

        示例 1:
        输入: s = "LEETCODEISHIRING", numRows = 3
        输出: "LCIRETOESIIGEDHN"

        示例 2:
        输入: s = "LEETCODEISHIRING", numRows = 4
        输出: "LDREOEIIECIHNTSG"
        解释:
        L     D     R
        E   O E   I I
        E C   I H   N
        T     S     G
        */
        static string Convert(string s, int numRows)
        {
            string newStr = "";
            int num = numRows * 2 - 2;

            // 最上面一行
            int head = 0;
            while (head < s.Length)
            {
                newStr += s[head].ToString();
                head += num;
            }

            // 中间的所有成对的行
            for (int i = 0; i < num - 2; i++)
            {
                int body = 0;
                while (body < s.Length)
                {
                    newStr += s[body + 1 + i].ToString();
                    newStr += s[body + num - 1 - i].ToString();
                    body += num;
                }
            }

            // 底部一行
            int bottom = 0;
            while (bottom < s.Length)
            {

            }
            return newStr;
        }
        #endregion
        #region 879 - 动态规划问题
        /*
         
        */
        static void ProfitableSchemes()
        {

        }
        #endregion
    }
}