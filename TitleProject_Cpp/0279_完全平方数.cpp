
#pragma region 279_完全平方数
/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
示例 1:
输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:
输入: n = 13
输出: 2
解释: 13 = 4 + 9.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// dp, 遍历每种情况, 找到最小值
	//Runtime : 108 ms, faster than 49.55 % of C++ online submissions for Perfect Squares.
	//Memory Usage : 11.4 MB, less than 61.54 % of C++ online submissions for Perfect Squares.
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j * j <= i; ++j)
			{
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}

	// 四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。 
	// 推论：满足四数平方和定理的数n（四个整数的情况），必定满足 n=4^a(8b+7)
	//Runtime: 4 ms, faster than 97.00 % of C++ online submissions for Perfect Squares.
	//Memory Usage : 8.2 MB, less than 100.00 % of C++ online submissions for Perfect Squares.
	int numSquares(int n) {
		while (n % 4 == 0) n /= 4;
		if (n % 8 == 7) return 4;
		for (int i = 0; i * i < n; i++) {
			int b = sqrt(n - i * i);
			if (i * i + b * b == n)return !!i + !!b;
		}
		return 3;
	}
};
#pragma endregion
