#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 637_二叉树的层平均值
/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
示例 1:
输入:
	3
   / \
  9  20
	/  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：
节点值的范围在32位有符号整数范围内。
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
	// 迭代 -> 36ms(17.4%), 24.1MB(5.3%)
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		stack<TreeNode*> curLayer;
		curLayer.push(root);
		while (!curLayer.empty())
		{
			stack<TreeNode*> nextLayer;
			double num = 0;
			int count = curLayer.size();
			while (!curLayer.empty())
			{
				TreeNode* node = curLayer.top();
				curLayer.pop();
				num += node->val;
				if (node->left != nullptr)
				{
					nextLayer.push(node->left);
				}
				if (node->right != nullptr)
				{
					nextLayer.push(node->right);
				}
			}
			num /= count;
			res.push_back(num);
			curLayer = nextLayer;
		}
		return res;
	}
};
#pragma endregion
