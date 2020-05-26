#region 538_�Ѷ���������ת�����ۼ��� 
/*
����һ��������������Binary Search Tree��������ת����Ϊ�ۼ�����Greater Tree)��ʹ��ÿ���ڵ��ֵ��ԭ���Ľڵ�ֵ�������д������Ľڵ�ֵ֮�͡�
���磺
����: ����������:
              5
            /   \
           2     13
���: ת��Ϊ�ۼ���:
             18
            /   \
          20     13
*/
//Runtime: 120 ms, faster than 25.19% of C# online submissions for Convert BST to Greater Tree.
//Memory Usage: 29.5 MB, less than 100.00% of C# online submissions for Convert BST to Greater Tree.
TreeNode ConvertBST(TreeNode root)
{
    if (root == null) return root;

    // �����������������������, �浽list��, Ȼ���ű��� nums[n] += nums[n+1]
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
