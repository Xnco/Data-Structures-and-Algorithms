using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_两数相加_链表
{
    /*
    给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
    你可以假设除了数字 0 之外，这两个数字都不会以零开头。
    示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
    */
    class Program
    {
        static void Main(string[] args)
        {
            ListNode l1_1 = new ListNode(2);
            ListNode l1_2 = new ListNode(4);
            ListNode l1_3 = new ListNode(3);

            l1_1.next = l1_2;
            l1_2.next = l1_3;

            ListNode l2_1 = new ListNode(5);
            ListNode l2_2 = new ListNode(6);
            ListNode l2_3 = new ListNode(4);

            l2_1.next = l2_2;
            l2_2.next = l2_3;

            ListNode ln = AddTwoNumbers(l1_1, l2_1);

            int result = ln.val + ln.next.val * 10 + ln.next.next.val * 100;
            Console.WriteLine(result);
        }

        static ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode cur = l1;
            string num1 = "";
            while (cur != null)
            {
                num1 += cur.val;
                cur = cur.next;
            }

            cur = l2;
            string num2 = "";
            while (cur != null)
            {
                num2 += cur.val;
                cur = cur.next;
            }

            int result = int.Parse(num1) + int.Parse(num2);
            ListNode resultNode = new ListNode(result % 10);
            cur = resultNode;
            while (result != 0)
            {
                result = result / 10;
                ListNode ln = new ListNode(result % 10);
                cur.next = ln;
                cur = ln;
            }

            return resultNode;
        }
    }

    //Definition for singly-linked list.
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

}
