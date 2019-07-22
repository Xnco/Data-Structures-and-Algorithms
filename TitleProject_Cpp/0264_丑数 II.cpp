
#pragma region 264_丑数 II
/*
编写一个程序，找出第 n 个丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 4 ms, faster than 96.39% of C++ online submissions for Ugly Number II.
	//Memory Usage : 8.3 MB, less than 93.09 % of C++ online submissions for Ugly Number II.
	// array 比 vector 更快一点
	int nthUglyNumber(int n) {
		//vector<int> dp(n);
		//dp[0] = 1;
		int dp[1691] = { 1 };
		int multiple2 = 0;
		int multiple3 = 0;
		int multiple5 = 0;

		for (int i = 1; i < n; i++)
		{
			int num2 = dp[multiple2] * 2;
			int num3 = dp[multiple3] * 3;
			int num5 = dp[multiple5] * 5;

			int next = min(num2, min(num3, num5));
			if (next == num2)
			{
				multiple2++;
			}
			if (next == num3)
			{
				multiple3++;
			}
			if (next == num5)
			{
				multiple5++;
			}
			dp[i] = next;
		}
		return dp[n - 1];
	}
};
#pragma endregion
