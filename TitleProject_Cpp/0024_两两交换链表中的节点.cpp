
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 24_两两交换链表中的节点
/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
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
	// 迭代 : 8ms(38%), 8.88MB(87%)
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;

		ListNode * cur = head;
		ListNode * before = nullptr;
		head = head->next;
		while (cur != nullptr)
		{

			ListNode* first = cur;
			ListNode* second = first->next;
			if (second == nullptr)
			{
				break;
			}
			if (before != nullptr)
			{
				before->next = second;
			}
			before = first;
			first->next = second->next;
			second->next = first;
			cur = first->next;
		}
		return head;
	}

	// 递归 - 4ms(100%), 8.7MB(98.65%)
	ListNode* swapPairs(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* second = head->next;
		head->next = swapPairs(second->next);
		second->next = head;
		return second;
	}
};
#pragma endregion
