
#pragma region 845_数组中的最长山脉
/*
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
给出一个整数数组 A，返回最长 “山脉” 的长度。
如果不含有 “山脉” 则返回 0。
示例 1：
输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
示例 2：
输入：[2,2,2]
输出：0
解释：不含 “山脉”。

提示：
0 <= A.length <= 10000
0 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-mountain-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 暴力, 将每种情况考虑. 很慢, 192ms(5%), 9.9MB(80%)
	int longestMountain(vector<int>& A) {
		if (A.size() < 3)
		{
			return 0;
		}

		int res = 0;
		for (int i = 1; i < A.size() - 1; i++)
		{
			int left = i;
			while (left - 1 >= 0 && A[left - 1] < A[left])
			{
				left--;
			}
			if (left == i)
			{
				continue;
			}
			int right = i;
			while (right + 1 < A.size() && A[right] > A[right + 1])
			{
				right++;
			}
			if (right == i)
			{
				continue;
			}
			res = max(res, right - left + 1);
			i = right;
		}
		return res;
	}
};
#pragma endregion

int main()
{
	// 1 4 7 3 2

	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(7);
	v.push_back(3);
	v.push_back(2);
	Solution s;
	s.longestMountain(v);
}