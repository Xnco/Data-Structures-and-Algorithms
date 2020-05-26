using System;

public class Class1
{
	public Class1()
	{
        FindDuplicate(new int[] { 3, 1, 3, 4, 2 });
    }

    #region 287_寻找重复数
    /*
    给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
    假设只有一个重复的整数，找出这个重复的数。

    示例 1:
    输入: [1,3,4,2,2]
    输出: 2

    示例 2:
    输入: [3,1,3,4,2]
    输出: 3
    说明：

    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。
    时间复杂度小于 O(n²) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。
    */

    //  160ms 10MB 
    // 直接for遍历不行，brute force的时间复杂度是O(n²)，不符合题意
    // 用 二分搜索法 例如： 长度为5，数组中必定有1234，mid = 2
    // 如果比2小的不止2个，所有重复的一定<=2，如果比2小的只有2个，所有重复的>2
    static int FindDuplicate(int[] nums)
    {
        //int left = 0;
        //int right = nums.Length - 1;

        //return 0;

        int left = 0, right = nums.Length;
        while (left < right)
        {
            int mid = left + (right - left) / 2, cnt = 0;
            foreach (int num in nums)
            {
                if (num <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    // 解法2 快慢指针
    //Runtime: 96 ms, faster than 82.87% of C# online submissions for Find the Duplicate Number.
    //Memory Usage: 25.3 MB, less than 20.00% of C# online submissions for Find the Duplicate Number.
    static int FindDuplicate(int[] nums)
    {
        int slow = 0; int fast = 0;
        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (nums[slow] != nums[fast]);

        slow = 0;
        while (nums[slow] != nums[fast])
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return nums[slow];
    }

    // http://www.cnblogs.com/grandyang/p/4843654.html - 这个博客有第三种解法

    #endregion
}
