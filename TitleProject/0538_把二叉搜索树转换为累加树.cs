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
//Runtime: 120 ms, faster than 25.19% of C# online submissions for Convert BST to Greater Tree.
//Memory Usage: 29.5 MB, less than 100.00% of C# online submissions for Convert BST to Greater Tree.
TreeNode ConvertBST(TreeNode root)
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
#endregion
