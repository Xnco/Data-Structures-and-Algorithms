
#pragma region 152_乘积最大子数组
/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），
并返回该子数组所对应的乘积。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 类似最大子数组, 但是乘法需要考虑负负得正的情况
	//Runtime : 4 ms, faster than 92.97 % of C++ online submissions for Maximum Product Subarray.
	//Memory Usage : 11.9 MB, less than 5.00 % of C++ online submissions for Maximum Product Subarray.
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int maxNum = 1;
		int minNum = 1;
		int res = INT_MIN;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0) swap(minNum, maxNum);
			minNum = min(minNum * nums[i], nums[i]);
			maxNum = max(maxNum * nums[i], nums[i]);
			res = max(res, maxNum);
		}
		return res;
	}
};
#pragma endregion
int main()
{
	vector<int> temp{ 2,3,-2,4 };
	Solution s;
	s.maxProduct(temp);
}