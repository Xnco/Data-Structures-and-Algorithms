
#pragma region 912_排序数组
/*
给定一个整数数组 nums，将该数组升序排列。
示例 1：
输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：
输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
提示：
1 <= A.length <= 10000
-50000 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 不要重复造轮子
	//Runtime: 52 ms, faster than 97.56% of C++ online submissions for Sort an Array.
	//Memory Usage : 12.5 MB, less than 94.44 % of C++ online submissions for Sort an Array.
	vector<int> sortArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums;
	}
};
#pragma endregion
