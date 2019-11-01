
#pragma region 993_二叉树的堂兄弟节点
/*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

示例 1：
输入：root = [1,2,3,4], x = 4, y = 3
输出：false

示例 2：
输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true

示例 3：
输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false

提示：
二叉树的节点数介于 2 到 100 之间。
每个节点的值都是唯一的、范围为 1 到 100 的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cousins-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Cousins in Binary Tree.
 //Memory Usage : 11.2 MB, less than 93.33 % of C++ online submissions for Cousins in Binary Tree.
class Solution {
public:
	int depth = 0;
	int parent = 0;
	bool isCousins(TreeNode* root, int x, int y) {
		if (root == NULL || root->val == x || root->val == y)
		{
			return false;
		}

		return dfs(root->left, x, y, 2, root->val) || dfs(root->right, x, y, 2, root->val);
	}

	bool dfs(TreeNode* root, int x, int y, int curDepth, int curParent)
	{
		if (root == NULL || (depth != 0 && curDepth > depth))
		{
			return false;
		}

		if (root->val == x || root->val == y)
		{
			if (depth == 0)
			{
				depth = curDepth;
				parent = curParent;
				return false;
			}
			else
			{
				return depth == curDepth && parent != curParent;
			}
		}
		return dfs(root->left, x, y, curDepth + 1, root->val) || dfs(root->right, x, y, curDepth + 1, root->val);
	}
};
#pragma endregion

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);

	t1->left = t2;
	t1->right = t3;
	t2->right = t4;
	t3->right = t5;

	Solution s;
	s.isCousins(t1, 4, 5);
}