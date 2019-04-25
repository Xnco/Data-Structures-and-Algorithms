
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 202_快乐数
/*
编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
示例:
输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
	// 用 map 记录
	// 8ms(34.4%), 8.7MB(5.6%)
	bool isHappy(int n) {
		map<int, bool> res;
		while (true)
		{
			int sum = 0;
			while (n != 0)
			{
				int num = n % 10;
				sum += num * num;
				n /= 10;
			}
			if (sum == 1)
			{
				return true;
			}
			if (res.find(sum) == res.end())
			{
				res[sum] = true;
				n = sum;
			}
			else
			{
				return false;
			}
		}
	}
};

#pragma endregion
