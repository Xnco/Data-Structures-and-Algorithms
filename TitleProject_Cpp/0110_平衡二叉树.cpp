
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;
#include <math.h>

using namespace std;

#pragma region 110_平衡二叉树
/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
示例 1:
给定二叉树 [3,9,20,null,null,15,7]
	3
   / \
  9  20
	/  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
返回 false 。
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
	// 每个子节点都得是平衡二叉树 - 16ms(99.37%), 16.3MB(99.06%)
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		int res = getHeight(root->left) - getHeight(root->right);
		return abs(res) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}

	int getHeight(TreeNode* root)
	{
		if (root == nullptr) return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		int res = left > right ? left : right;
		return res + 1;
	}
};
#pragma endregion