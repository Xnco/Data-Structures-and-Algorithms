#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 965_单值二叉树
/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。
示例 1：
输入：[1,1,1,1,1,null,1]
输出：true
示例 2：
输入：[2,2,2,5,2]
输出：false
提示：
给定树的节点数范围是 [1, 100]。
每个节点的值都是整数，范围为 [0, 99] 。
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

	// 4ms(100%), 10.7MB(99.47%)
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			return true;
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			if (root->left->val == root->val && root->right->val == root->val)
			{
				return isUnivalTree(root->left) && isUnivalTree(root->right);
			}
			else
			{
				return false;
			}
		}
		else if (root->left != nullptr)
		{
			if (root->left->val == root->val)
			{
				return isUnivalTree(root->left);
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (root->right->val == root->val)
			{
				return isUnivalTree(root->right);
			}
			else
			{
				return false;
			}
		}
	}
};
#pragma endregion