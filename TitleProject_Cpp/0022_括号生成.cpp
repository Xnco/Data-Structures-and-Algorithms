#include "pch.h";
#include <iostream>;
#include <vector>;
#include <string>;
#include <stack>;
#include <queue>;

using namespace std;

#pragma region 22_括号生成
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
// 44ms, 24.6MB, 几乎最慢了
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0)
		{
			return result;
		}
		stack<string> leftBrackets;
		leftBrackets.push("(");
		AddBrackets(n, 1, "(", leftBrackets, result);
		return result;
	}

	void AddBrackets(int n, int count, string s, stack<string> left, vector<string>& result) {
		if (left.empty() && count != n)
		{
			// 栈中没有 (, 此时只能加 ( 
			left.push("(");
			AddBrackets(n, count + 1, s + "(", left, result);
		}
		else
		{
			if (count == n)
			{
				for (size_t i = 0; i < left.size(); i++)
				{
					s += ")";
				}
				result.push_back(s);
			}
			else
			{
				// 可以加 (
				left.push("(");
				AddBrackets(n, count + 1, s + "(", left, result);
				left.pop();

				// 也可以加 )
				left.pop();
				AddBrackets(n, count, s + ")", left, result);
			}
		}
	}
};
#pragma endregion