using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shellsort
{
    class Program
    {
        // 希尔排序(Shellsort) 又名 缩小增量排序 
        // 不断得减少增量 -> 比较得越来越频繁

        static void Main(string[] args)
        {
            int[] array = { 34, 8, 64, 51, 32, 21 };
            Shellsort(array, array.Length);

            foreach (var item in array)
            {
                Console.WriteLine(item);
            }
        }

        static void Shellsort(int[] array, int N)
        {
            for (int increment = N / 2; increment > 0; increment /= 2)
            {
                // 从插值 遍历到 最后
                for (int i = increment; i < N; i++)
                {
                    int temp = array[i];
                    int j = i;
                    for (; j >= increment; j-=increment)
                    {
                        if (temp < array[j-increment])
                        {
                            array[j] = array[j - increment];
                        }
                        else
                        {
                            break;
                        }
                    }
                    array[j] = temp;
                }
            }
        }
    }
}
