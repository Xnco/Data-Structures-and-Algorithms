
#pragma region 763_划分字母区间
/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
示例 1:
输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
注意:
S的长度在[1, 500]之间。
S只包含小写字母'a'到'z'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 4ms(97.39%), 8.6MB(81.72%)
	vector<int> partitionLabels(string S) {
		vector<int> res;
		int maxArray[26] = { 0 };

		for (auto i = 0; i < S.size(); i++)
			maxArray[S[i] - 'a'] = i;

		int left = 0;
		while (left < S.length())
		{
			int init = left;
			int right = maxArray[S[left] - 'a'];
			while (left < right)
			{
				left++;
				if (right < maxArray[S[left] - 'a'])
				{
					// 更新右边界
					right = maxArray[S[left] - 'a'];
				}
			}
			res.push_back(++left - init);
		}
		return res;
	}
};
#pragma endregion
