
#pragma region 54_螺旋矩阵
/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
	//Memory Usage : 7 MB, less than 100.00 % of C++ online submissions for Spiral Matrix.
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return res;
		}

		int top = 0, bottom = matrix.size(), left = 0, right = matrix[0].size();
		while (true)
		{
			// →
			for (int i = left; i < right; ++i)
			{
				res.push_back(matrix[top][i]);
			}
			if (++top >= bottom) break;

			// ↓
			for (int i = top; i < bottom; ++i)
			{
				res.push_back(matrix[i][right - 1]);
			}
			if (--right <= left) break;

			// ←
			for (int i = right - 1; i >= left; --i)
			{
				res.push_back(matrix[bottom - 1][i]);
			}
			if (--bottom <= top) break;

			// ↑
			for (int i = bottom - 1; i >= top; --i)
			{
				res.push_back(matrix[i][left]);
			}
			if (++left >= right) break;
		}
		return res;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<int> a1{ 1,2,3,4 };
	vector<int> a2{ 5,6,7,8 };
	vector<int> a3{ 9,10,11,12 };
	vector<vector<int>> temp{ a1, a2, a3 };
	s.spiralOrder(temp);
}