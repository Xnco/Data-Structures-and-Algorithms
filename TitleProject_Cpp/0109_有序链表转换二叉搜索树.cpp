
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 109_有序链表转换二叉搜索树
/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
	  0
	 / \
   -3   9
   /   /
 -10  5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

	// ListNode->vector 816ms(5.06%), 354MB(0.95%)
public:
	TreeNode* sortedListToBST2(ListNode* head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		vector<int> list;
		while (head != nullptr)
		{
			list.push_back(head->val);
			head = head->next;
		}
		int left = 0;
		int right = list.size() - 1;
		return CreateRoot(left, right, list);
	}

	TreeNode* CreateRoot(int left, int right, vector<int> list)
	{
		if (left > right) return nullptr;
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(list[mid]);
		root->left = CreateRoot(left, mid - 1, list);
		root->right = CreateRoot(mid + 1, right, list);
		return root;
	}

	// 快慢指针, 不用 vector - 32ms(100%), 24.3MB(89.37%)
	TreeNode* sortedListToBST(ListNode* head)
	{
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return new TreeNode(head->val);

		ListNode* pre = head;
		ListNode* mid = head;
		ListNode* fast_node = head;

		// 快慢指针找到 mid
		while (fast_node != nullptr && fast_node->next != nullptr)
		{
			pre = mid;
			mid = mid->next;
			fast_node = fast_node->next->next;
		}

		pre->next = nullptr;
		TreeNode* root = new TreeNode(mid->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(mid->next);
		return root;
	}
};
#pragma endregion