using System;

public class Class1
{
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

    //Runtime: 80 ms, faster than 100.00% of C# online submissions for Rotate List.
    //Memory Usage: 25.3 MB, less than 25.00% of C# online submissions for Rotate List.
    static ListNode RotateRight(ListNode head, int k)
    {
        if (head == null || head.next == null || k == 0)
        {
            return head;
        }
        int len = 1;
        ListNode current = head;
        while (current.next != null)
        {
            ++len;
            current = current.next;
        }

        k %= len;
        if (k == 0) return head;

        current.next = head; // 第一次遍历就可以先将首尾相连， 第二次遍历就不用遍历到最后了

        ListNode newlast = head;
        for (int i = 1; i < len - k; ++i)
        {
            newlast = newlast.next;
        }
        ListNode newhead = newlast.next;
        newlast.next = null;
        return newhead;
    }

    // 反转链表, 且得到链表长度(Len > 1)
    static ListNode ReverseList(ListNode head, out int Len)
    {
        Len = 1;
        ListNode first = head;
        ListNode second = head.next;
        ListNode third = second.next;
        while (second != null)
        {
            ++Len;
            second.next = first;

            first = second;
            second = third;
            if (third != null)
                third = third.next;
            else
                break;
        }
        head.next = null;
        return first;
    }
    #endregion
}
