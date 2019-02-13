using System;

public class Class1
{
	public Class1()
	{
	}

    #region 94_二叉树的中序遍历 
    /*
    给定一个二叉树，返回它的中序 遍历。
    示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [1,3,2]
    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
    */
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     public int val;
     *     public TreeNode left;
     *     public TreeNode right;
     *     public TreeNode(int x) { val = x; }
     * }
     */
    // 递归 - 372ms
    static IList<int> InorderTraversal(TreeNode root)
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
        CompleteNode(root.left, result);
        result.Add(root.val);
        CompleteNode(root.right, result);
    }
    #endregion
}
