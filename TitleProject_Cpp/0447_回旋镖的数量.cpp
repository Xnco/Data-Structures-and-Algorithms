
#pragma region 447_回旋镖的数量
/*
给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-boomerangs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 724 ms, faster than 22.78% of C++ online submissions for Number of Boomerangs.
	//Memory Usage : 147.7 MB, less than 47.06 % of C++ online submissions for Number of Boomerangs.
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;
		map<int, int> dir;
		for (size_t i = 0; i < points.size(); ++i)
		{
			for (size_t j = 0; j < points.size(); ++j)
			{
				if (i == j)
				{
					continue;
				}
				int x = points[i][0] - points[j][0];
				int y = points[i][1] - points[j][1];
				int dist = x * x + y * y;
				if (dir.find(dist) == dir.end())
				{
					dir[dist] = 1;
				}
				else
				{
					// 当能满足的点从 n->n+1 时, 可能性增多 2n 个
					res += 2 * dir[dist];
					dir[dist]++;
				}
			}
			dir.clear();
		}
		return res;
	}
};
#pragma endregion
