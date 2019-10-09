
#pragma region 506_相对名次
/*
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。
前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
(注：分数越高的选手，排名越靠前。)
示例 1:
输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	// 利用排序 + map, 空间换时间 
	//Runtime : 16 ms, faster than 88.85 % of C++ online submissions for Relative Ranks.
	//Memory Usage : 12.8 MB, less than 33.33 % of C++ online submissions for Relative Ranks.
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<int> sort_nums = nums;
		sort(sort_nums.begin(), sort_nums.end(), greater<int>()); // 降序排序
		//reverse(sort_nums.begin(), sort_nums.end());
		unordered_map<int, string> rank;
		for (int i = 0; i < sort_nums.size(); ++i)
		{
			if (i == 0)
				rank[sort_nums[i]] = "Gold Medal";
			else if (i == 1)
				rank[sort_nums[i]] = "Silver Medal";
			else if (i == 2)
				rank[sort_nums[i]] = "Bronze Medal";
			else
				rank[sort_nums[i]] = to_string(i + 1);
		}

		vector<string> res(nums.size());
		for (int i = 0; i < nums.size(); ++i)
		{
			res[i] = rank[nums[i]];
		}
		return res;
	}
};
#pragma endregion
