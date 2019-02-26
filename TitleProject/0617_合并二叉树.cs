using System;

public class Class1
{
	public Class1()
	{
        
    }

    #region 617_合并二叉树 
    /*
    你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
    示例 1:
    输入: 
        Tree 1                     Tree 2                  
              1                         2                             
             / \                       / \                            
            3   2                     1   3                        
           /                           \   \                      
          5                             4   7                  
    输出: 
    合并后的树:
             3
            / \
           4   5
          / \   \ 
         5   4   7
    注意: 合并必须从两个树的根节点开始。
    */
    // 188ms, 25.8MB

    static TreeNode MergeTrees(TreeNode t1, TreeNode t2)
    {
        TreeNode tmpNode = null;
        if (t1 == null && t2 == null)
        {
            return tmpNode;
        }
        else if (t1 != null && t2 != null)
        {
            tmpNode = new TreeNode(0);
            tmpNode.val += t1.val;
            tmpNode.val += t2.val;
            tmpNode.left = MergeTrees(t1.left, t2.left);
            tmpNode.right = MergeTrees(t1.right, t2.right);
        }

        if (t1 == null)
        {
            tmpNode = new TreeNode(0);
            tmpNode.val += t2.val;
            tmpNode.left = MergeTrees(null, t2.left);
            tmpNode.right = MergeTrees(null, t2.right);
        }
        if (t2 == null)
        {
            tmpNode = new TreeNode(0);
            tmpNode.val += t1.val;
            tmpNode.left = MergeTrees(t1.left, null);
            tmpNode.right = MergeTrees(t1.right, null);
        }

        return tmpNode;
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
