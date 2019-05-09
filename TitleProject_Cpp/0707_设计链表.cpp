// TitleProject_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 707_设计链表
/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
示例：
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
提示：
所有值都在 [1, 1000] 之内。
操作次数将在  [1, 1000] 之内。
请不要使用内置的 LinkedList 库。
*/
// 52ms(85.8%), 19.2MB(99.8%)
class MyLinkedList {

	class Node
	{
	public:
		Node(int val) {
			this->val = val;
			next = nullptr;
		}
		int val;
		Node* next;
	};

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		count = 0;
	}

	Node* head;
	int count;

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= count) return -1;

		Node * cur = head;
		for (size_t i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* res = new Node(val);
		res->next = head;
		head = res;
		count++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head == nullptr)
		{
			head = new Node(val);
			return;
		}
		Node* cur = head;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(val);
		count++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	// 好无语的设计, 如果index<0, 默认是0
	void addAtIndex(int index, int val) {
		if (index > count) return;
		else if (index <= 0)
		{
			addAtHead(val);
			return;
		}
		else if (index == count)
		{
			addAtTail(val);
			return;
		}

		Node* cur = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		Node* tmp = cur->next;
		cur->next = new Node(val);
		cur->next->next = tmp;
		count++;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= count) return;
		else if (index == 0)
		{
			head = head->next;
			return;
		}

		Node* cur = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		count--;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
#pragma endregion

int main()
{

}

