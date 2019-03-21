#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 119_杨辉三角II
/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
示例:
输入: 3
输出: [1,3,3,1]
进阶：
你可以优化你的算法到 O(k) 空间复杂度吗？
*/
// 8ms, 8.3MB
class Solution {
public:
	vector<int> getRow(int rowIndex) {

		// begin line 2
		vector<int> cur;
		cur.push_back(1);
		if (rowIndex == 0)
		{
			return cur;
		}
		cur.push_back(1);

		vector<int> next;
		for (size_t i = 0; i < rowIndex - 1; i++)
		{
			next.push_back(1);
			for (size_t i = 0; i < cur.size() - 1; i++)
			{
				next.push_back(cur[i] + cur[i + 1]);
			}
			next.push_back(1);

			cur = next;
			vector<int> tmp;
			next = tmp;
		}
		return cur;
	}
};
#pragma endregion