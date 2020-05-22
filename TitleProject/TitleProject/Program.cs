using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static TitleProject.Tool;

namespace TitleProject
{
    class Program
    {
        static void Main(string[] args)
        {
            
        }

        #region 0 
        /*
        
        */
        static void Func()
        {

        }
        #endregion
        #region 27_移除元素 
        /*
        元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
        示例 1:
        给定 nums = [3,2,2,3], val = 3,
        函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
        你不需要考虑数组中超出新长度后面的元素。
        示例 2:
        给定 nums = [0,1,2,2,3,0,4,2], val = 2,
        函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
        注意这五个元素可为任意顺序。
        你不需要考虑数组中超出新长度后面的元素。
        说明:
        为什么返回数值是整数，但输出的答案是数组呢?
        请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
        你可以想象内部操作如下:
        // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
        int len = removeElement(nums, val);
        // 在函数里修改输入数组对于调用者是可见的。
        // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
        for (int i = 0; i < len; i++) {
            print(nums[i]);
        }
        */
        static int RemoveElement(int[] nums, int val)
        {
            int begin = 0;
            int end = nums.Length - 1;
            int count = 0;

            while (begin < end)
            {
                while (nums[end] == val)
                {
                    end--;
                    if (end == 0)
                    {
                        return count;
                    }
                }

                while (nums[begin] != val)
                {
                    begin++;
                    if (begin == nums.Length - 1)
                    {
                        return count;
                    }
                }

                nums[begin] = nums[end];
                count++;
            }
            return count;
        }

        #endregion
        #region 54_螺旋矩阵
        /*
        给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

        示例 1:
        输入:
        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        输出: [1,2,3,6,9,8,7,4,5]

        示例 2:
        输入:
        [
          [1, 2, 3, 4],
          [5, 6, 7, 8],
          [9,10,11,12]
        ]
        输出: [1,2,3,4,8,12,11,10,9,5,6,7]
        */
        //static IList<int> SpiralOrder(int[,] matrix)
        //{

        //}
        #endregion
        #region 61 旋转链表
        /*
        给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

        示例 1:
        输入: 1->2->3->4->5->NULL, k = 2
        输出: 4->5->1->2->3->NULL
        解释:
        向右旋转 1 步: 5->1->2->3->4->NULL
        向右旋转 2 步: 4->5->1->2->3->NULL

        示例 2:
        输入: 0->1->2->NULL, k = 4
        输出: 2->0->1->NULL
        解释:
        向右旋转 1 步: 2->0->1->NULL
        向右旋转 2 步: 1->2->0->NULL
        向右旋转 3 步: 0->1->2->NULL
        向右旋转 4 步: 2->0->1->NULL
        */

        /**
         * Definition for singly-linked list.
         * public class ListNode {
         *     public int val;
         *     public ListNode next;
         *     public ListNode(int x) { val = x; }
         * }
         */

        static ListNode RotateRight(ListNode head, int k)
        {
            if (head == null || head.next == null || k == 0)
            {
                return head;
            }

            // 反转链表
            ListNode temp = head;
            while (temp.next != null)
            {
                ListNode cur = temp;
                temp = temp.next;
                //temp.next = 
            }

            ListNode current = head;
            for (int i = 0; i < k; i++)
            {
                if (current.next != null)
                {
                    current = current.next;
                }
                else
                {
                    current = head;
                }
            }

            ListNode target = current;
            while (current.next != null)
            {
                current = current.next;
            }

            ListNode newHead = target.next == null ? head : target.next;
            current.next = head;
            target.next = null;

            return newHead;
        }
        #endregion
        #region 538_把二叉搜索树转换成累加树 
        /*
        给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
        例如：
        输入: 二叉搜索树:
                      5
                    /   \
                   2     13
        输出: 转换为累加树:
                     18
                    /   \
                  20     13
        */
        // 累加树的概念不明确 - 暂放一边
        static TreeNode ConvertBST(TreeNode root)
        {
            if (root == null)
            {
                return null;
            }
            CompleteNode(root);
            return root;
        }

        static int CompleteNode(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }
            if (root.right != null)
            {
                int right = CompleteNode(root.right);
                root.val += right;
            }
            if (root.left != null)
            {
                int left = CompleteNode(root.left);
                root.left.val += root.val;
            }

            return root.val;
        }
        #endregion
    }
}