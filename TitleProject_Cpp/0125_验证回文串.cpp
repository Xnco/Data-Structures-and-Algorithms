#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 125_验证回文串
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2
输入: "race a car"
输出: false
*/

class Solution {
	// 数字 48-57 A-Z 65-90 a-z 97-122
	// 12ms(77.3%), 9.8MB(5%)
public:
	bool isPalindrome(string s) {

		string str = "";

		for (size_t i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]) || isdigit(s[i]))
			{
				str += tolower(s[i]);
			}
		}
		string str2 = str;
		reverse(str.begin(), str.end());
		return str == str2;
	}
};
#pragma endregion