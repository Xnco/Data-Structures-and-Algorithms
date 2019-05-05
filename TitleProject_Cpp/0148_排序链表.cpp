
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 148_排序链表
/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4
示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5
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
	// 72ms(29.31%), 13.8MB(49.79%)
	ListNode* sortList(ListNode* head) {

		vector<int> res;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}

		sort(res.begin(), res.end());

		ListNode* newhead = new ListNode(0);
		ListNode* cur = newhead;
		for (auto item : res)
		{
			cur->next = new ListNode(item);
			cur = cur->next;
		}
		return newhead->next;
	}
};
#pragma endregion
