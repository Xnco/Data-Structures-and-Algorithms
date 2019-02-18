using System;

public class Class1
{
	public Class1()
	{
	}

    #region 905_按奇偶排序数组 
    /*
    给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
    你可以返回满足此条件的任何数组作为答案。

    示例：
    输入：[3,1,2,4]
    输出：[2,4,3,1]
    输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
    提示：

        1 <= A.length <= 5000
        0 <= A[i] <= 5000
    */
    // 380ms - 击败93.49%, 19.2MB
    static int[] SortArrayByParity(int[] A)
    {
        int[] array = new int[A.Length];
        int left = 0;
        int right = array.Length - 1;
        for (int i = 0; i < A.Length; i++)
        {
            if (A[i] % 2 == 0)
            {
                array[left] = A[i];
                left++;
            }
            else
            {
                array[right] = A[i];
                right--;
            }
        }
        return array;
    }
    #endregion
}
