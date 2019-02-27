using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TitleProject
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(Convert("LEETCODEISHIRING", 3)); 
            
        }

        // LCA(最近公共祖先)
        // DFS(深度优先遍历)
        // BFS(广度优先遍历)

        #region 0 
        /*
        
        */
        static void Func()
        {

        }
        #endregion
        #region 6_Z字形变换
        /*
        将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
        比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
        L   C   I   R
        E T O E S I I G
        E   D   H   N
        之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
        请你实现这个将字符串进行指定行数变换的函数：
        string convert(string s, int numRows);

        示例 1:
        输入: s = "LEETCODEISHIRING", numRows = 3
        输出: "LCIRETOESIIGEDHN"

        示例 2:
        输入: s = "LEETCODEISHIRING", numRows = 4
        输出: "LDREOEIIECIHNTSG"
        解释:
        L     D     R
        E   O E   I I
        E C   I H   N
        T     S     G
        */
        static string Convert(string s, int numRows)
        {
            string newStr = "";
            int num = numRows * 2 - 2;

            // 最上面一行
            int head = 0;
            while (head < s.Length)
            {
                newStr += s[head].ToString();
                head += num;
            }

            // 中间的所有成对的行
            for (int i = 0; i < num - 2; i++)
            {
                int body = 0;
                while (body < s.Length)
                {
                    newStr += s[body + 1 + i].ToString();
                    newStr += s[body + num - 1 - i].ToString();
                    body += num;
                }
            }

            // 底部一行
            int bottom = 0;
            while (bottom < s.Length)
            {

            }
            return newStr;
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
        #region 879 - 动态规划问题
        /*

        */
        static void ProfitableSchemes()
        {

        }
        #endregion
        

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
    }
}