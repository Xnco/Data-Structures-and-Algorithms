using System;

public class Class1
{
    // 快速排序 - O(N log N)的复杂度
    // 对于很小的数组(N <= 20)， 快速排序不如插入排序好，但是一旦数据很大并且是混乱的，快速排序则是最优解

    // 关于 枢纽元 的选择
    // 选择第一个为枢纽元。如果输入是随机的，这样是可以接受的，但如果输入是预排序或者是反序的，那么枢纽元就产生了一个劣质的分割
    // 如果用随机数的话，随机数的生成一般比较消耗性能，很多时候得不偿失
    // 最终方案：三数中值分割法(Median-of-Three Partitioning), 取 left, right, (lefe+right)/2的中值，减少5%的运行时间 -> 方案2
    // 所以方案1可以，但是不是很好

    #region 方案1
    static void QuickSort1(int[] list, int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        // 将数组分成两边, 一边大于x, 一边小于x, 返回x的位置
        int center = SortAndGetCenter(list, left, right);

        // 左边再排序
        QuickSort1(list, left, center);
        // 右边再排序
        QuickSort1(list, center + 1, right);
    }

    static int SortAndGetCenter(int[] list, int left, int right)
    {
        int target = list[left];

        bool isRight = true;
        while (left < right)
        {
            if (isRight)
            {
                if (list[right] < target)
                {
                    list[left] = list[right];
                    isRight = false;
                }
                else
                {
                    right--;
                }
            }
            else
            {
                if (list[left] > target)
                {
                    list[right] = list[left];
                    isRight = true;
                }
                else
                {
                    left++;
                }
            }
        }
        list[left] = target;
        return left;
    }

    #endregion

    #region 方案2
    // 三数中值分割法(Median-of-Three Partitioning), 取 left, right, (lefe + right)/2的中值，减少5%的运行时间
    // 返回中位数，并且它在倒数第二个位置上
    static void QuickSort(int[] arr)
    {
        QuickSort(arr, 0, arr.Length - 1);
    }

    // static int CutOff = 10; 可以加个限制, 当数量小于一定值时用选择排序减少复杂度
    static void QuickSort(int[] arr, int left, int right)
    {
        if (left >= right) return;
        int center = (left + right) / 2;
        // 将三个数从小到大排序， 中间的自然是中位数了: list[left] <= list[center] <= list[right]
        if (arr[left] > arr[center]) Swap(arr, left, center);
        if (arr[left] > arr[right]) Swap(arr, left, right);
        if (arr[center] > arr[right]) Swap(arr, center, right);

        Swap(arr, center, right - 1);
        int l = left, r = right - 1, point = right - 1;
        while (l < r)
        {
            while (arr[++l] < arr[point]) ;
            while (arr[--r] > arr[point]) ;
            if (l < r)
            {
                Swap(arr, l, r);
            }
        }
        Swap(arr, l, point); // 将中位数从倒数第二个换回来
        QuickSort(arr, left, l - 1);
        QuickSort(arr, l + 1, right);
    }

    #endregion
}
