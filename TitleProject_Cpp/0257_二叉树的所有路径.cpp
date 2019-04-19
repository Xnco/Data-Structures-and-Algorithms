#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 257_二叉树的所有路径
/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:
   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
	// 8ms(92%), 11.5MB(94.7%)
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		dfs(root, "", res);
		return res;
	}

	void dfs(TreeNode* root, string cur, vector<string>& res)
	{
		if (root == nullptr)
			return;

		cur += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr)
		{
			res.push_back(cur);
			return;
		}
		if (root->left != nullptr)
			dfs(root->left, cur + "->", res);
		if (root->right != nullptr)
			dfs(root->right, cur + "->", res);
	}
};
#pragma endregion
