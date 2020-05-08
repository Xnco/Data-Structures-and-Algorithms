
#pragma region 221_最大正方形
/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 暴力就略过了
	// 直接动态规划 dp[i,j]表示以i,j为正方形右下角的边长
	// dp[i, j] = min(dp[i-1, j-1], dp[i, j-1], dp[i-1, j]) + 1
	//Runtime: 4 ms, faster than 100 % of C++ online submissions for Maximal Square.
	//Memory Usage : 9.2 MB, less than 100 % of C++ online submissions for Maximal Square.
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if (matrix.size() == 0) return 0;

		int maxSide = 0;
		int rows = matrix.size();
		int columns = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(columns));

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if (matrix[i][j] == '1')
				{
					if (i - 1 < 0 || j - 1 < 0)
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
					}
					maxSide = maxSide > dp[i][j] ? maxSide : dp[i][j];
				}
			}
		}
		return maxSide * maxSide;
	}
};
#pragma endregion
