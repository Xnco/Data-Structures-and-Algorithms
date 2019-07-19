
#pragma region 64_最小路径和
/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//dp
	//Runtime: 4 ms, faster than 99.51% of C++ online submissions for Minimum Path Sum.
	//Memory Usage : 10.5 MB, less than 85.91 % of C++ online submissions for Minimum Path Sum.
	int minPathSum(vector<vector<int>>& grid) {
		int i, j;
		for (i = 0; i < grid.size(); i++)
		{
			for (j = 0; j < grid[i].size(); j++)
			{
				if (i == 0 && j == 0)
					continue;
				else if (i == 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0)
					grid[i][j] += grid[i - 1][j];
				else
					grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[i - 1][j - 1];
	}
};
#pragma endregion
