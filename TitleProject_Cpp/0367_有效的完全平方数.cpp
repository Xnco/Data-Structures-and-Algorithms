#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 367_有效的完全平方数
/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。
示例 1：
输入：16
输出：True
示例 2：
输入：14
输出：False
*/

class Solution {
	// 一般的方法 - 4ms(61%), 7.9MB(95.2%)
public:
	bool isPerfectSquare(int num) {
		long n = 1; // 用 int 越界
		while (true)
		{
			long sum = n * n;
			if (sum == num)
			{
				return true;
			}
			if (sum > num)
			{
				return false;
			}
			++n;
		}
	}

	// 二分法 - 4ms(100%), 8.1MB(42%)
	bool isPerfectSquare(int num) {
		if (num == 1) return true;

		long left = 0;
		long right = num;

		while (left < right)
		{
			long mid = (left + right + 1) / 2;

			if (mid <= num / mid)
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left * left == num;
	}
};
#pragma endregion