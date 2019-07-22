
#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 39_组合总和
/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
// 回溯算法 - 40ms(击败9%), 10.3MB
class Solution {
public:
	//Runtime: 12 ms, faster than 86.24% of C++ online submissions for Combination Sum.
	//Memory Usage : 9.4 MB, less than 73.85 % of C++ online submissions for Combination Sum.
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.size() == 0) {
			return result;
		}
		int count = 0;
		vector<int> cur;
		addNumber(candidates, target, count, cur, 0, result);
		return result;
	}

	void addNumber(vector<int>& candidates, int target, int count, vector<int>& cur, int index, vector<vector<int>>& result) {
		for (size_t i = index; i < candidates.size(); i++)
		{
			count += candidates[i];
			cur.push_back(candidates[i]);
			if (count == target)
			{
				result.push_back(cur);
			}
			else if (count < target)
			{
				addNumber(candidates, target, count, cur, i, result);
			}
			cur.pop_back();
			count -= candidates[i];
		}
	}
};
#pragma endregion