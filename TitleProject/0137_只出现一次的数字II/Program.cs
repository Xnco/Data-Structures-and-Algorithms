using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0137_只出现一次的数字II
{
    class Program
    {
        static void Main(string[] args)
        {

        }

        #region 137_只出现一次的数字II
        /*
        给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
    
        说明：
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

        示例 1:
            输入: [2,2,3,2]
            输出: 3

        示例 2:
            输入: [0,1,0,1,0,1,99]
            输出: 99
        */
        // 记录所有数字的算法，需要额外的开销 - 240ms
        public int singleNumber(int[] nums)
        {
            Dictionary<int, int> all = new Dictionary<int, int>();
            foreach (var item in nums)
            {
                if (all.ContainsKey(item))
                {
                    all[item]++;
                }
                else
                {
                    all.Add(item, 1);
                }
            }

            foreach (var item in all)
            {
                if (item.Value == 1)
                {
                    return item.Key;
                }
            }
            return 0;
        }

        // 160ms
        // 亦或解法 - 思路如下
        /*
        网上大佬曾经说，如果能设计一个状态转换电路，使得一个数出现3次时能自动抵消为0，最后剩下的就是只出现1次的数。
        开始设计：一个二进制位只能表示0或者1。也就是天生可以记录一个数出现了一次还是两次。
            x ^ 0 = x;
            x ^ x = 0;
        要记录出现3次，需要两个二进制位。那么上面单独的x就不行了。我们需要两个变量，每个变量取一位：
            ab ^ 00 = ab;
            ab ^ ab = 00;
        这里，a、b都是32位的变量。我们使用a的第k位与b的第k位组合起来的两位二进制，表示当前位出现了几次。也就是，一个8位的二进制x就变成了16位来表示。
            x = x[7] x[6] x[5] x[4] x[3] x[2] x[1] x[0]
            x = (a[7]b[7]) (a[6]b[6]) ... (a[1]b[1]) (a[0]b[0])
        于是，就有了这一幕....
        它是一个逻辑电路，a、b变量中，相同位置上，分别取出一位，负责完成00->01->10->00，也就是开头的那句话，当数字出现3次时置零。
        */
        public int singleNumber2(int[] nums)
        {
            int a = 0, b = 0;
            foreach (var x in nums)
            {
                a = (a ^ x) & ~b;
                b = (b ^ x) & ~a;
            } 
            return a;
        }
        #endregion
    }
}
