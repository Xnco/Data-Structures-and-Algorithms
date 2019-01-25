using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0206_反转链表
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 206_反转链表
        /*
        反转一个单链表。

        示例:
            输入: 1->2->3->4->5->NULL
            输出: 5->4->3->2->1->NULL

        进阶: 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

        */

        // 解法1： 迭代反转链表 - 160ms
        public static ListNode ReverseList(ListNode head)
        {
            // 处理头部
            if (head == null)
            {
                return null;
            }
            ListNode firstNode = head;
            ListNode secondNode = head.next;
            ListNode thirdNode = null;
            head.next = null;

            while (secondNode != null)
            {
                // 不是最后一个
                thirdNode = secondNode.next;
                secondNode.next = firstNode;

                firstNode = secondNode;
                secondNode = thirdNode;
            }
            return firstNode;
        }


        // 解法2： 递归反转链表， 144ms
        public static ListNode ReverseList2(ListNode head)
        {
            // 处理头部
            if (head == null)
            {
                return null;
            }
            ListNode firstNode = head;
            ListNode secondNode = head.next;
            head.next = null;
            return SwapNode(firstNode, secondNode);
        }

        // 两两处理，直到末尾为 null - 144ms
        public static ListNode SwapNode(ListNode first, ListNode second)
        {
            if (second == null)
            {
                // 是最后一个，first 就是新的 head 
                return first;
            }
            else
            {
                // 不是最后一个
                ListNode third = second.next;
                second.next = first;
                return SwapNode(second, third);
            }
        }
        #endregion

        /* Definition for singly-linked list. */
        public class ListNode
        {
            public int val;
            public ListNode next;
            public ListNode(int x) { val = x; }
        }
    }
}
