#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 507_完美数
/*
对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False
示例：
输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14
注意:
输入的数字 n 不会超过 100,000,000. (1e8)
*/

class Solution {
	// 4ms(100%), 7.9MB(100%)
public:
	bool checkPerfectNumber(int num) {
		if (num < 1)
		{
			return false;
		}

		int sum = 0;
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0)
			{
				if (i * i != num)
					sum += num / i;
				sum += i;
			}
		}
		return sum + 1 == num;
	}

	// 4ms, 8.1MB
	bool checkPerfectNumber2(int num) {
		switch (num)
		{
		case 6:
		case 28:
		case 496:
		case 8128:
		case 33550336:
			return true;
		default:
			return false;
		}
	}

};
#pragma endregion
