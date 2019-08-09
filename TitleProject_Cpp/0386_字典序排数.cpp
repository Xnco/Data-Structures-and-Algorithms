
#pragma region 386_字典序排数
/*
给定一个整数 n, 返回从 1 到 n 的字典顺序。
例如，
给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographical-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 84 ms, faster than 30.37% of C++ online submissions for Lexicographical Numbers.
	//Memory Usage : 11.7 MB, less than 72.73 % of C++ online submissions for Lexicographical Numbers.
	vector<int> lexicalOrder(int n) {
		vector<int> res;
		for (int i = 1; i < 10; ++i)
		{
			Loop(res, i, n);
		}
		return res;
	}

	void Loop(vector<int>& res, int begin, int n)
	{
		if (begin <= n)
		{
			res.push_back(begin);
		}
		else
		{
			return;
		}
		for (int i = 0; i < 10; ++i)
		{
			int value = begin * 10 + i;
			Loop(res, value, n);
			break;
		}
	}

	//Runtime: 68 ms, faster than 91.62% of C++ online submissions for Lexicographical Numbers.
	//Memory Usage : 11.7 MB, less than 72.73 % of C++ online submissions for Lexicographical Numbers.
	vector<int> lexicalOrder(int n) {
		vector<int> res;
		for (int i = 1; i < 10; ++i)
		{
			if (i <= n)
			{
				Loop(res, i, n);
			}
		}
		return res;
	}

	void Loop(vector<int>& res, int begin, int n)
	{
		res.push_back(begin);

		for (int i = 0; i < 10; ++i)
		{
			int value = begin * 10 + i;
			if (value <= n)
			{
				Loop(res, value, n);
			}
			else
			{
				break;
			}
		}
	}
};
#pragma endregion
