
#pragma region 821_字符的最短距离
/*
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
示例 1:
输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:
字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime : 12 ms, faster than 63.32 % of C++ online submissions for Shortest Distance to a Character.
	//Memory Usage : 8.7 MB, less than 90.91 % of C++ online submissions for Shortest Distance to a Character.
	// 两次遍历, 分别得到离左右两个C的距离, 取小的那个
	vector<int> shortestToChar(string S, char C) {
		vector<int> res(S.size(), -1);
		int previous = -1;
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == C)
			{
				res[i] = 0;
				previous = i; // 记录下上个C的位置
			}
			else if (previous != -1)
			{
				res[i] = previous - i; // 记录到右边的C的距离
			}
		}
		previous = -1;
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == C)
			{
				previous = i; // 记录下上个C的位置
			}
			else if (res[i] == -1)
			{
				res[i] = i - previous;
			}
			else if (previous != -1)
			{
				res[i] = min(res[i], i - previous); // 从左边位置
			}
		}
		return res;
	}
};
#pragma endregion
