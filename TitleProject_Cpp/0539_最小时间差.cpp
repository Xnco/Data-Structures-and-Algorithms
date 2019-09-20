
#pragma region 539_最小时间差
/*
给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并已分钟数表示。
示例 1：
输入: ["23:59","00:00"]
输出: 1
备注:
列表中时间数在 2~20000 之间。
每个时间取值在 00:00~23:59 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 20 ms, faster than 68.12% of C++ online submissions for Minimum Time Difference.
	//Memory Usage : 12.1 MB, less than 60.00 % of C++ online submissions for Minimum Time Difference.
	int findMinDifference(vector<string>& timePoints) {
		vector<int> all;
		for (int i = 0; i < timePoints.size(); ++i)
		{
			//int point = timePoints[i].find(':');
			int hour = stoi(timePoints[i].substr(0, 2));
			int minute = stoi(timePoints[i].substr(3, 2));
			all.push_back(hour * 60 + minute);
		}
		sort(all.begin(), all.end());
		int res = all[0] + 1440 - all[all.size() - 1];
		for (int i = 0; i < all.size() - 1; ++i)
		{
			res = min(all[i + 1] - all[i], res);
		}
		return res;
	}
};
#pragma endregion
