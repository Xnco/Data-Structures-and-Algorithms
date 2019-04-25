
#pragma region 258_各位相加
/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
示例:
输入: 38
输出: 2
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

class Solution {
public:
	// 1. 直接硬算 - 4ms(100%), 8.4MB(7.44%)
	int addDigits(int num) {
		while (true)
		{
			int sum = 0;
			while (num != 0)
			{
				int n = num % 10;
				sum += n;
				num /= 10;
			}
			if (sum < 10)
			{
				return sum;
			}
			num = sum;
		}
	}

	// 2 找规律 - O(1) 4ms(100%, 8.3MB(20%)
	int addDigits(int num) {
		if (num > 9)
		{
			int res = num % 9;
			if (res == 0)
			{
				return 9;
			}
			return res;
		}
		return num;

		return num > 9 ? num % 9 != 0 ? num % 9 : 9 : num;
	}
};
#pragma endregion
