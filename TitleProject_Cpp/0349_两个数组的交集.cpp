
#pragma region 349_两个数组的交集
/*
给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 各遍历一次, 将出现过的存在map中
	// 16ms(73.5%), 9.3MB(61.72%)
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> temp;
		vector<int> res;

		for (size_t i = 0; i < nums1.size(); i++)
		{
			if (temp.find(nums1[i]) == temp.end())
			{
				temp[nums1[i]] = 1;
			}
		}

		for (size_t i = 0; i < nums2.size(); i++)
		{
			if (temp.find(nums2[i]) != temp.end())
			{
				if (find(res.begin(), res.end(), nums2[i]) == res.end())
				{
					res.push_back(nums2[i]);
				}
			}
		}
		return res;
	}
};
#pragma endregion
