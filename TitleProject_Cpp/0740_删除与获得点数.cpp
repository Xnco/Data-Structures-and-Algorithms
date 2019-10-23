
#pragma region 740_删除与获得点数
/*
给定一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

示例 1:
输入: nums = [3, 4, 2]
输出: 6
解释:
删除 4 来获得 4 个点数，因此 3 也被删除。
之后，删除 2 来获得 2 个点数。总共获得 6 个点数。

示例 2:
输入: nums = [2, 2, 3, 3, 3, 4]
输出: 9
解释:
删除 3 来获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。

注意:
nums的长度最大为20000。
每个整数nums[i]的大小都在[1, 10000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-and-earn
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// dp - 空间换时间 然而并不快
	//Runtime: 4 ms, faster than 98.86% of C++ online submissions for Delete and Earn.
	//Memory Usage : 11 MB, less than 25.00 % of C++ online submissions for Deleteand Earn.
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> countList(10001, 0);
		int maxIndex = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			++countList[nums[i]];
			maxIndex = max(maxIndex, nums[i]);
		}

		vector<int>dp(maxIndex + 1, 0);
		dp[1] = countList[1];
		for (int i = 2; i < dp.size(); ++i)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + countList[i] * i);
		}
		return dp[dp.size() - 1];
	}
};
#pragma endregion
