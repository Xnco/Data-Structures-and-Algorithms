#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 713_乘积小于K的子数组
/*
给定一个正整数数组 nums。
找出该数组内乘积小于 k 的连续的子数组的个数。
示例 1:
输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:
	0 < nums.length <= 50000
	0 < nums[i] < 1000
	0 <= k < 10^6
*/

class Solution {

	// 暴力 - 超时
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int count = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			int sum = 1;
			for (size_t j = i; j < nums.size(); j++)
			{
				sum *= nums[j];
				if (sum < k)
					count++;
				else
					break;
			}
		}
		return count;
	}

	//[10,5,2,6], 100 自然数求和 n(n+1) / 2
	//[10,2,2,5,4,4,4,3,7,7] 289 - 思路错误, 漏了一些情况
	int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
		int count = 0;
		int left = 0;
		while (left < nums.size())
		{
			int right = left;
			int sum = 1;
			while (right < nums.size())
			{
				sum *= nums[right];
				if (sum < k)
				{
					right++;
				}
				else
				{
					break;
				}
			}
			float len = right - left;
			count += len / 2.0f * (len + 1);
			if (len == 0)
			{
				// 没有满足的直接跳过该数字
				right++;
			}
			else if (len != 1)
			{
				right--; // right 回退一格
				count--;
			}
			left = right;
		}
		return count;
	}

	// 双指针 - 132ms(72%), 18.2MB(100%)
	int numSubarrayProductLessThanK3(vector<int>& nums, int k) {
		int left = 0;
		int right = 0;
		int count = 0;
		int sum = 1;
		while (right < nums.size())
		{
			sum *= nums[right];
			right++;
			while (left < right && sum >= k) {
				sum /= nums[left];
				left++;
			}
			count += right - left;
		}
		return count;
	}
};

#pragma endregion