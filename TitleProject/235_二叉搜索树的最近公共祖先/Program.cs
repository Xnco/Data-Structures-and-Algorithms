using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _235_二叉搜索树的最近公共祖先
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 235_二叉搜索树的最近公共祖先
        /*
        给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
        百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
        例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

        示例 1:
        输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
        输出: 6 
        解释: 节点 2 和节点 8 的最近公共祖先是 6。

        示例 2:
        输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
        输出: 2
        解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

        说明:
            所有节点的值都是唯一的。
            p、q 为不同节点且均存在于给定的二叉搜索树中。
        */

        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }

        // 240 ms
        // 递归的做法 - 二叉搜索数的性质就是小的在左边，大的在右边
        static TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
        {
            return SelectNode(root, p, q);
        }

        static TreeNode SelectNode(TreeNode target, TreeNode p, TreeNode q)
        {
            if (target == null)
            {
                return null;
            }

            if (target.val > p.val && target.val > q.val)
            {
                // 两个数在左边
                return SelectNode(target.left, p, q);
            }
            else if (target.val < p.val && target.val < q.val)
            {
                // 两个数在右边
                return SelectNode(target.right, p, q);
            }
            else
            {
                // 两个数分别在两边 - 或者有一个相等的 -> 这就是最近公共祖先
                return target;
            }
        }

        TreeNode LowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q)
        {
            if ((root.val - p.val) * (root.val -q.val) <= 0)
            {
                // 一正一负，说明在两边
                return root;
            }
            else if (root.val > p.val)
            {
                // 在左边
                return LowestCommonAncestor2(root.left, p, q);
            }
            else
            {
                // 在右边
                return LowestCommonAncestor2(root.right, p, q);
            }
        }
        #endregion
    }
}
