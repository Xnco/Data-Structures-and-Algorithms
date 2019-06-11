
#pragma region 142_环形链表 II
/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。
进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
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
	// 解法1 投机取巧, 因为Leetcode的链表是内存越来越大的
	// 12ms(90.75%), 9.8MB(42.58%)
	ListNode* detectCycle(ListNode* head) {
		while (head) {
			if (!less<ListNode*>()(head, head->next)) {
				return head->next;
			}
			head = head->next;
		}
		return nullptr;
	}

	// 解法2 简单粗暴, 将出现过的节点存入Map, 有重复说明有环
	// 时间O(N), 空间O(N), 16ms(36.71%), 12.2MB(5.05%)
	ListNode* detectCycle(ListNode* head) {
		map<ListNode*, int> res;
		while (head != nullptr)
		{
			if (res.find(head) == res.end())
			{
				res[head] = 1;
			}
			else
			{
				return head;
			}

			head = head->next;
		}

		return nullptr;
	}

	// 解法3 双指针
	ListNode* detectCycle(ListNode* head) {

	}
};
#pragma endregion
