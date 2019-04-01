
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 153_寻找旋转排序数组中的最小值
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
你可以假设数组中不存在重复元素。
示例 1:
输入: [3,4,5,1,2]
输出: 1
示例 2:
输入: [4,5,6,7,0,1,2]
输出: 0
*/

class Solution {
	// 明显二分问题 4ms(100%), 8.7MB(71.7%)
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		if (right == 0 || nums[0] < nums[right])
		{
			return nums[0];
		}

		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] > nums[right])
			{
				// 抛弃左边
				left = mid + 1;
			}
			else
			{
				// 抛弃右边
				right = mid;
			}
		}
		return nums[left];
	}

	// 8ms(46.9%), 8.8MB(16.7%)
	// 暴力 - 可以, 但不符合题意
	int findMin2(vector<int>& nums) {
		int min = nums[0];
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] < min)
			{
				min = nums[i];
			}
		}
		return min;
	}

	// 直接找到旋转点, 旋转点的下一个就是了
	// 4ms(100%), 8.7MB(66.88%)
	int findMin3(vector<int>& nums) {
		int len = nums.size() - 1;
		if (len == 0 || nums[0] < nums[len])
		{
			return nums[0];
		}

		for (size_t i = 0; i < len; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				return nums[i + 1];
			}
		}
		return nums[0];
	}
};
#pragma endregion