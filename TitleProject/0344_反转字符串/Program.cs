using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0344_反转字符串
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 344-反转字符串 
        /*
            编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
            不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
            你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
        */
        // 直接头尾交换反转 724 ms
        static void ReverseString(char[] s)
        {
            for (int i = 0; i < s.Length / 2; i++)
            {
                char tmp = s[i];
                s[i] = s[s.Length - i - 1];
                s[s.Length - i - 1] = tmp;
            }
        }
        #endregion
    }
}
