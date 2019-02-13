using System;

//Definition for singly-linked list.
public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int x) { val = x; }
}

public class Class1
{
    public Class1()
    {
        ListNode node1 = new ListNode(1);
        node1.next = new ListNode(4);
        node1.next.next = new ListNode(5);

        ListNode node2 = new ListNode(1);
        node2.next = new ListNode(3);
        node2.next.next = new ListNode(4);

        ListNode node3 = new ListNode(2);
        node3.next = new ListNode(6);

        ListNode[] all = { node1, node2, node3 };

        MergeKLists2(all);
    }

    #region 23_合并k个排序链表 
    /*
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
    示例:
    输入:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    输出: 1->1->2->3->4->4->5->6
    */
    // 暴力将所有链表转换成集合，排序之后再转换成链表 - 192ms
    static ListNode MergeKLists(ListNode[] lists)
    {
        if (lists == null || lists.Length == 0)
        {
            return null;
        }
        List<int> temp = new List<int>();
        for (int i = 0; i < lists.Length; i++)
        {
            ListNode cur = lists[i];
            while (cur != null)
            {
                temp.Add(cur.val);
                cur = cur.next;
            }
        }

        if (temp.Count == 0)
        {
            return null;
        }
        else
        {
            temp.Sort();

            ListNode head = new ListNode(temp[0]);
            ListNode tempNode = head;
            for (int i = 1; i < temp.Count; i++)
            {
                tempNode.next = new ListNode(temp[i]);
                tempNode = tempNode.next;
            }

            return head;
        }
    }

    // 964ms，这种反而更慢了
    // 类似合并两个有序数组，找到数组中当前最小的 一一并入新链表
    static ListNode MergeKLists2(ListNode[] lists)
    {
        if (lists == null || lists.Length == 0)
        {
            return null;
        }

        ListNode head = new ListNode(0);
        ListNode cur = head;

        while (true)
        {
            // 找最小的 下标
            int minIndex = -1;
            for (int i = 0; i < lists.Length; i++)
            {
                if (lists[i] == null)
                {
                    continue;
                }
                else if (minIndex == -1)
                {
                    minIndex = i;
                }
                else if (lists[i].val < lists[minIndex].val)
                {
                    minIndex = i;
                }
            }

            // 找不到最小的，说明空了
            if (minIndex == -1)
            {
                break;
            }
            else
            {
                cur.next = new ListNode(lists[minIndex].val);
                cur = cur.next; // 链表往后推
                lists[minIndex] = lists[minIndex].next; // 用过的链表也往后推
            }
        }

        return head.next;
    }

    #endregion
}
