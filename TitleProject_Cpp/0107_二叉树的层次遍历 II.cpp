#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;
#include <math.h>

using namespace std;

#pragma region 107_二叉树的层次遍历 II
/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
例如：
给定二叉树 [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
]
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
	// 8ms(100%), 13.8MB(84.02%)
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}

		vector<TreeNode*> cur;
		cur.push_back(root);

		vector<int> curNum;
		vector<TreeNode*> next;
		while (true)
		{
			for (size_t i = 0; i < cur.size(); i++)
			{
				curNum.push_back(cur[i]->val);

				if (cur[i]->left != nullptr)
				{
					next.push_back(cur[i]->left);
				}
				if (cur[i]->right != nullptr)
				{
					next.push_back(cur[i]->right);
				}
			}
			result.push_back(curNum);
			if (next.size() == 0)
			{
				reverse(result.begin(), result.end());
				return result;
			}
			curNum.clear();
			cur = next;
			vector<TreeNode*> temp;
			next = temp;
		}
	}
};
#pragma endregion