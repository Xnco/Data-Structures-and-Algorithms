using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0021_合并两个有序链表
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 21_合并两个有序链表 
        /*
        将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

        示例：
        输入：1->2->4, 1->3->4
        输出：1->1->2->3->4->4
        */

        //Definition for singly-linked list.
        public class ListNode
        {
            public int val;
            public ListNode next;
            public ListNode(int x) { val = x; }
        }
         
        // 144ms
        static ListNode MergeTwoLists(ListNode l1, ListNode l2)
        {
            ListNode head = new ListNode(0);
            ListNode cur = head;
            while (l1 != null && l2 != null)
            {
                if (l1.val < l2.val)
                {
                    cur.next = l1;
                    l1 = l1.next;
                }
                else
                {
                    cur.next = l2;
                    l2 = l2.next;
                }
                cur = cur.next;
            }

            if (l1 == null)
            {
                cur.next = l2;
            }
            else
            {
                cur.next = l1;
            }

            return head.next;
        }
        #endregion
    }
}
