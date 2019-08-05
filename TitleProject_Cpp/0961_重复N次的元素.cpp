
#pragma region 961_重复 N 次的元素
/*
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
返回重复了 N 次的那个元素。
示例 1：
输入：[1,2,3,3]
输出：3
示例 2：
输入：[2,1,2,5,3,2]
输出：2
示例 3：
输入：[5,1,5,2,5,3,5,4]
输出：5
提示：
4 <= A.length <= 10000
0 <= A[i] < 10000
A.length 为偶数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	// 没有额外空间
	//Runtime: 40 ms, faster than 86.07% of C++ online submissions for N-Repeated Element in Size 2N Array.
	//Memory Usage : 10.8 MB, less than 61.65 % of C++ online submissions for N - Repeated Element in Size 2N Array.
	int repeatedNTimes(vector<int>& A) {
		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (A[i] == A[i + 1]) return A[i];
		}
		if (A[0] == A.back()) return A[0];
		return A[0] == A[2] ? A[0] : A[1];
	}
};
#pragma endregion
