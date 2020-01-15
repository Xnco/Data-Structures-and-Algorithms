
#pragma region 300_最长上升子序列
/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//dp递归, 时间复杂度 O(n²)
	//Runtime : 532 ms, faster than 5.69 % of C++ online submissions for Longest Increasing Subsequence.
	//Memory Usage : 13.6 MB, less than 6.25 % of C++ online submissions for Longest Increasing Subsequence.
	int lengthOfLIS(vector<int>& nums)
	{
		int max = 0;
		map<int, int> dp;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			int cur = GetMax(nums, i, dp) + 1;
			if (cur > max)
			{
				max = cur;
			}
		}
		return max;
	}

	int GetMax(vector<int>& nums, int begin, map<int, int>& dp)
	{
		if (dp.find(begin) != dp.end())
		{
			return dp[begin];
		}
		int max = 0;
		for (size_t i = begin + 1; i < nums.size(); i++)
		{
			int cur = 1;
			if (nums[i] > nums[begin])
			{
				cur += GetMax(nums, i, dp);
				if (cur > max)
				{
					max = cur;
				}
			}
		}
		dp[begin] = max;
		return max;
	}
};
#pragma endregion

int main()
{
	Solution s;
	//[10, 9, 2, 5, 3, 7, 101, 18]
	//[10, 9, 2, 5, 3, 4]
	vector<int> test{ 10,9,2,5,3,4 };
	s.lengthOfLIS(test);
}