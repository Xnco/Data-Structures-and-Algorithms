
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 520_检测大写字母
/*
给定一个单词，你需要判断单词的大写使用是否正确。
我们定义，在以下情况时，单词的大写用法是正确的：
全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。
示例 1:
输入: "USA"
输出: True
示例 2:
输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
*/

class Solution {
public:
	// 巧妙的做法 4ms(100%), 8.4MB(98.75%)
	bool detectCapitalUse(string word) {

		int num = 0;
		for (size_t i = 0; i < word.size(); i++)
		{
			if (isUpper(word[i]))
			{
				if (num < i) // 只要有一个大写字母出现在小写字母后面就是false
				{
					return false;
				}
				num++;
			}
		}

		// 要不大写字符数量 == 字符串长度
		// 要不大写字母没有或只有一个
		return num == word.size() || num <= 1;
	}

	bool isUpper(char c)
	{
		return c >= 'A' && c <= 'Z';
	}
};
#pragma endregion
