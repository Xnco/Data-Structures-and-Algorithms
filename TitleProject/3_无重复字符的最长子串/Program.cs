using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_无重复字符的最长子串
{
    /*
        给定一个字符串，找出不含有重复字符的最长子串的长度。

        示例 1:

        输入: "abcabcbb"
        输出: 3 
        解释: 无重复字符的最长子串是 "abc"，其长度为 3。
        示例 2:

        输入: "bbbbb"
        输出: 1
        解释: 无重复字符的最长子串是 "b"，其长度为 1。
        示例 3:

        输入: "pwwkew"
        输出: 3
        解释: 无重复字符的最长子串是 "wke"，其长度为 3。
        请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
     */
    class Program
    {
        static void Main(string[] args)
        {
        }

        static int LengthOfLongestSubstring(string s)
        {
            #region 暴力
            //int max = 0;
            //for (int j = 0; j < s.Length; j++)
            //{
            //    string tmp = "";
            //    for (int i = j; i < s.Length; i++)
            //    {
            //        // 如果已存在， 就中断
            //        string single = s[i].ToString();
            //        if (tmp.Contains(single))
            //        {
            //            break;
            //        }
            //        tmp += single;
            //    }
            //    if (tmp.Length > max)
            //    {
            //        max = tmp.Length;
            //    }
            //}
            //return max;
            #endregion

            int max = 0;
            string tmp = "";
            for (int i = 0; i < s.Length; i++)
            {
                int index = tmp.IndexOf(s[i]);
                if (index != -1)
                {
                    // 存在
                    if (index + 1 == tmp.Length)
                    {
                        tmp = "";
                    }
                    else
                    {
                        tmp = tmp.Substring(index + 1);
                    }
                }
                tmp += s[i];
                max = Math.Max(tmp.Length, max);     
            }
            return max;
        }
    }

        
}
