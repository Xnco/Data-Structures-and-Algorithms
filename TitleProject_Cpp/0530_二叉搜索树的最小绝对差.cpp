#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 530_二叉搜索树的最小绝对差
/*
给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
示例 :
输入:
   1
	\
	 3
	/
   2
输出:
1
解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
注意: 树中至少有2个节点。
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
	// 先中序遍历得到一个 vector<int>, 再两两对比差值即可
	// 24ms(98%), 22.3MB(94.9%)
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> res;
		getVec(root, res);

		int num = abs(res[0] - res[1]);
		for (size_t i = 1; i < res.size() - 1; i++)
		{
			int n = abs(res[i] - res[i + 1]);
			if (n < num)
			{
				num = n;
			}
		}
		return num;
	}

	void getVec(TreeNode* root, vector<int>& res)
	{
		if (root == nullptr) return;
		getVec(root->left, res);
		res.push_back(root->val);
		getVec(root->right, res);
	}
};

#pragma endregion

int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	Solution s;
	s.getMinimumDifference(root);
}