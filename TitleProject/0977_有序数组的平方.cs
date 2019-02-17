using System;

public class Class1
{
	public Class1()
	{
        SortedSquares2(new int[] { -1, 2, 2 });
    }

    #region 977_有序数组的平方 
    /*
    给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
    示例 1：
    输入：[-4,-1,0,3,10]
    输出：[0,1,9,16,100]
    示例 2：
    输入：[-7,-3,2,3,11]
    输出：[4,9,9,49,121]
    提示：
    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A 已按非递减顺序排序。
    */
    // Brute force - 512ms(击败了79%),27.2MB(空间复杂度为0,击败了100%)
    static int[] SortedSquares(int[] A)
    {
        for (int i = 0; i < A.Length; i++)
        {
            A[i] *= A[i];
        }
        Array.Sort(A);
        return A;
    }

    // 解法二 - 双指针 - 524ms, 27.6MB (貌似更慢了我也是醉了)
    static int[] SortedSquares2(int[] A)
    {
        int mid = 0;
        for (int i = 0; i < A.Length; i++)
        {
            if (A[i] >= 0)
            {
                mid = i;
                break;
            }
        }

        if (mid == 0)
        {
            for (int i = 0; i < A.Length; i++)
            {
                A[i] *= A[i];
            }
            return A;
        }
        else
        {
            // 双指针
            int[] array = new int[A.Length];
            int left = mid - 1;
            int right = mid;
            int index = 0;
            while (left >= 0 && right < A.Length)
            {
                if (left >= 0 && right < A.Length)
                {
                    if (Math.Abs(A[left]) < A[right])
                    {
                        array[index] = A[left] * A[left];
                        left--;
                    }
                    else
                    {
                        array[index] = A[right] * A[right];
                        right++;
                    }
                    index++;
                }
            }

            if (left < 0)
            {
                while (right < A.Length)
                {
                    array[index] = A[right] * A[right];
                    right++;
                    index++;
                }
            }
            else
            {
                while (left >= 0)
                {
                    array[index] = A[left] * A[left];
                    left--;
                    index++;
                }
            }
            return array;
        }
    }
    #endregion
}
