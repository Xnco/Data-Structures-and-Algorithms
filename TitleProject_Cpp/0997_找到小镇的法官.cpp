
#pragma region 997_找到小镇的法官
/*
在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
如果小镇的法官真的存在，那么：
小镇的法官不相信任何人。
每个人（除了小镇法官外）都信任小镇的法官。
只有一个人同时满足属性 1 和属性 2 。
给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。

示例 1：
输入：N = 2, trust = [[1,2]]
输出：2

示例 2：
输入：N = 3, trust = [[1,3],[2,3]]
输出：3

示例 3：
输入：N = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1

示例 4：
输入：N = 3, trust = [[1,2],[2,3]]
输出：-1

示例 5：
输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
输出：3

提示：
1 <= N <= 1000
trust.length <= 10000
trust[i] 是完全不同的
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-town-judge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//暴力 
	//Runtime: 176 ms, faster than 41.99% of C++ online submissions for Find the Town Judge.
	//Memory Usage : 100 MB, less than 12.50 % of C++ online submissions for Find the Town Judge.
	int findJudge(int N, vector<vector<int>>& trust)
	{
		vector<vector<int>> list(N, vector<int>(N, 0));

		for (auto i = 0; i < trust.size(); ++i)
		{
			list[trust[i][0] - 1][trust[i][1] - 1] = 1;
		}

		// 竖直判断除自身以外全是1的为法官
		bool flag = true;
		for (auto i = 0; i < N; ++i)
		{
			flag = true;
			for (auto j = 0; j < N; ++j)
			{
				if (i != j && list[j][i] == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				// 所有人都相信的人, 还不能相信别人
				bool flag2 = true;
				for (auto j = 0; j < N; ++j)
				{
					if (i != j && list[i][j] == 1)
					{
						flag2 = false;
						break;
					}
				}
				if (flag2)
					return i + 1;
			}
		}
		return -1;
	}
};
#pragma endregion
