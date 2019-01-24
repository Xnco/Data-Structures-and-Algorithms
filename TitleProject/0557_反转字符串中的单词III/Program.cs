using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0557_反转字符串中的单词III
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 557_反转字符串中的单词 III
        /*
        给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

        示例 1:
            输入: "Let's take LeetCode contest"
            输出: "s'teL ekat edoCteeL tsetnoc" 
            注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
        */

        // 获取到一个单词就局部反转，最后再将数组拼回来
        public static string ReverseWords(string s)
        {
            char[] array = s.ToCharArray();
            int begin = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ' ')
                {
                    ReverseString(array, begin, i - 1);
                    begin = i + 1;
                }
            }

            // 最后一个了
            ReverseString(array, begin, array.Length - 1);

            StringBuilder str = new StringBuilder();
            for (int i = 0; i < array.Length; i++)
            {
                //str+=( array[i].ToString());
                str.Append(array[i].ToString());
            }
            return str.ToString();
        }

        static void ReverseString(char[] s, int i, int j)
        {
            while (i < j)
            {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;

                i++;
                j--;
            }
        }
        #endregion
    }


}
