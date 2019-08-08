
#pragma region 463_岛屿的周长
/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，
但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出: 16
解释: 它的周长是下面图片中的 16 个黄色的边：

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/island-perimeter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 68 ms, faster than 78.09% of C++ online submissions for Island Perimeter.
	//Memory Usage : 16.1 MB, less than 85.71 % of C++ online submissions for Island Perimeter.
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
				{
					res += 4;
					res -= isLinkNum(grid, i, j) * 2;
				}
			}
		}
		return res;
	}

	int isLinkNum(vector<vector<int>>& grid, int x, int y)
	{
		int res = 0;
		if (x - 1 >= 0 && grid[x - 1][y] == 1)
		{
			++res;
		}
		if (y - 1 >= 0 && grid[x][y - 1] == 1)
		{
			++res;
		}
		return res;
	}

};
#pragma endregion
