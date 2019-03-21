#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;

using namespace std;

#pragma region 412_Fizz Buzz
/*
写一个程序，输出从 1 到 n 数字的字符串表示。
1. 如果 n 是3的倍数，输出“Fizz”；
2. 如果 n 是5的倍数，输出“Buzz”；
3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
示例：
n = 15,
返回:
[
	"1",
	"2",
	"Fizz",
	"4",
	"Buzz",
	"Fizz",
	"7",
	"8",
	"Fizz",
	"Buzz",
	"11",
	"Fizz",
	"13",
	"14",
	"FizzBuzz"
]
*/
// 28ms(击败1%), 10.3MB
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;

		for (int i = 1; i <= n; i++)
		{
			if (i % 15 == 0)
			{
				result.push_back("FizzBuzz");
			}
			else if (i % 5 == 0)
			{
				result.push_back("Buzz");
			}
			else if (i % 3 == 0)
			{
				result.push_back("Fizz");
			}
			else
			{
				result.push_back(to_string(i));
			}
		}
		return result;
	}
};

#pragma endregion