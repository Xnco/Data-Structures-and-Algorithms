using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearch
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 二分查找 - Binary Search 
        /*
          当序列排好序时效率最高 O(logN)
        */
        static bool BinarySearch(int[] array, int target)
        {
            int left = 0;
            int right = array.Length - 1;

            while (left < right)
            {
                int mid = left + right / 2;
                if (array[mid] > target)
                {
                    // 中间的数比目标大， 右边的被舍弃
                    right = mid - 1;
                }
                else if (array[mid] < target)
                {
                    // 中间的数比目标小， 左边的被舍弃
                    left = mid + 1;
                }
                else
                {
                    // 相等说明找到了
                    return true;
                }
            }
            return false;
        }
        #endregion
    }
}
