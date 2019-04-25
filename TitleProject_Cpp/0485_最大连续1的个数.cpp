
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 485_最大连续1的个数
/*
给定一个二进制数组， 计算其中最大连续1的个数。
示例 1:
输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：
输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/

class Solution {
public:
	// 40ms(72.8%), 11.9MB(49.2%)
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
		int max = 0;
		for (auto item : nums)
		{
			if (item == 1)
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
			else
			{
				count = 0;
			}
		}
		return max;
	}
};
#pragma endregion
