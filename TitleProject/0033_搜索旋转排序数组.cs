using System;

public class Class1
{
	public Class1()
	{
	}
    #region 33_搜索旋转排序数组 
    /*
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
    你可以假设数组中不存在重复的元素。
    你的算法时间复杂度必须是 O(log n) 级别。

    示例 1:
    输入: nums = [4,5,6,7,0,1,2], target = 0
    输出: 4
    示例 2:
    输入: nums = [4,5,6,7,0,1,2], target = 3
    输出: -1
    */
    // 不符合题意 - 时间复杂度O(N) - 148ms(击败69% :O )，22.4MB
    static int Search(int[] nums, int target)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    // 一部分没有排序，所以不能直接二分， 先找到旋转的节点，后面部分再二分
    // 152ms, 22.3MB, 失败中的失败，比O(N)还慢？
    static int Search2(int[] nums, int target)
    {
        if (nums.Length == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
            else if (i != nums.Length - 1 && nums[i] > nums[i + 1])
            {
                // 前一个数比后一个数要打，说明旋转节点找到了， 剩下的部分二分 i+1 -> L-1
                int begin = i + 1;
                int end = nums.Length - 1;
                while (begin < end)
                {
                    int mid = (begin + end) / 2;
                    if (nums[mid] > target)
                    {
                        end = mid - 1;
                    }
                    else if (nums[mid] < target)
                    {
                        begin = mid + 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
                return -1;
            }
        }
        return -1;
    }

    // 思路三
    static int Search3(int[] nums, int target)
    {
        int left = 0;
        int right = nums.Length - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // 前半段是无序的
            else if (nums[mid] < target)
            {
                // target 在后半段，直接二分 mid - right
                if (true)
                {

                }
                else
                {
                    // target 在前半段，无序的不能二分，继续吧，感觉用递归也可以
                    left = mid;
                }
            }
            else
            {
                // 后半段无序的
            }
        }
        return -1;
    }
    #endregion
}
