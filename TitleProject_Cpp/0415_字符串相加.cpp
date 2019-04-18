#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
#pragma region 415_字符串相加
/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
注意：
num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/

class Solution {
	// 8ms(93%), 8.9MB(100%)
public:
	string addStrings(string num1, string num2) {
		string res = "";
		int l1 = num1.size() - 1;
		int l2 = num2.size() - 1;
		int cur = 0;
		while (l1 >= 0 || l2 >= 0 || cur != 0)
		{
			if (l1 >= 0)
				cur += num1[l1--] - '0';
			if (l2 >= 0)
				cur += num2[l2--] - '0';
			res += to_string(cur % 10);
			cur /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#pragma endregion