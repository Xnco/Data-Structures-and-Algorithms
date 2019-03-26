
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 106_从中序与后序遍历序列构造二叉树
/*
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
	// 56ms, 68.4MB
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return BinaryTree(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
	}

	TreeNode* BinaryTree(int in_left, int in_right, int post_left, int post_right, vector<int>& inorder, vector<int>& postorder)
	{
		if (in_left > in_right) return nullptr;

		// 后序的最后一个一定是 root
		int rootval = postorder[post_right];
		TreeNode* root = new TreeNode(rootval);
		int root_index = IndexOf(inorder, rootval);
		//int root_index = in_left;
		//while (root_index <= in_right && inorder[root_index] != postorder[post_right])
		//	root_index++;

		int left_len = root_index - in_left;
		root->left = BinaryTree(in_left, root_index - 1, post_left, post_left + left_len - 1, inorder, postorder);
		root->right = BinaryTree(root_index + 1, in_right, post_left + left_len, post_right - 1, inorder, postorder);
		return root;
	}

	int IndexOf(vector<int> arr, int target)
	{
		int index = 0;
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	// 24ms, 16.8MB
	TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
		return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
	}

	TreeNode *pre_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
		if (leftin > rightin) return NULL;
		TreeNode *root = new TreeNode(post[rightpost]);
		int rootin = leftin;
		while (rootin <= rightin && in[rootin] != post[rightpost]) rootin++;
		int left = rootin - leftin;
		root->left = pre_order(leftin, rootin - 1, leftpost, leftpost + left - 1, in, post);
		root->right = pre_order(rootin + 1, rightin, leftpost + left, rightpost - 1, in, post);
		return root;
	}
};
#pragma endregion