
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 700_二叉搜索树中的搜索
/*
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。
返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
例如，
给定二叉搜索树:
		4
	   / \
	  2   7
	 / \
	1   3
和值: 2
你应该返回如下子树:
	  2
	 / \
	1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
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
	// 60ms(93%), 29.1MB(96%)
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val == val)
			return root;
		else if (root->val > val)
			return searchBST(root->left, val);
		else
			return searchBST(root->right, val);
	}
};
#pragma endregion