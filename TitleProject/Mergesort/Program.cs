using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mergesort
{
    // 归并排序(mergesort) O(N log N)
    // 合并两个已排序的表，把两者间最小的放到新数组中，重复至最后
    // 分治， 两两处理好了， 四四就处理好了， 所有的都处理好了

    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 34, 8, 64, 51, 32, 21 };
            //int[] array = { 34, 8, 64, 51 };
            Mergesort(array, array.Length);

            foreach (var item in array)
            {
                Console.WriteLine(item);
            }
        }

        static void Mergesort(int[] array, int N)
        {
            int[] targetArray = new int[N]; // 存放的新数组

            MSort(array, targetArray, 0, N - 1);
        }

        // 将一个数组分两半 -> 将排序好的结果放到 targetArray 中
        static void MSort(int[] array, int[] targetArray, int left, int right)
        {
            // 至少有两个数才有得分
            if (left < right)
            {
                int center = (left + right) / 2;
                MSort(array, targetArray, left, center);
                MSort(array, targetArray, center + 1, right);
                //Merge(array, targetArray, left, center + 1, right);
                Merge2(array, targetArray, left, center + 1, right);
            }
        }

        static void Merge(int[] array, int[] targetArray, int left, int center, int right)
        {
            int begin_Left = left;
            int begin_Right = center;
            for (int i = left; i <= right; i++)
            {
                // 取两段数组中更小的那个，取到后往后推一个
                if (array[begin_Left] < array[begin_Right])
                {
                    // 取左边的
                    targetArray[i] = array[begin_Left];
                    begin_Left++;
                    if (begin_Left == center)
                    {
                        // 左边取完了 -- 将右边直接填进新数组
                        for (int j = begin_Right; j <= right; j++)
                        {
                            i++;
                            targetArray[i] = array[j];
                        }
                        break;
                    }
                }
                else
                {
                    targetArray[i] = array[begin_Right];
                    begin_Right++;
                    if (begin_Right == right + 1)
                    {
                        // 右边取完了 -- 将左边直接填进新数组
                        for (int j = begin_Left; j < center; j++)
                        {
                            i++;
                            targetArray[i] = array[j];
                        }
                        break;
                    }
                }
            }

            //target 完成后还要更新老数组
            for (int i = left; i <= right; i++)
            {
                array[i] = targetArray[i];
            }
        }

        static void Merge2(int[] array, int[] targetArray, int left, int center, int right)
        {
            int begin_Left = left;
            int begin_Right = center;

            int real = left;
            //for (int i = left; i <= right; i++)
            for (; begin_Left <= center && begin_Right <= right; real++)
            {
                // 取两段数组中更小的那个，取到后往后推一个 -> 直到一方取完为止
                if (array[begin_Left] < array[begin_Right])
                {
                    // 取左边的
                    targetArray[real] = array[begin_Left];
                    begin_Left++;
                }
                else
                {
                    // 取右边的
                    targetArray[real] = array[begin_Right];
                    begin_Right++;
                }
            }

            // 左边取完了 -- 将右边剩下的填进新数组
            for (int i = begin_Right; i <= right; i++)
            {
                targetArray[real] = array[i];
                real++;
            }

            // 右边取完了 -- 将左边剩下的填进新数组
            for (int i = begin_Left; i < center; i++)
            {
                targetArray[real] = array[i];
                real++;
            }

            //target 完成后还要更新老数组
            for (int i = left; i <= right; i++)
            {
                array[i] = targetArray[i];
            }
        }
    }
}
