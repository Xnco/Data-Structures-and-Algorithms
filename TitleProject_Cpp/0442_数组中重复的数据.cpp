
#pragma region 442_数组中重复的数据
/*
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。
你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
示例：
输入:
[4,3,2,7,8,2,3,1]
输出:
[2,3]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 用 a[i] 当下标, 当取值重复加入res
	//Runtime : 100 ms, faster than 97.64 % of C++ online submissions for Find All Duplicates in an Array.
	//Memory Usage : 14.9 MB, less than 90.00 % of C++ online submissions for Find All Duplicates in an Array.
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			int value = abs(nums[i]);
			if (nums[value - 1] > 0)
			{
				nums[value - 1] *= -1;
			}
			else
			{
				res.push_back(value);
			}
		}
		return res;
	}
};
#pragma endregion
