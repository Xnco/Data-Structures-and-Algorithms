using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0104_二叉树的最大深度
{

    //Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }
 

    class Program
    {
        static void Main(string[] args)
        {
            TreeNode tree1 = new TreeNode(3);
            TreeNode tree2 = new TreeNode(9);
            TreeNode tree3 = new TreeNode(20);
            TreeNode tree4 = new TreeNode(15);
            TreeNode tree5 = new TreeNode(7);

            tree1.left = tree2;
            tree1.right = tree3;
            tree3.left = tree4;
            tree3.right = tree5;

            Console.WriteLine(MaxDepth_Iteration(tree1)); 
        }

        // 方案1 Leetcode上 最好成绩160ms
        static int MaxDepth(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }
            int maxDepth = 1;
            int curDepth = 1;

            AddDepth(root, ref maxDepth, ref curDepth);

            return maxDepth;
        }

        static void AddDepth(TreeNode tree, ref int maxDepth, ref int curDepth)
        {
            if (tree.left != null)
            {
                curDepth++;
                if (curDepth > maxDepth)
                {
                    maxDepth = curDepth;
                }

                AddDepth(tree.left, ref maxDepth, ref curDepth);
                curDepth--;
            }

            if (tree.right != null)
            {
                curDepth++;
                if (curDepth > maxDepth)
                {
                    maxDepth = curDepth;
                }

                AddDepth(tree.right, ref maxDepth, ref curDepth);
                curDepth--;
            }
        }

        // 方案2 最好成绩148ms，但有时会超时，不知道什么原因 
        public int MaxDepth2(TreeNode root)
        {
            return root == null ? 0 : Math.Max(MaxDepth(root.left), MaxDepth(root.right)) + 1;
        }

        // 160ms， if和三元运算符感觉差不多的样子
        static int MaxDepth3(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }
            else
            {
                int left_height = MaxDepth3(root.left);
                int right_height = MaxDepth3(root.right);
                return Math.Max(left_height, right_height) + 1;
            }
        }

        // 迭代来算 -> 时间复杂度：O(N)  空间复杂度：O(N) 最好成绩156ms
        static int MaxDepth_Iteration(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            Queue<KeyValuePair<TreeNode, int>> all = new Queue<KeyValuePair<TreeNode, int>>();
            all.Enqueue(new KeyValuePair<TreeNode, int>(root, 1));

            int depth = 1;
            while (all.Count != 0)
            {
                var cur = all.Dequeue();
                var curNode = cur.Key;
                var curDepth = cur.Value;

                // 当前节点不空
                if (curNode != null)
                {
                    depth = Math.Max(depth, curDepth);
                    all.Enqueue(new KeyValuePair<TreeNode, int>(curNode.left, curDepth + 1));
                    all.Enqueue(new KeyValuePair<TreeNode, int>(curNode.right, curDepth + 1));
                }
            }

            return depth;
        }
    }
}
