using System;

public class Class1
{
    public Class1()
    {
    }

    #region 226_翻转二叉树 
    /*
    翻转一棵二叉树。
    示例：
    输入：
         4
       /   \
      2     7
     / \   / \
    1   3 6   9

    输出：
         4
       /   \
      7     2
     / \   / \
    9   6 3   1

    备注:
    这个问题是受到 Max Howell 的 原问题 启发的 ：
        谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
    */
    // 152ms, 9.1MB
    static TreeNode InvertTree(TreeNode root)
    {
        if (root == null)
        {
            return null;
        }

        Swap(root);

        InvertTree(root.left);
        InvertTree(root.right);

        return root;
    }

    static void Swap(TreeNode root)
    {
        TreeNode node = root.left;
        root.left = root.right;
        root.right = node;
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
