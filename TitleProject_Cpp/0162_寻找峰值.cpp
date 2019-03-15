#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 162_寻找峰值
/*
峰值元素是指其值大于左右相邻值的元素。
给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞。
示例 1:
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5
解释: 你的函数可以返回索引 1，其峰值元素为 2；
	 或者返回索引 5， 其峰值元素为 6。
说明:
你的解法应该是 O(logN) 时间复杂度的。
*/

class Solution {
public:
	// 12ms(击败16.2%)，9MB - 这是有毒吧，英文版的8ms, 击败99.31%
	// 二分，nums[mid - 1] < nums[mid], 大的那一半一定有峰值
	int findPeakElement(vector<int>& nums) {
		if (nums.size()==1)
		{
			return 0;
		}
		int left = 0;
		int right = nums.size() - 1;

		while (left + 1 < right)
		{
			int mid = (left + right) / 2;
			if (mid > 0 && nums[mid - 1] < nums[mid]){
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return nums[left] > nums[right] ? left : right; 
	}
};
#pragma endregion