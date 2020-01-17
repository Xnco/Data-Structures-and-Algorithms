
#pragma region 445_两数相加 II
/*
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

 

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	// 将数据压入栈, 不对原链表操作
	//Runtime: 28 ms, faster than 52.22% of C++ online submissions for Add Two Numbers II.
	//Memory Usage : 14.4 MB, less than 14.81 % of C++ online submissions for Add Two Numbers II.
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1;
		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}

		stack<int> s2;
		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}

		ListNode* res = nullptr;
		bool flag = false;
		while (s1.size() != 0 || s2.size() != 0)
		{
			int num1 = 0;
			int num2 = 0;
			if (s1.size() != 0)
			{
				num1 = s1.top();
				s1.pop();
			}

			if (s2.size() != 0)
			{
				num2 = s2.top();
				s2.pop();
			}

			int sum = num1 + num2 + (flag ? 1 : 0);
			flag = false;
			if (sum > 9)
			{
				sum -= 10;
				flag = true;
			}
			ListNode* node = new ListNode(sum);
			node->next = res;
			res = node;
		}
		if (flag)
		{
			ListNode* node = new ListNode(1);
			node->next = res;
			res = node;
		}
		return res;
	}
};
#pragma endregion
