using System;

public class Class1
{
    #region 105_从前序与中序遍历序列构造二叉树
    /*
    根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。
    例如，给出
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    */
    static TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        return GetRoot(0, preorder.Length - 1, preorder, 0, inorder.Length - 1, inorder);
    }

    static TreeNode GetRoot(int preLeft, int preRight, int[] preorder, int inLeft, int inRight, int[] inorder)
    {
        if (preLeft > preRight)
        {
            return null;
        }
        int rootVal = preorder[preLeft];
        TreeNode root = new TreeNode(rootVal);

        for (int i = inLeft; i <= inRight; i++)
        {
            if (inorder[i] == rootVal)
            {
                int leftLen = i - inLeft;
                root.left = GetRoot(preLeft + 1, preLeft + leftLen, preorder, inLeft, i - 1, inorder);
                root.right = GetRoot(preLeft + leftLen + 1, preRight, preorder, i + 1, inRight, inorder);
                return root;
            }
        }
        return null;
    }
    #endregion

}
