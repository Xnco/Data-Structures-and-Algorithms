using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0144_二叉树的前序遍历
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 144_二叉树的前序遍历
        /*
        给定一个二叉树，返回它的 前序 遍历。

        示例:
        输入: [1,null,2,3]  
           1
            \
             2
            /
           3 
        输出: [1,2,3]

        进阶: 递归算法很简单，你可以通过迭代算法完成吗？
        */
        // 递归 - 420ms
       /**
         * Definition for a binary tree node.
         * public class TreeNode {
         *     public int val;
         *     public TreeNode left;
         *     public TreeNode right;
         *     public TreeNode(int x) { val = x; }
         * }
         */
        static IList<int> PreorderTraversal(TreeNode root)
        {
            List<int> result = new List<int>();
            CompleteNode(root, result);
            return result;
        }

        static void CompleteNode(TreeNode root, List<int> result)
        {
            if (root == null)
            {
                return;
            }
            result.Add(root.val);

            CompleteNode(root.left, result);
            CompleteNode(root.right, result);
        }

        #endregion
    }
}
