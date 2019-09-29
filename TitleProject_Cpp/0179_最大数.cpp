
#pragma region 179_最大数
/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	static bool func_sort_string()
	{
		string res1 = to_string(a);
		string res2 = to_string(b);

		int num1 = atoi((res1 + res2).c_str());
		int num2 = atoi((res2 + res1).c_str());

		return num1 > num2;
	}

	static bool func_sort(const int& a, const int& b)
	{
		long long n_a = 10;
		while (a / n_a) n_a *= 10;
		long long n_b = 10;
		while (b / n_b) n_b *= 10;
		long long r_a = (long long)a * n_b + (long long)b;
		long long r_b = (long long)b * n_a + (long long)a;
		return r_a > r_b;
	}

	//Runtime: 4 ms, faster than 97.89% of C++ online submissions for Largest Number.
	//Memory Usage : 8.8 MB, less than 90.91 % of C++ online submissions for Largest Number.
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), func_sort);
		string str = "";
		bool flag = false;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (!flag)
			{
				if (nums[i] == 0)
				{
					continue;
				}
			}
			flag = true; // 存在非零数
			str += to_string(nums[i]);
		}
		return flag ? str : "0";
	}

};
#pragma endregion
