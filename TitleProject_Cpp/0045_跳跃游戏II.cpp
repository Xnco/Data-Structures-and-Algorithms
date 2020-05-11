
#pragma region 45_跳跃游戏II
/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明:
假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 贪心, 反向推出到目的地的最小值, but outtime...
	int jump(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> JumpNums(nums.size()); // 记录从index到最后需要的最小步数
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			int min = INT_MAX - 1;
			for (int j = nums[i]; j > 0; --j) // 反序判断能否到达目的地
			{
				if (i + j >= nums.size() - 1)
				{
					JumpNums[i] = 1; // 一步到位
					min = 0;
					break;
				}

				if (min > JumpNums[i + j])
				{
					min = JumpNums[i + j];
				}
			}
			JumpNums[i] = min + 1;
		}
		return JumpNums[0];
	}

	// 贪心的简介算法 -- 依旧超时
	int jump(vector<int>& nums) {
		int pos = nums.size() - 1;
		int res = 0;
		while (pos > 0)
		{
			for (int i = 0; i < pos; ++i)
			{
				if (i + nums[i] >= pos) // 正序判断能到达目的地
				{
					pos = i;
					++res;
					break;
				}
			}
		}
		return res;
	}

	// 贪心再优化, 跳跃到边界不必折返, 多指针
	//Runtime: 8 ms, faster than 93.16% of C++ online submissions for Jump Game II.
	//Memory Usage : 7.9 MB, less than 100.00 % of C++ online submissions for Jump Game II.
	int jump(vector<int>& nums)
	{
		int end = 0; // 某一次跳跃可到达的最远距离
		int maxDist = 0; // 到最远距离过程中, 能达到的最远距离 -> 下一次跳跃的边界
		int res = 0;
		int len = nums.size() - 1;
		for (int i = 0; i < len; ++i)
		{
			if (maxDist >= i)
			{
				maxDist = max(maxDist, i + nums[i]); // 得到一步之内能到达最远的地方
				if (i == end) // 到达当前边界
				{
					end = maxDist; // 将边界设置到最远处, 记跳一步
					++res;
				}
			}
		}
		return res;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<int> list{ 2,3,1,1,4 };
	s.jump(list);
}