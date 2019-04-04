#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>

using namespace std;

#pragma region 92_反转链表 II
/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution92 {
	// 4ms(100%), 8.7MB(95.13%)
public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* left = head;
		for (int i = 0; i < m - 2; i++)
		{
			left = left->next;
		}

		ListNode* begin = left;
		if (m != 1)
		{
			begin = begin->next;
		}
		ListNode* cur = begin;
		ListNode* mid = cur->next;
		for (int i = 0; i < n - m; i++)
		{
			ListNode* temp = mid->next;
			mid->next = cur;
			cur = mid;
			mid = temp;
			if (mid == nullptr)
			{
				break;
			}
		}
		begin->next = mid;
		if (m != 1)
		{
			left->next = cur;
			return head;
		}
		else
		{
			return cur;
		}
	}
};
#pragma endregion

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution92 s;
	s.reverseBetween(head, 1, 5);
}