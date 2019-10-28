
#pragma region 896_单调数列
/*
如果数组是单调递增或单调递减的，那么它是单调的。
如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。
如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。
当给定的数组 A 是单调数组时返回 true，否则返回 false。

示例 1：
输入：[1,2,2,3]
输出：true

示例 2：
输入：[6,5,4,4]
输出：true

示例 3：
输入：[1,3,2]
输出：false

示例 4：
输入：[1,2,4,5]
输出：true

示例 5：
输入：[1,1,1]
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 80 ms, faster than 84.81% of C++ online submissions for Monotonic Array.
	//Memory Usage : 13.8 MB, less than 100.00 % of C++ online submissions for Monotonic Array.
	bool isMonotonic(vector<int>& A) {
		if (A.size() < 3)
		{
			return true;
		}

		int difference = A[1] - A[0];
		for (size_t i = 1; i < A.size() - 1; i++)
		{
			int newDiff = A[i + 1] - A[i];
			if (difference * newDiff < 0)
			{
				return false;
			}

			if (newDiff != 0)
			{
				difference = newDiff;
			}
		}
		return true;
	}
};
#pragma endregion
