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
            ListNode c = new ListNode(1);
            c.next = new ListNode(2);
            //c.next.next = new ListNode(3);
            //c.next.next.next = new ListNode(4);
            //c.next.next.next.next = new ListNode(5);
            RotateRight(c, 2);
        }

        #region 0 
        /*
        
        */
        static void Func()
        {

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