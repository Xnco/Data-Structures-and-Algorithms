
#pragma region 0081_搜索旋转排序数组_II
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return true;
			}
		}
		return false;
	}

	// 解法2 在33题的基础上增加一个去重复的循环即可
	bool search2(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
		{
			return fasle;
		}

		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			while (left != right && nums[left] == nums[right])
			{
				right--;// 有重复值的情况右值往左移动到不重复为止
			}
			int mid = (left + right) / 2;
			if (nums[mid] == target)
			{
				return true;
			}

			// 要先判断左边是连续的还是右边是连续的
			if (nums[mid] >= nums[0])
			{
				// 左边是连续的
				if (target >= nums[left] && target < nums[mid]) // 判断target是否在左边
				{
					// in left 
					right = mid - 1;
				}
				else
				{
					// in right
					left = mid + 1;
				}
			}
			else
			{
				// 右边是连续的
				if (target <= nums[right] && target > nums[mid]) // 判断target是否在左边
				{
					// in right
					left = mid + 1;
				}
				else
				{
					// in left 
					right = mid - 1;
				}
			}
		}
		return fasle;
	}
};
#pragma endregion
