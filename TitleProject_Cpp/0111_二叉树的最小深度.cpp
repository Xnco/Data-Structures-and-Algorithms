
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 111_二叉树的最小深度
/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。
示例:
给定二叉树 [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回它的最小深度  2
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
	// 16ms(99.34%), 19.7MB(65.46%)
	int minDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int res = 1;
		int min = 999999;
		dfs(root, res, min);
		return min;
	}

	void dfs(TreeNode* root, int& res, int& min) {
		if (root == nullptr)
		{
			return;
		}
		if (root->left == nullptr && root->right == nullptr)
		{
			if (res < min)
			{
				min = res;
			}
			return;
		}
		if (root->left != nullptr)
		{
			res++;
			dfs(root->left, res, min);
			res--;
		}
		if (root->right != nullptr)
		{
			res++;
			dfs(root->right, res, min);
			res--;
		}
	}

	// 16ms
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = minDepth(root->left), right = minDepth(root->right);
		return (left && right) ? 1 + min(left, right) : 1 + left + right;
	}
};

#pragma endregion
