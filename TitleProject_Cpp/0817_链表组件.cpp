
#pragma region 817_链表组件
/*
给定一个链表（链表结点包含一个整型值）的头结点 head。
同时给定列表 G，该列表是上述链表中整型值的一个子集。
返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
示例 1：
输入:
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释:
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
示例 2：
输入:
head: 0->1->2->3->4
G = [0, 3, 1, 4]
输出: 2
解释:
链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
注意:
如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000
G 是链表中所有结点的值的一个子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-components
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
	// 暴力 - 时间换空间, 就原地判断
	//Runtime: 288 ms, faster than 5.35% of C++ online submissions for Linked List Components.
	//Memory Usage : 12.7 MB, less than 89.47 % of C++ online submissions for Linked List Components.
	int numComponents(ListNode* head, vector<int>& G) {
		int res = 0;
		int len = 0;
		while (head != nullptr)
		{
			if (Contain(G, head->val))
			{
				len++;
			}
			else
			{
				if (len != 0)
				{
					res++;
					len = 0;
				}
			}

			head = head->next;
		}
		if (len > 0)
		{
			res++;
		}
		return res;
	}

	bool Contain(vector<int>& G, int value)
	{
		for (int i = 0; i < G.size(); ++i)
		{
			if (value == G[i])
			{
				return true;
			}
		}
		return false;
	}

	// 空间换时间 - 用额外的 unordered_set
	//Runtime: 28 ms, faster than 99.35% of C++ online submissions for Linked List Components.
	//Memory Usage : 14.7 MB, less than 26.32 % of C++ online submissions for Linked List Components.

	static const auto fast = []() {
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
		return 0;
	} ();

	int numComponents(ListNode* head, vector<int>& G) {
		int res = 0;
		unordered_set<int> temp(G.begin(), G.end());
		int len = 0;
		while (head != nullptr)
		{
			if (temp.count(head->val))
			{
				len++;
			}
			else
			{
				if (len != 0)
				{
					res++;
					len = 0;
				}
			}

			head = head->next;
		}
		if (len > 0)
		{
			res++;
		}
		return res;
	}
};
#pragma endregion
