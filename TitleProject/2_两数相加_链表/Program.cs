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
            ListNode l1_1 = new ListNode(9);

            ListNode l2_1 = new ListNode(1);
            ListNode l2_2 = new ListNode(9);
            ListNode l2_3 = new ListNode(9);
            ListNode l2_4 = new ListNode(9);
            ListNode l2_5 = new ListNode(9);
            ListNode l2_6 = new ListNode(9);
            ListNode l2_7 = new ListNode(9);
            ListNode l2_8 = new ListNode(9);
            ListNode l2_9 = new ListNode(9);
            ListNode l2_10 = new ListNode(9);

            l2_1.next = l2_2;
            l2_2.next = l2_3;
            l2_3.next = l2_4;
            l2_4.next = l2_5;
            l2_5.next = l2_6;
            l2_6.next = l2_7;
            l2_7.next = l2_8;
            l2_8.next = l2_9;
            l2_9.next = l2_10;

            ListNode ln = new Program().AddTwoNumbers(l1_1, l2_1);

            Console.ReadKey();
        }

        ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode cur1 = l1;
            ListNode cur2 = l2;

            ListNode header = new ListNode(0);
            ListNode newCur = header;
            int isOver = 0;

            while (cur1 != null || cur2 != null)
            {
                int num = (cur1 != null ? cur1.val : 0) + (cur2 != null ? cur2.val : 0) + isOver;
                isOver = num / 10;

                newCur.next = new ListNode(num % 10);
                newCur = newCur.next;

                if (cur1 != null) cur1 = cur1.next;

                if (cur2 != null) cur2 = cur2.next;
            }

            if (isOver != 0) newCur.next = new ListNode(1);

            return header.next;
        }
    }

    //Definition for singly-linked list.
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }
    
    /*  两数相加硬算
     public ListNode AddTwoNumbers(ListNode l1, ListNode l2) 
        {
            string num1 = GetText(l1);
            string num2 = GetText(l2);

            int result = int.Parse(num1) + int.Parse(num2);

            ListNode resultNode = new ListNode(result % 10);
            ListNode cur = resultNode;
            while (result != 0)
            {
                result = result / 10;
                if (result == 0)
                {
                    break;
                }
                ListNode ln = new ListNode(result % 10);
                cur.next = ln;
                cur = ln;
            }

            return resultNode;
        }

        string GetText(ListNode node)
        {
            ListNode cur = node;
            string num1 = "";
            while (cur != null)
            {
                num1 = num1.Insert(0, cur.val.ToString());
                cur = cur.next;
            }
            return num1;
        } 
   */
}
