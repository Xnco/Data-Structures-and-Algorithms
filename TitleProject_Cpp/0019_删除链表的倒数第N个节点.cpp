
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 19_删除链表的倒数第N个节点
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
给定的 n 保证是有效的。
进阶：
你能尝试使用一趟扫描实现吗？
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
	// 双指针 - 4ms(100%), 8.6MB(100%)
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* first = head;
		ListNode* second = head;

		// 前指针先走n步
		for (size_t i = 0; i < n; i++)
		{
			second = second->next;
		}
		if (second == nullptr)
		{
			// 直接走到底之后 -> 说明移除的是head
			return head->next;
		}

		// 双指针同时前进 -> 
		while (true)
		{
			second = second->next;
			if (second == nullptr)
			{
				first->next = first->next->next;
				return head;
			}
			first = first->next;
		}
	}
};

#pragma endregion
