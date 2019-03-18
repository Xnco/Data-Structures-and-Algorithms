#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 413_等差数列划分
/*
如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。
例如，以下数列为等差数列:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
以下数列不是等差数列。
1, 1, 2, 5, 7
数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
如果满足以下条件，则称子数组(P, Q)为等差数组：
元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
函数要返回数组 A 中所有为等差数组的子数组个数。
示例:
A = [1, 2, 3, 4]
返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。
*/
// 动态规划 
// 8ms, 8.6MB
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
		{
			return 0;
		}
		int dp = 0;
		int sum = 0;
		int sub = A[1] - A[0];
		for (int i = 2; i < A.size(); ++i) {
			int newSub = A[i] - A[i - 1];
			if (newSub == sub)
			{
				dp++;
				sum += (dp);
			}
			else
			{
				dp = 0;
			}
			sub = newSub;
		}
		return sum;
	}

public:
	int numberOfArithmeticSlices2(vector<int>& A) {
		int l = A.size();
		if (l == 0)
		{
			return 0;
		}
		int count = 0;
		for (size_t i = 0; i < l - 2; i++)
		{
			int sub = A[i + 1] - A[i];
			if (A[i + 2] - A[i + 1] == sub)
			{
				count++;
			}
			int num = 2;
			while (i + num < l - 1)
			{
				if (A[i + num + 1] - A[i + num] == sub)
				{
					count++;
					num++;
				}
			}
		}
		return count;
	}
};
#pragma endregion
