
#pragma region 221_���������
/*
��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ��������������

ʾ��:

����:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

���: 4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximal-square
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	// �������Թ���
	// ֱ�Ӷ�̬�滮 dp[i,j]��ʾ��i,jΪ���������½ǵı߳�
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
