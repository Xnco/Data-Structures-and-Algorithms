
#pragma region 69_x的平方根
/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime : 0 ms, faster than 100.00 % of C++ online submissions for Sqrt(x).
	//Memory Usage : 5.9 MB, less than 100.00 % of C++ online submissions for Sqrt(x).
	int mySqrt(int x) {
		int res = 0;
		int l = 0, r = x; // 46340² < INT_MAX
		if (x == 0) return res;

		while (l <= r)
		{
			int mid = 0;
			if ((l + r) / 2 > 46341)
			{
				r = 46341;
				mid = 46341;
			}
			else
			{
				mid = (l + r) / 2;
			}
			if ((long long)mid * mid > x)
			{
				r = mid - 1;
			}
			else
			{
				res = mid;
				l = mid + 1;
			}
		}
		return res;
	}
};
#pragma endregion
int main()
{
	Solution s;
	s.mySqrt(2147395600);
}