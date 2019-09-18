
#pragma region 661_图片平滑器
/*
包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

示例 1:

输入:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
输出:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
注意:

给定矩阵中的整数范围为 [0, 255]。
矩阵的长和宽的范围均为 [1, 150]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/image-smoother
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime : 140 ms, faster than 93.69 % of C++ online submissions for Image Smoother.
	//Memory Usage : 17.4 MB, less than 100.00 % of C++ online submissions for Image Smoother.
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> res(M.size(), vector<int>(M[0].size()));
		for (int i = 0; i < M.size(); ++i)
		{
			for (int j = 0; j < M[0].size(); ++j)
			{
				res[i][j] = getAve(M, i, j);
			}
		}
		return res;
	}

	int getAve(vector<vector<int>>& M, int x, int y)
	{
		int sum = 0;
		int count = 0;
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				if (x + i >= 0 && x + i < M.size() && y + j >= 0 && y + j < M[0].size())
				{
					sum += M[x + i][y + j];
					count++;
				}
			}
		}
		return sum / count;
	}
};
#pragma endregion
