
#pragma region 983_最低票价
/*
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
火车票有三种不同的销售方式：
一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

示例 1：
输入：days = [1,4,6,7,8,20], costs = [2,7,15]
输出：11
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行。

示例 2：
输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
输出：17
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。
你总共花了 $17，并完成了你计划的每一天旅行。

提示：

1 <= days.length <= 365
1 <= days[i] <= 365
days 按顺序严格递增
costs.length == 3
1 <= costs[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-for-tickets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// dp -倒着遍历 
	// 没出行计划 -> dp[i] = dp[i + 1]
	// 有出行计划 -> dp[i] = min{cost[x] + dp[i + x]}, x∈{1, 7, 30}
	//Runtime: 4 ms, faster than 72.90% of C++ online submissions for Minimum Cost For Tickets.
	//Memory Usage : 9.5 MB, less than 12.50 % of C++ online submissions for Minimum Cost For Tickets.
	int dp[367] = { 0 }; // 367是因为 i+1 可能=366
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int point = days.size() - 1;
		for (int i = 365; i > 0; --i)
		{
			if (point >= 0 && i == days[point])
			{
				// 这天计划出行
				int daySum = costs[0] + dp[i + 1]; // -> 日票
				int weekSum = costs[1] + dp[i + 7 < 366 ? i + 7 : 366]; // -> 周票
				int monthSum = costs[2] + dp[i + 30 < 366 ? i + 30 : 366]; // -> 月票
				dp[i] = min(daySum, weekSum, monthSum);
				--point;
			}
			else
			{
				// 这天没有出行计划
				dp[i] = dp[i + 1];
			}
		}
		return dp[1];
	}

	int min(int a, int b, int c)
	{
		int temp = a < b ? a : b;
		return temp < c ? temp : c;
	}
};
#pragma endregion

int main()
{
	//days = [1,4,6,7,8,20], costs = [2,7,15]
	vector<int> days{ 6,8,9,18,20,21,23,25 };
	vector<int> costs{ 2,10,41 };
	Solution s;

	s.mincostTickets(days, costs);
}