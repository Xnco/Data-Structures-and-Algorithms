#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;


#pragma region 105_从前序与中序遍历序列构造二叉树
/*
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7
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
	// 24ms(79%), 16.6MB(67.5%)
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return BinaryTree(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
	}

	TreeNode* BinaryTree(int pre_left, int pre_right, int in_left, int in_right, vector<int>& preorder, vector<int>& inorder)
	{
		if (in_left > in_right)
		{
			return nullptr;
		}
		// 前序的首位就是root.val
		TreeNode* root = new TreeNode(preorder[pre_left]);
		// 然后从中序中找到 val
		int root_index = in_left;
		while (root_index <= in_right && inorder[root_index] != preorder[pre_left])
		{
			root_index++;
		}
		int left_len = root_index - in_left; // 左边的长度

		root->left = BinaryTree(pre_left + 1, pre_left + left_len, in_left, root_index - 1, preorder, inorder);
		root->right = BinaryTree(pre_left + left_len + 1, pre_right, root_index + 1, in_right, preorder, inorder);
		return root;
	}
};
#pragma endregion