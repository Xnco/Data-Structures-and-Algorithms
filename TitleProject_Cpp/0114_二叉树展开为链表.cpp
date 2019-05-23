
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 114_二叉树展开为链表
/*
给定一个二叉树，原地将它展开为链表。
例如，给定二叉树
	1
   / \
  2   5
 / \   \
3   4   6
将其展开为：
1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6
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
	// 递归 - 4ms(99.08%), 10.1MB(57.79%)
	void flatten(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}

		flatten(root->left);
		flatten(root->right);
		TreeNode* r = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right != nullptr)
		{
			root = root->right;
		}
		root->right = r;
	}
};
#pragma endregion
