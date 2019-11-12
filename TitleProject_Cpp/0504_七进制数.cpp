
#pragma region 504_七进制数
/*
给定一个整数，将其转化为7进制，并以字符串形式输出。

示例 1:

输入: 100
输出: "202"
示例 2:

输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/base-7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	//Runtime : 0 ms, faster than 100.00 % of C++ online submissions for Base 7.
	//Memory Usage : 8.2 MB, less than 100.00 % of C++ online submissions for Base 7.
	string convertToBase7(int num) {
		if (num == 0)
		{
			return "0";
		}
		string res = "";
		string sign = num < 0 ? "-" : "";

		num = abs(num);
		while (num != 0)
		{
			res = to_string(num % 7) + res;
			num /= 7;
		}
		res = sign + res;
		return res;
	}
};
#pragma endregion
