
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1019_链表中的下一个更大节点
/*
给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。
每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，
那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。
返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。
注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。
示例 1：
输入：[2,1,5]
输出：[5,5,0]
示例 2：
输入：[2,7,4,3,5]
输出：[7,0,5,5,0]
示例 3：
输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]
提示：
对于链表中的每个节点，1 <= node.val <= 10^9
给定列表的长度在 [0, 10000] 范围内
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
	// 暴力 - 果然超时
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res;
		if (head == nullptr)
		{
			return res;
		}

		// 全部存入数组中
		int num;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}

		int len = res.size();
		for (int i = 0; i < len; i++)
		{
			int temp = i;
			while (++temp < res.size())
			{
				if (res[i] < res[temp])
				{
					res[i] = res[temp];
					break;
				}
			}
			if (temp == len)
			{
				res[i] = 0;
			}
		}
		return res;
	}

	// 单栈 - 将数字一一入栈, 当后面出现一个数比前一个数大时出栈, 并更新当前位置的val
	// 212ms(92.44%), 25.8MB(43.33%)
	vector<int> nextLargerNodes(ListNode* head) {
		int count = 0;
		vector<int> res;

		stack<pair<int, int>> temp; // first: value, second: index
		while (head)
		{
			res.push_back(0);
			// 栈不空且head的val大于栈顶的值
			while (!temp.empty() && head->val > temp.top().first)
			{
				res[temp.top().second] = head->val;
				temp.pop();
			}
			temp.push(pair<int, int>(head->val, count++));
			head = head->next;
		}
		return res;
	}
};
#pragma endregion
