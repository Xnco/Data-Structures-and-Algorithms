using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4_寻找两个有序数组的中位数
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(FindMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4 }));
        }

        //4. 寻找两个有序数组的中位数
        public static double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            // 暴力
            //List<int> all = new List<int>();
            //for (int i = 0; i < nums1.Length; i++)
            //{
            //    all.Add(nums1[i]);
            //}

            //for (int i = 0; i < nums2.Length; i++)
            //{
            //    all.Add(nums2[i]);
            //}

            //all.Sort();

            //if (all.Count % 2 == 0)
            //{
            //    int middle = all.Count / 2;
            //    return (all[middle] + all[middle - 1]) / 2f;
            //}
            //else
            //{
            //    return all[all.Count / 2];
            //}

            if (nums1.Length + nums2.Length % 2 == 0)
            {
                // 偶数
            }
            else
            {
                // 奇数
            }

            return 0;
        }
    }
}
