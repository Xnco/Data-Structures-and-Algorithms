
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 82_删除排序链表中的重复元素 II
/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:
输入: 1->1->1->2->3
输出: 2->3
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
	// 单用迭代和递归就可以了
	// 迭代 + 递归 (思路还不够简洁) 8ms(100%), 9.2MB(30.5%)
	ListNode* deleteDuplicates(ListNode* head) {
		head = getNotEqual(head); // 首个特殊处理
		if (head == nullptr)
		{
			return head;
		}
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* old = cur->next;
			cur->next = getNotEqual(cur->next);
			if (old == cur->next)
			{
				// 没变
				cur = cur->next;
			}
		}
		return head;
	}

	// 传入一个节点, 如果有重复就返回不重复的那个
	// 如果没重复就返回自己
	ListNode* getNotEqual(ListNode* head)
	{
		ListNode* cur = head;
		int count = 1;
		while (cur != nullptr)
		{
			if (cur->next == nullptr || cur->next->val != cur->val)
			{
				break;
			}
			cur = cur->next;
			count++;
		}
		if (count > 1)
		{
			return getNotEqual(cur->next);
		}
		return head;
	}
};
#pragma endregion

int main()
{
	ListNode* cur = new ListNode(1);
	cur->next = new ListNode(2);
	cur->next->next = new ListNode(2);
	Solution s;
	s.deleteDuplicates(cur);
}