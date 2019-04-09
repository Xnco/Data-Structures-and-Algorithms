#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 680_验证回文字符串 Ⅱ
/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
输入: "aba"
输出: True
示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/

class Solution {
	// 108ms(78%), 26.1MB(0)
public:
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.length() - 1;
		bool one = false;

		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
			}
			else
			{
				return Repeat(left + 1, right, s) || Repeat(left, right - 1, s);
			}
		}
		return true;
	}

	bool Repeat(int left, int right, string s)
	{
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
#pragma endregion