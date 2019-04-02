
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;
#include <math.h>
#include <algorithm>

using namespace std;

#pragma region 103_二叉树的锯齿形层次遍历
/*
例如：
给定二叉树 [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回锯齿形层次遍历如下：
[
  [3],
  [20,9],
  [15,7]
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
	// BFS - 8ms(100%), 14.3MB(8.05%)
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		stack<TreeNode*> s;
		s.push(root);
		BFS(s, res, true);
		return res;
	}

	// l2r -> 左往右 or 右往左
	void BFS(stack<TreeNode*> s, vector<vector<int>>& res, bool l2r)
	{
		if (s.size() == 0)
		{
			return;
		}

		vector<int> tmp;
		stack<TreeNode*> news;
		while (!s.empty())
		{
			TreeNode* tree = s.top();
			s.pop();
			tmp.push_back(tree->val);
			if (l2r)
			{
				if (tree->left != nullptr)
					news.push(tree->left);
				if (tree->right != nullptr)
					news.push(tree->right);
			}
			else
			{
				if (tree->right != nullptr)
					news.push(tree->right);
				if (tree->left != nullptr)
					news.push(tree->left);
			}
		}
		res.push_back(tmp);
		BFS(news, res, !l2r);
	}
};

#pragma endregion