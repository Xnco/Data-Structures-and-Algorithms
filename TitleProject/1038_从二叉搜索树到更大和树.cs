using System;

/**
* Definition for a binary tree node.
* public class TreeNode {
*     public int val;
*     public TreeNode left;
*     public TreeNode right;
*     public TreeNode(int x) { val = x; }
* }
*/
public class Solution
{
    //Runtime: 92 ms, faster than 79.27% of C# online submissions for Binary Search Tree to Greater Sum Tree.
    //Memory Usage: 24 MB, less than 100.00% of C# online submissions for Binary Search Tree to Greater Sum Tree.
    public TreeNode BstToGst(TreeNode root)
    {
        if (root == null) return root;

        // 二叉搜索树的中序是升序的, 存到list中, 然后倒着遍历 nums[n] += nums[n+1]
        Stack<TreeNode> stack = new Stack<TreeNode>();
        MidOrder(root, stack);

        TreeNode lastNode = stack.Pop();
        while (stack.Count != 0)
        {
            TreeNode temp = stack.Pop();
            temp.val += lastNode.val;
            lastNode = temp;
        }
        return root;
    }

    void MidOrder(TreeNode root, Stack<TreeNode> stack)
    {
        if (root == null) return;

        MidOrder(root.left, stack);
        stack.Push(root);
        MidOrder(root.right, stack);
    }
}

