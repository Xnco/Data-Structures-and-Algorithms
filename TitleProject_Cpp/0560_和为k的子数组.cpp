
#pragma region 560_和为K的子数组
/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 暴力  超时
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j < nums.size(); ++j)
			{
				sum += nums[j];
				if (sum == k) ++res;
			}
		}
		return res;
	}

	// 倒着遍历就不超时了 ??
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		for (int start = 0; start < nums.size(); ++start) {
			int sum = 0;
			for (int end = start; end >= 0; --end) {
				sum += nums[end];
				if (sum == k) res++;
			}
		}
		return res;
	}

	// 哈希表优化 - 计算[0-j]的和, sum(0-j) - k出现过, 说明该数可以形成连续子数组, 数量+出现过的次数
	//Runtime: 80 ms, faster than 38.18 % of C++ online submissions for Subarray Sum Equals K.
	//Memory Usage : 22.1 MB, less than 5.34 % of C++ online submissions for Subarray Sum Equals K.
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> temp{ {0, 1} };
		int sum = 0;
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			//if (temp.find(sum - k) != temp.end())
			if (temp.count(sum - k))
			{
				// 有连续子数组
				res += temp[sum - k];
			}
			++temp[sum];
		}
		return res;
	}
};
#pragma endregion
