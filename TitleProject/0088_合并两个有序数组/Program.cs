using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0088_合并两个有序数组
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 88_合并两个有序数组 
        /*
        给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
        说明:
            初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
            你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

        示例:
        输入:
        nums1 = [1,2,3,0,0,0], m = 3
        nums2 = [2,5,6],       n = 3
        输出: [1,2,2,3,5,6]
        */
        // 556ms
        // 解法1： 插入数据，将数组二中的每个数据插入到合适的位置
        static void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            // 遍历数组2
            for (int i = 0; i < n; i++)
            {
                // 将数组2中的每个数插入到数组1中
                Insert(nums1, m, nums2[i]);
                m++;
            }
        }

        static void Insert(int[] array, int m, int target)
        {
            // 插入到对应位置
            for (int i = 0; i < m; i++)
            {
                if (array[i] > target)
                {
                    // 如果有个数字比目标数字要大，就将数字往后移
                    MoveToBack(array, i, m);
                    array[i] = target;
                    return;
                }
            }

            // 如果目标数字比所有数字都大， 就放到最后
            array[m] = target;
        }

        // 数组数据往后移
        static void MoveToBack(int[] nums, int index, int m)
        {
            for (int i = m - 1; i >= index && i < nums.Length; i--)
            {
                nums[i + 1] = nums[i];
            }
        }

        // 468ms
        // 解法二：将两个数组拼在一起再排序
        static void Merge2(int[] nums1, int m, int[] nums2, int n)
        {
            for (int i = m; i < n + m; i++)
            {
                nums1[i] = nums2[i - m];
            }

            Array.Sort(nums1);
        }

        #endregion
    }
}
