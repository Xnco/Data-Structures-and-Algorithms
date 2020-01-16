
#pragma region 228_汇总区间
/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/summary-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
	//Memory Usage : 8.4 MB, less than 92.31 % of C++ online submissions for Summary Ranges.
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		string cur = "";
		int count = 0;

		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (cur == "")
			{
				cur += to_string(nums[i]);
			}
			else
			{
				if (nums[i] == nums[i - 1] + 1)
				{
					count++;
				}
				else
				{
					if (count != 0)
					{
						cur += "->" + to_string(nums[i - 1]);
						count = 0;
					}
					res.push_back(cur);
					cur = "";
					i--;
				}
			}
		}
		if (count != 0)
		{
			cur += "->" + to_string(nums[nums.size() - 1]);
		}
		if (cur != "")
		{
			res.push_back(cur);
		}
		return res;
	}
};
#pragma endregion
