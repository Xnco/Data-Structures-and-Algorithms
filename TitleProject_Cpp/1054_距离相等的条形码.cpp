
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1054_距离相等的条形码
/*
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。
示例 1：
输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：
输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
提示：
1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/

class Solution {
public:
	// 因为一定有解, 所以最多的数不超过 1/2
	// 排序再奇偶插入 - 如果一段数字没有一次性处理完就可能出现连续的情况
	// 还是得统计, 思考不统计的方法...
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> res(barcodes.size());

		sort(barcodes.begin(), barcodes.end());

		int count = 0;
		for (size_t i = 0; i < res.size(); i += 2)
		{
			res[i] = barcodes[count++];
		}
		for (size_t i = 1; i < res.size(); i += 2)
		{
			res[i] = barcodes[count++];
		}

		return res;
	}

	// 统计数字出现的次数, 次数最多的先奇偶插入
	// 224ms(74.9%), 20.3MB(100%)
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {

		vector<int> res(barcodes.size());

		map<int, int> numpair;

		for (auto item : barcodes)
		{
			numpair[item]++;
		}

		int maxKey;
		// 找到最多的key
		for (auto item : numpair)
		{
			if (item.second > numpair[maxKey])
				maxKey = item.first;
		}

		// 先将最多的填完
		int evenIndex = 0;
		while (numpair[maxKey] > 0)
		{
			res[evenIndex] = maxKey;
			numpair[maxKey]--;
			evenIndex += 2;
		}
		int oddIndex = 1;
		for (auto item : numpair)
		{
			// 将剩余偶数位置填完
			while (evenIndex < res.size() && item.second > 0)
			{
				res[evenIndex] = item.first;
				item.second--;
				evenIndex += 2;
			}

			// 奇数
			while (oddIndex < res.size() && item.second > 0)
			{
				res[oddIndex] = item.first;
				item.second--;
				oddIndex += 2;
			}
		}
		return res;
	}
};
#pragma endregion
