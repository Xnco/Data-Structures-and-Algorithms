#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

#pragma region 112_路径总和
/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 // DFS(深度优先遍历)
class Solution {

	// 16ms(99.8%), 19.9MB
	// 递归算法
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		sum -= root->val;
		if (root->right == nullptr && root->left == nullptr) return sum == 0;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}

	// 迭代
	bool hasPathSum2(TreeNode* root, int sum)
	{
		if (root == nullptr)
		{
			return false;
		}
		int result = 0;
		stack<TreeNode*> nodeS;
		nodeS.push(root);
		while (nodeS.size() != 0)
		{
			TreeNode* cur = nodeS.top();
			nodeS.pop();
			result += cur->val;

			if (cur->right != nullptr)
			{
				nodeS.push(cur->right);
			}

			if (cur->left != nullptr)
			{
				nodeS.push(cur->left);
			}

			if (node->right == nullptr && node->left == nullptr)
			{
				if (result == sum)
				{
					return true;
				}
			}
		}
		return false;
	}
};

#pragma endregion