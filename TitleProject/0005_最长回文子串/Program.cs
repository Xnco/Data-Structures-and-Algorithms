using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0005_最长回文子串
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(FuLongestPalindromenc2("a"));
        }

        #region 5_最长回文子串 
        /*
         给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

        示例 1：
            输入: "babad"
            输出: "bab"
        注意: "aba" 也是一个有效答案。

        示例 2：
            输入: "cbbd"
            输出: "bb"
        */
        // 暴力法
        // 3640ms - - O(n³)
        static string FuLongestPalindromenc(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return "";
            }
            int begin = 0;
            int end = 0;
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = i + 1; j < s.Length; j++)
                {
                    if (IsMeet(s, i, j))
                    {
                        // 是回文记录判断最大值
                        if (j - i > end - begin)
                        {
                            begin = i;
                            end = j;
                        }
                    }
                }
            }

            return s.Substring(begin, end - begin + 1);
        }

        // 判断某一段是否是回文数
        static bool IsMeet(string s, int begin, int end)
        {
            while (begin < end)
            {
                if (s[begin] != s[end])
                {
                    return false;
                }
                begin++;
                end--;
            }
            return true;
        }

        // 152ms 击败 87%
        // 以每个字符为中心， 判断所有的回文数大小，不用两次遍历了
        static string FuLongestPalindromenc2(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return "";
            }

            int begin = 0;
            int end = 0;

            for (int i = 0; i < s.Length; i++)
            {
                int len1 = GetMeetLen(s, i, i);
                int len2 = GetMeetLen(s, i, i + 1);
                int len = Math.Max(len1, len2);
                if (len > end - begin + 1)
                {
                    begin = i - (len - 1) / 2;
                    end = i + len / 2;
                }
            }

            return s.Substring(begin, end - begin + 1);
        }

        static int GetMeetLen(string s, int left, int right)
        {
            while (left >= 0 && right < s.Length && s[left] == s[right])
            {
                left--;
                right++;
            }
            return right - left - 1;
        }

        #endregion
    }
}
