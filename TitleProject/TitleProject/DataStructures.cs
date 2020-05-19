using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TitleProject
{
    //Definition for singly-linked list.
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    //Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }

    public static class Tool
    {
        public static void Swap(int[] arr, int a, int b)
        {
            if (a < 0 || b >= arr.Length || b < 0 || b >= arr.Length || a == b)
                return;

            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
    }
}
