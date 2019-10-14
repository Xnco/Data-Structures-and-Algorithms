
#pragma region 404_左叶子之和
/*
计算给定二叉树的所有左叶子之和。

示例：

	3
   / \
  9  20
	/  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
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
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
		{
			return root->left->val + sumOfLeftLeaves(root->right); // 右边走正常逻辑
		}
		else
		{
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); // 如果左边不是叶子也走正常逻辑
		}
	}

	// 多一个方法记录是否为左边
	//Runtime: 4 ms, faster than 82.33% of C++ online submissions for Sum of Left Leaves.
	//Memory Usage : 13.2 MB, less than 100.00 % of C++ online submissions for Sum of Left Leaves.
	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		dfs(root, false, res);
		return res;
	}

	void dfs(TreeNode* root, bool bIsLeft, int& res)
	{
		if (root == NULL)
		{
			return;
		}

		if (bIsLeft && root->left == NULL && root->right == NULL)
		{
			res += root->val;
		}
		else
		{
			dfs(root->left, true, res);
			dfs(root->right, false, res);
		}
	}
};
#pragma endregion
