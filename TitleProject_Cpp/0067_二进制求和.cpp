
#pragma region 67_二进制求和
/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 一位一位算
	//Runtime: 4 ms, faster than 80.07% of C++ online submissions for Add Binary.
	//Memory Usage : 9.3 MB, less than 49.09 % of C++ online submissions for Add Binary.
	string addBinary(string a, string b) {
		string res = "";
		int indexA = a.length() - 1;
		int indexB = b.length() - 1;
		int isAdd = 0;
		while (indexA >= 0 && indexB >= 0)
		{
			int temp = a[indexA] - 48 + b[indexB] - 48 + isAdd;
			isAdd = temp > 1 ? 1 : 0;
			res = (temp % 2 == 0 ? "0" : "1") + res;

			--indexA;
			--indexB;
		}

		string target = (indexA < 0) ? b : a;
		int targetIdx = (indexA < 0) ? indexB : indexA;
		while (targetIdx >= 0)
		{
			int temp = target[targetIdx] - 48 + isAdd;
			isAdd = temp > 1 ? 1 : 0;
			res = (temp % 2 == 0 ? "0" : "1") + res;

			--targetIdx;
		}

		if (isAdd == 1)
		{
			res = "1" + res;
		}
		return res;
	}

	// 可以合并
	// push_back好像更慢了??
	//Runtime: 8 ms, faster than 26.96 % of C++ online submissions for Add Binary.
	//Memory Usage : 8.5 MB, less than 94.55 % of C++ online submissions for Add Binary.
	string addBinary(string a, string b) {
		string res = "";
		int indexA = a.length() - 1;
		int indexB = b.length() - 1;
		int isAdd = 0;
		while (indexA >= 0 || indexB >= 0 || isAdd == 1)
		{
			int temp = (indexA < 0 ? 0 : a[indexA] - 48) + (indexB < 0 ? 0 : b[indexB] - 48) + isAdd;
			isAdd = temp > 1 ? 1 : 0;
			res.push_back(temp % 2 + '0');

			--indexA;
			--indexB;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#pragma endregion
