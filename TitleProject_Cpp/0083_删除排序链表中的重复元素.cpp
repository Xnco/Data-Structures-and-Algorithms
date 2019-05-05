
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 83_删除排序链表中的重复元素
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
示例 1:
输入: 1->1->2
输出: 1->2
示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
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
	// 迭代 16ms(39.6%), 10.1MB(5.19%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		map<int, bool> all;
		all[head->val] = true;
		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			if (all.find(cur->next->val) == all.end())
			{
				all[cur->next->val] = true;
				cur = cur->next;
			}
			else
			{
				cur->next = cur->next->next;
			}
		}
		return head;
	}

	// 迭代方法2, 没注意这是个排序链表, 这样更快
	// 12ms(100%), 9.4MB(10.6%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return nullptr;
		}

		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			if (cur->val == cur->next->val)
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

	// 递归 -> 因为这是个排序链表
	// 传入一个节点, 返回自己, 处理好后代
	// 12ms(100%), 9.4MB(7.7%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		head->next = deleteDuplicates(head->next);
		if (head->next->val == head->val)
		{
			head->next = head->next->next;
		}
		return head;
	}
};
#pragma endregion
