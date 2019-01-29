using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0011_盛最多水的容器
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(MaxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }));
        }

        #region 11_盛最多水的容器 
        /*
        给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

        说明：你不能倾斜容器，且 n 的值至少为 2。

        图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

        示例:

        输入: [1,8,6,2,5,4,8,3,7]
        输出: 49
        */
        // 184ms
        // 双指针两边往中间推进
        static int MaxArea(int[] height)
        {
            int left = 0;
            int right = height.Length - 1;
            int maxArea = 0;

            while (left < right)
            {
                int w = right - left;

                int l_num = height[left];
                int r_num = height[right];

                int h = l_num > r_num ? r_num : l_num;
                int area = w * h;

                maxArea = Math.Max(area, maxArea);

                if (l_num > r_num)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return maxArea;
        }
        #endregion
    }
}
