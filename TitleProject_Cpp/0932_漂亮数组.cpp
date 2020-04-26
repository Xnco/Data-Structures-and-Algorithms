
#pragma region 932_漂亮数组
/*
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
那么数组 A 是漂亮数组。
给定 N，返回任意漂亮数组 A（保证存在一个）。

示例 1：
输入：4
输出：[2,1,4,3]

示例 2：
输入：5
输出：[3,1,2,5,4]

提示：
1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime : 12 ms, faster than 38.62 % of C++ online submissions for Beautiful Array.
	//Memory Usage : 7.9 MB, less than 100.00 % of C++ online submissions for Beautiful Array.
	map<int, vector<int>> memo;

	vector<int> beautifulArray(int N) {
		return GetArray(N);
	}

	vector<int> GetArray(int N)
	{
		if (memo.find(N) != memo.end())
		{
			return memo[N];
		}

		vector<int> res(N);
		if (N == 1)
		{
			res[0] = 1;
		}
		else
		{
			int t = 0;
			vector<int> odds = GetArray((N + 1) / 2);
			for (size_t i = 0; i < odds.size(); ++i)
			{
				res[t++] = 2 * odds[i] - 1;
			}
			vector<int> evens = GetArray(N / 2);
			for (size_t i = 0; i < evens.size(); ++i)
			{
				res[t++] = 2 * evens[i];
			}
			memo[N] = res;
		}
		return res;
	}
};

#pragma endregion
