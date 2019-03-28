#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 941_有效的山脉数字
/*
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[B.length - 1]
示例 1：
输入：[2,1]
输出：false
示例 2：
输入：[3,5,5]
输出：false
示例 3：
输入：[0,3,2,1]
输出：true
提示：
0 <= A.length <= 10000
0 <= A[i] <= 10000
*/

class Solution {
	// 44ms(20%), 10.6MB(0%)
public:
	bool validMountainArray(vector<int>& A) {
		int len = A.size();
		if (len < 3)
			return false;
		bool c1 = false;
		bool c2 = false;
		for (size_t i = 0; i < len - 1; i++)
		{
			if (A[i] - A[i + 1] < 0)
			{
				// 后面的大
				if (c2)
				{
					return false;
				}
				c1 = true;
			}
			else if (A[i] - A[i + 1] > 0)
			{
				// 前面的大
				if (!c1)
				{
					return  false;
				}
				c2 = true;
			}
			else
			{
				return false;
			}
		}

		return c1 && c2;
	}

	// 36ms(75.6%), 10.4MB(100%)
	bool validMountainArray(vector<int>& A) {
		int len = A.size();
		if (len < 3)
		{
			return false;
		}
		int i;
		for (i = 1; i < len && A[i - 1] < A[i]; i++);
		if (i == 1 || i == len)
		{
			return false;
		}

		for (; i < len && A[i - 1] > A[i]; i++);

		return i == len;
	}
};
#pragma endregion