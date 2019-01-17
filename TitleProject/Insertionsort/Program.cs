using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Insertionsort
{
    // 插入排序 - 最简单的排序算法之一。(还有冒泡和选择排序) 复杂度都是 O(N²)

    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 34, 8, 64, 51, 32, 21 };
            Insertionsort(array);

            foreach (var item in array)
            {
                Console.WriteLine(item);
            }
        }

        static void Insertionsort(int[] array)
        {
            for (int i = 1; i < array.Length; i++)
            {
                // 将要插入的值记录下来
                int target = array[i];

                // 倒着遍历， 直到 0
                int j = i - 1;
                for (; j >= 0 && array[j] > target; j--)
                {
                    // 比目标要大的就将数字往后移动一格
                    array[j + 1] = array[j];
                }

                // 将要插入的值插入到对应的位置 -> 数字不再比 target 大了，所以就插到这里
                array[j + 1] = target;
            }
        }
    }
}
