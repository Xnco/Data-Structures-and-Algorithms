#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 283_移动零
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = nums.size();
		int left = 0;
		for (size_t i = 0; i < count; i++)
		{
			if (nums[i] != 0)
			{
				nums[left++] = nums[i];
			}
		}

		while (left < count)
		{
			nums[left++] = 0;
		}
	}
};
#pragma endregion