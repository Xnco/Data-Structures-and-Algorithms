
#pragma region 50_Pow(x,n)
/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		return N >= 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
	}

	// 递归
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
	//Memory Usage : 6.1 MB, less than 100.00 % of C++ online submissions for Pow(x, n).
	double quickMul(double x, long long N)
	{
		if (N == 0)
		{
			return 1;
		}
		double y = quickMul(x, N / 2);
		return (N & 1) == 0 ? y * y * x : y * y;
	}

	// 迭代
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
	//Memory Usage : 5.9 MB, less than 100.00 % of C++ online submissions for Pow(x, n).
	double quickMul(double x, long long N) {
		double orgin = x;
		double res = 1;
		while (N > 0)
		{
			if (N % 2 != 0)
			{
				res *= orgin;
			}

			orgin *= orgin;
			N /= 2;
		}
		return res;
	}
};
#pragma endregion
