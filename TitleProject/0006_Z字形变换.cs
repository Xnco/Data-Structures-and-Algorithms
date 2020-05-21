using System;

public class Class1
{
	public Class1()
	{
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
        // 自己总结规律 - 遍历一次, 时间空间都是O(n)
        static string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            string newStr = "";

            for (int i = 1; i <= numRows; i++)
            {
                int num = 0;
                while (true)
                {
                    int index = (2 * numRows - 2) * num + i - 1;
                    if (index >= s.Length)
                    {
                        break;
                    }
                    newStr += s[index];

                    if (i != 1 && i != numRows)
                    {
                        // 除开第一行和最后一行, 还要再加一个
                        int lastIndex = (2 * numRows - 2) * num + numRows + numRows - i - 1;
                        if (lastIndex >= s.Length)
                        {
                            break;
                        }
                        newStr += s[lastIndex];
                    }

                    ++num;
                }
            }
            return newStr;
        }

        // 还有一种方案, 用遍历s, 用lows个list将s拆分, 最后再合并
        #endregion

    }
}
