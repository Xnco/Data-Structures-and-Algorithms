
#pragma region 448_找到所有数组中消失的数字
/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
示例:
输入:
[4,3,2,7,8,2,3,1]
输出:
[5,6]
*/

class Solution {
public:
	// 没变0的下标就是缺失的
	// 104ms(97.04%), 15MB(63.94%)
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (auto item : nums)
		{
			nums[abs(item) - 1] = -abs(nums[abs(item) - 1]);
		}
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				res.push_back(i + 1);
			}
		}
		return res;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	s.findDisappearedNumbers(v);
}
