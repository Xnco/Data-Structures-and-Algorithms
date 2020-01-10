
#pragma region 1190_反转每对括号间的子串
/*
给出一个字符串 s（仅含有小写英文字母和括号）。
请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
注意，您的结果中 不应 包含任何括号。

示例 1：
输入：s = "(abcd)"
输出："dcba"

示例 2：
输入：s = "(u(love)i)"
输出："iloveu"

示例 3：
输入：s = "(ed(et(oc))el)"
输出："leetcode"

示例 4：
输入：s = "a(bcdefghijkl(mno)p)q"
输出："apmnolkjihgfedcbq"

提示：
0 <= s.length <= 2000
s 中只有小写英文字母和括号
我们确保所有括号都是成对出现的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
	//Memory Usage : 8.6 MB, less than 100.00 % of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
	string reverseParentheses(string s) {
		stack<int> right_stack;
		for (auto i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				right_stack.push(i);
			}
			if (s[i] == ')')
			{
				int left = right_stack.top() + 1;
				int right = i - 1;
				while (left < right)
				{
					while (s[left] == '(' || s[left] == ')')
					{
						++left;
					}
					while (s[right] == '(' || s[right] == ')')
					{
						--right;
					}

					if (left < right)
					{
						swap(s[left], s[right]);
						++left;
						--right;
					}
				}
				right_stack.pop();
			}
		}
		string res = "";
		for (auto i = 0; i < s.length(); ++i)
		{
			if (s[i] != '(' && s[i] != ')')
			{
				res += s[i];
			}
		}
		return res;
	}
};
#pragma endregion
