using System;

public class Class1
{
	public Class1()
	{

        #region 394_字符串解码 
        /*
        给定一个经过编码的字符串，返回它解码后的字符串。
        编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
        你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
        此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
        示例:
        s = "3[a]2[bc]", 返回 "aaabcbc".
        s = "3[a2[c]]", 返回 "accaccacc".
        s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

        来源：力扣（LeetCode）
        链接：https://leetcode-cn.com/problems/decode-string
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        */
        // 递归
        // Runtime: 84 ms, faster than 70.29% of C# online submissions for Decode String.
        // Memory Usage: 22.6 MB, less than 10.00% of C# online submissions for Decode String.
        public string DecodeString(string s)
        {
            return GetStringByNum(1, s, 0, s.Length - 1);
        }

        string GetStringByNum(int num, string str, int left, int right)
        {
            int index = left;
            string reapStr = "";

            while (index <= right)
            {
                if (str[index] >= '0' && str[index] <= '9')
                {
                    int numL = index;
                    string numStr = "";
                    while (str[numL] >= '0' && str[numL] <= '9')
                    {
                        numStr += str[numL];
                        numL++;
                    }

                    int leftBrackets = numL;
                    int rightBrackets = leftBrackets + 1;

                    Stack<int> bracketStack = new Stack<int>();
                    bracketStack.Push(leftBrackets);
                    while (bracketStack.Count != 0)
                    {
                        ++rightBrackets;
                        if (str[rightBrackets] == '[')
                            bracketStack.Push(rightBrackets);
                        if (str[rightBrackets] == ']')
                            bracketStack.Pop();
                    }
                    reapStr += GetStringByNum(int.Parse(numStr), str, leftBrackets + 1, rightBrackets - 1);
                    index = rightBrackets + 1;
                }
                else
                {
                    reapStr += str[index];
                    ++index;
                }
            }

            string res = "";
            for (int i = 0; i < num; i++)
            {
                res += reapStr;
            }
            return res;
        }
        #endregion

    }
}
