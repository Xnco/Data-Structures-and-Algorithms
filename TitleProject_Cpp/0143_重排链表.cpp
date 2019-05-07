
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 143_ 重排链表
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// 44ms(100%), 12.1MB(82.8%)
	// 二分 -> 反转后面 -> 插入前面
	void reorderList(ListNode* head) {
		if (head == nullptr) return;

		// 快慢指针二分
		ListNode * first = head;
		ListNode * second = head;

		while (second != nullptr && second->next != nullptr)
		{
			first = first->next;
			second = second->next->next;
		}

		// 反转后部分链表
		ListNode* right = first->next;
		first->next = nullptr;
		right = reverseList(right);

		// 后部分插入前面
		ListNode* cur = head;
		while (right != nullptr)
		{
			ListNode* n1 = cur->next;
			ListNode* n2 = right->next;

			cur->next = right;
			right->next = n1;
			cur = n1;
			right = n2;
		}
	}

	// 反转链表
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}

	// 简单粗暴, 将节点都存入列表中
	// 超时
	void reorderList(ListNode* head) {
		vector<ListNode*> list;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			list.push_back(cur);
			cur = cur->next;
		}

		int count = list.size() - 1;
		int mid = count / 2;
		for (size_t i = 0; i <= mid; i++)
		{
			list[i]->next = list[count - i];
			if (i + 1 != count - i)
			{
				list[count - i]->next = list[i + 1];
			}
		}
	}
};
#pragma endregion
