
#pragma region 0033_搜索旋转排序数组
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 复杂度 O(log n) 
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return -1;
		}

		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
			{
				return mid;
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
		return -1;
	}
};
#pragma endregion
