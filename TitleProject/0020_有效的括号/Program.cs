using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0020_有效的括号
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 20_有效的括号
        /*
            给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
            有效字符串需满足：
            左括号必须用相同类型的右括号闭合。
            左括号必须以正确的顺序闭合。
            注意空字符串可被认为是有效字符串。

            示例 1
            输入: "()"
            输出: true

            示例 2:
            输入: "()[]{}"
            输出: true

            示例 3:
            输入: "(]"
            输出: false

            示例 4:
            输入: "([)]"
            输出: false

            示例 5:
            输入: "{[]}"
            输出: true
        */

        // 典型的栈问题 168ms
        public static bool IsValid(string s)
        {
            Stack<char> stack = new Stack<char>();
            for (int i = 0; i < s.Length; i++)
            {
                if (stack.Count == 0)
                {
                    stack.Push(s[i]);
                }
                else
                {
                    char tmp = stack.Peek();
                    if (Pair(tmp, s[i]))
                    {
                        // 成对 
                        stack.Pop();
                    }
                    else
                    {
                        // 不成对
                        stack.Push(s[i]);
                    }
                }
            }

            return stack.Count == 0;
        }

        static bool Pair(char before, char current)
        {
            switch (before)
            {
                case '(':
                    return current == ')';
                case '[':
                    return current == ']';
                case '{':
                    return current == '}';
                default:
                    return false;
            }
        }
        #endregion
    }
}
