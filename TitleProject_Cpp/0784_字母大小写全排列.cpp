
#pragma region 784_字母大小写全排列
/*
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
输入: S = "3z4"
输出: ["3z4", "3Z4"]
输入: S = "12345"
输出: ["12345"]
注意：
S 的长度不超过12。
S 仅由数字和字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 回溯
	//Runtime: 8 ms, faster than 88.13% of C++ online submissions for Letter Case Permutation.
	//Memory Usage : 12.4 MB, less than 97.06 % of C++ online submissions for Letter Case Permutation.
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		if (S.size() == 0) return res;
		dfs(S, "", 0, res);
		return res;
	}

	void dfs(string S, string cur, int index, vector<string>& res)
	{
		if (index == S.size())
			res.push_back(cur + S[index]);
		else
			dfs(S, cur + S[index], index + 1, res);

		// if (S[index] < '0' || S[index] > '9')
		if (isalpha(S[index]))
		{
			cur += (S[index] ^ 32);
			if (index == S.size() - 1)
				res.push_back(cur);
			else
				dfs(S, cur, index + 1, res);
		}
	}

	// 原地修改dfs
	void letter_dfs(string& S, int index, vector<string>& res)
	{
		if (S.size() == index)
		{
			res.push_back(S);
			return;
		}

		letter_dfs(S, index + 1, res);
		if (isalpha(S[index]))
		{
			S[index] ^= 32;
			letter_dfs(S, index + 1, res);
			S[index] ^= 32;
		}
	}
};
#pragma endregion
