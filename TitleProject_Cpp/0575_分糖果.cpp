
#pragma region 575_分糖果
/*
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。
你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
示例 1:
输入: candies = [1,1,2,2,3,3]
输出: 3
解析: 一共有三种种类的糖果，每一种都有两个。
	 最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
示例 2 :
输入: candies = [1,1,2,3]
输出: 2
解析: 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
注意:
数组的长度为[2, 10,000]，并且确定为偶数。
数组中数字的大小在范围[-100,000, 100,000]内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	/*
	const static auto ioSpeedUp = []() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		return NULL;
	}();
	*/
	//Runtime: 284 ms, faster than 73.65% of C++ online submissions for Distribute Candies.
	//Memory Usage : 54.6 MB, less than 33.33 % of C++ online submissions for Distribute Candies.
	int distributeCandies(vector<int>& candies) {
		set<int> pool; // 用bitset效率更高, 所有数据+100000
		for (int i = 0; i < candies.size(); ++i)
		{
			pool.insert(candies[i]);
		}
		return min(candies.size() / 2, pool.size());
	}
};
#pragma endregion
