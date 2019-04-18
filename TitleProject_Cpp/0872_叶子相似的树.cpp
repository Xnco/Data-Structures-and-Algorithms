#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#pragma region 872_叶子相似的树
/*
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
提示：
给定的两颗树可能会有 1 到 100 个结点
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
	// 8ms(99.87%), 14.1MB(68.46%)
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> res1;
		dfs(root1, res1);
		vector<int> res2;
		dfs(root2, res2);

		if (res1.size() != res2.size())
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < res1.size(); i++)
			{
				if (res1[i] != res2[i])
				{
					return false;
				}
			}
			return true;
		}
	}

	void dfs(TreeNode* root, vector<int>& res)
	{
		if (root == nullptr) return;
		if (root->left == nullptr && root->right == nullptr)
		{
			res.push_back(root->val);
		}
		dfs(root->left, res);
		dfs(root->right, res);
	}
};
#pragma endregion
