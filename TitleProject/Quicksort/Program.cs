using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quicksort
{
    class Program
    {
        // 快速排序 - O(N log N)的复杂度
        // 对于很小的数组(N <= 20)， 快速排序不如插入排序好，但是一旦数据很大并且是混乱的，快速排序则是最优解

        // 关于 枢纽元 的选择
        // 选择第一个为枢纽元。如果输入是随机的，这样是可以接受的，但如果输入是预排序或者是反序的，那么枢纽元就产生了一个劣质的分割
        // 如果用随机数的话，随机数的生成一般比较消耗性能，很多时候得不偿失
        // 最终方案：三数中值分割法(Median-of-Three Partitioning), 取 left, right, (lefe+right)/2的中值，减少5%的运行时间
        // 所以方案1可以，但是不是很好

        static void Main(string[] args)
        {
            int[] list = {  11, 55, 3, 23, 59, 76, 14, 9 };
            Quicksort2(list, 0, list.Length - 1);

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }
        }

        // 工具方法，交换两数
        static void Swap(int[] list, int a, int b)
        {
            int x = list[a];
            list[a] = list[b];
            list[b] = list[a];
        }

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
        static int Median3(int[] list, int left, int right)
        {
            int center = (left + right) / 2;
            if (list[left] > list[center])
            {
                Swap(list, left, center);
            }
            if (list[left] > list[right])
            {
                Swap(list, left, right);
            }
            if (list[center] > list[right])
            {
                Swap(list, center, right);
            }
            // 将三个数从小到大排序， 中间的自然是中位数了: list[left] <= list[center] <= list[right]

            // 将中位数换到倒数第二个去
            Swap(list, center, right - 1);
            // 返回中位数
            return list[right - 1]; 
        }

        static int CutOff = 10;
        static void Quicksort2(int[] list, int left, int right)
        {
            if (left + CutOff <= right)
            {
                int i = left; // 左
                int j = right; // 右
                int pivot = Median3(list, left, right); // 得到枢纽元

                while (true)
                {
                    while (list[++i] < pivot) { } // 从左边开始找一个比枢纽元要大的就停止
                    while (list[--j] > pivot) { } // 从右边开始找一个比枢纽元要小的就停止
                    if (i < j)
                    {
                        // 没交错之前就找到了，交换位置
                        Swap(list, i, j);
                    }
                    else
                    {
                        // i, j已将交错了，说明两边已经分完了，找到了也不用交换了
                        break;
                    }
                }

                // 两边分完之后， 找到一个比 pivot 大的将 pivot 换回来
                Swap(list, i, right - 1);

                Quicksort2(list, left, i - 1);
                Quicksort2(list, i + 1, right);
            }
            else
            {
                // 数组排序的数字小于10, 就用插入排序
            }
        }

        #endregion
    }
}
