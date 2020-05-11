
#pragma region 98_验证二叉搜索树
/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1:
输入:
	2
   / \
  1   3
输出: true

示例 2:
输入:
	5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
	// 中序遍历, 升序为true, 用了一次额外的空间, 切要遍历一次List
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) return true;
		vector<int> list;
		MidOrder(root, list);
		if (list.size() == 1) return true;
		for (int i = 0; i < list.size() - 1; ++i)
		{
			if (list[i] >= list[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	void MidOrder(TreeNode* root, vector<int>& list)
	{
		if (root == nullptr) return;

		MidOrder(root->left, list);
		list.push_back(root->val);
		MidOrder(root->right, list);
	}

	// 同样是中序遍历, 但是只记录上下边界, 不用额外空间和额外遍历
	//Runtime: 16 ms, faster than 72.67% of C++ online submissions for Validate Binary Search Tree.
	//Memory Usage : 18.2 MB, less than 100.00 % of C++ online submissions for Validate Binary Search Tree.
	bool isValidBST(TreeNode* root) {
		return Between(root, LONG_MIN, LONG_MAX);
	}

	bool Between(TreeNode* root, long low, long high)
	{
		if (root == nullptr) return true;
		if (root->val < low || root->val > high) return false;
		if (!Between(root->left, low, root->val)) return false;
		if (!Between(root->right, root->val, high)) return false;
		return true;
	}
};
#pragma endregion
