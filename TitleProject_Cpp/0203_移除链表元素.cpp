
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 203_移除链表元素
/*
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
	// 20ms(100%), 11.1MB(99.1%)
	ListNode* removeElements(ListNode* head, int val) {
		// 处理 head
		while (head != nullptr && head->val == val)
		{
			if (head->val == val)
			{
				head = head->next;
			}
		}

		// 处理后面所有的
		ListNode* cur = head;
		while (cur != nullptr && cur->next != nullptr)
		{
			if (cur->next->val == val)
			{
				cur->next = cur->next->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return head;
	}

	// 28ms(99.64%), 10.9MB(100%)
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* res = new ListNode(0);
		res->next = head;

		ListNode* cur = res;
		while (cur != nullptr && cur->next != nullptr)
		{
			if (cur->next->val == val)
			{
				cur->next = cur->next->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return res->next;
	}

	// 递归 28ms(99.64%), 11.6MB(14.35%)
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr) return nullptr;
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};
#pragma endregion
