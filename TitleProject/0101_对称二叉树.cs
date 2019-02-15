using System;

public class Class1
{
	public Class1()
	{
	}

    #region 101_对称二叉树 
    /*
    给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3

    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
        1
       / \
      2   2
       \   \
       3    3

    说明:
    如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
    */
    // 递归的做法 152ms, 10.1MB
    static bool IsSymmetric(TreeNode root)
    {
        if (root == null)
        {
            return true;
        }

        return Compare(root.left, root.right);
    }

    static bool Compare(TreeNode left, TreeNode right)
    {
        if (left == null && right == null)
        {
            return true;
        }
        else if (left != null && right != null && left.val == right.val)
        {
            return Compare(left.left, right.right) && Compare(left.right, right.left);
        }
        else
        {
            return false;
        }
    }

    //Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }
    #endregion
}
