
#pragma region 155_最小栈
/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

示例:
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 
提示：
pop、top 和 getMin 操作总是在 非空栈 上调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 用额外的一个有序空间来存储, push和pop时要索引一次, 但GetMin()直接得到最小的
//Runtime: 88 ms, faster than 11.47 % of C++ online submissions for Min Stack.
//Memory Usage : 16.3 MB, less than 100.00 % of C++ online submissions for Min Stack.
/*
class MinStack {
public:
	stack<int> myStack;
	vector<int> sortList;
	MinStack() {

	}

	void push(int x) {
		myStack.push(x);

		for (vector<int>::iterator it = sortList.begin(); it != sortList.end(); it++)
		{
			if (x > * it)
			{
				sortList.insert(it, x);
				return;
			}
		}
		sortList.push_back(x);
	}

	void pop() {
		//if (myStack.size() == 0) return;
		int x = top();
		for (vector<int>::iterator it = sortList.begin(); it != sortList.end(); it++)
		{
			if (x == * it)
			{
				sortList.erase(it);
				break;
			}
		}

		myStack.pop();
	}

	int top() {
		//if (myStack.size() == 0) return 0;
		return myStack.top();
	}

	int getMin() {
		//if (sortList.size() == 0) return 0;
		return sortList[sortList.size() - 1];
	}
};
*/
// 优化一版, 辅助列表不需要记录所有的数据, 只需要记录数据入栈的时候当前的最小值即可
//Runtime: 48 ms, faster than 23.55% of C++ online submissions for Min Stack.
//Memory Usage : 16.2 MB, less than 100.00 % of C++ online submissions for Min Stack.
/*
class MinStack {
public:
	stack<int> myStack;
	stack<int> exStack;
	MinStack() {

	}

	void push(int x) {
		myStack.push(x);

		if (exStack.size() == 0)
		{
			exStack.push(x);
			return;
		}
		int min = exStack.top();
		exStack.push(min < x ? min : x);
	}

	void pop() {
		myStack.pop();
		exStack.pop();
	}

	int top() {
		return myStack.top();
	}

	int getMin() {
		return exStack.top();
	}
};
*/
// 再优化一版, 不用辅助栈, 更新min的时候将上一个min记录, 相当于一个链表
//Runtime: 48 ms, faster than 23.55% of C++ online submissions for Min Stack.
//Memory Usage : 16 MB, less than 100.00 % of C++ online submissions for Min Stack.
class MinStack {
public:
	stack<int> myStack;
	int min;
	MinStack() {
		min = 0;
	}

	void push(int x) {
		if (myStack.size() == 0)
		{
			min = x;
		}
		else if (x <= min)
		{
			// 先记录一个最小值, 再更新min
			myStack.push(min);
			min = x;
		}
		myStack.push(x);
	}

	void pop() {
		int temp = myStack.top();
		if (myStack.size() == 1)
		{
			min = myStack.top();
		}
		else if (temp == min)
		{
			// 移除的是最小值
			myStack.pop();
			min = myStack.top();
		}
		myStack.pop();
	}

	int top() {
		return myStack.top();
	}

	int getMin() {
		return min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
#pragma endregion

int main()
{
	MinStack m;
	m.push(2147483646);
	m.push(2147483646);
	m.push(2147483647);
	m.top();
	m.pop();
	m.getMin();
	m.pop();
	m.getMin();
	m.pop();
	m.push(2147483647);
	m.top();
	m.getMin();
	m.push(INT_MIN);
	m.top();
	m.getMin();
	m.pop();
	m.getMin();
}