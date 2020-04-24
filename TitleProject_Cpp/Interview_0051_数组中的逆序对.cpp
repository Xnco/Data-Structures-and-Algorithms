
#pragma region Interview_0051_数组中的逆序对
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5

限制：
0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 暴力 - 明显会超时
	/*int reversePairs(vector<int>& nums) {
		int res = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] > nums[j]) ++res;
			}
		}
		return res;
	}*/

	// 归并 [7 5 6 4]
	int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
		if (l >= r) {
			return 0;
		}

		int mid = (l + r) / 2;
		// 当l, mid相差1时, 为仅为归并排序, 排序完之后再copy回原数组
		int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
		// 以下逻辑基于左右两数组是有序的, 在计数的同时并排序
		int i = l, j = mid + 1, pos = l;
		while (i <= mid && j <= r) {
			// 在已排好序的情况下, 左值比右值小, 意味着, 右数组在右值之前的都比左值小, (j - (mid + 1))即个数
			// 然后左值往后推
			if (nums[i] <= nums[j]) {
				tmp[pos] = nums[i];  // 不管左值还是右值往后推的时候都能保证是当时最小的, 填入临时数组
				++i;
				inv_count += (j - (mid + 1));
			}
			// 左值比右值大, 右值直接往后推
			else {
				tmp[pos] = nums[j]; // 不管左值还是右值往后推的时候都能保证是当时最小的, 填入临时数组
				++j;
			}
			++pos;
		}
		// 将剩余的左半数组拷贝到tmp中
		for (int k = i; k <= mid; ++k) {
			tmp[pos++] = nums[k];
			inv_count += (j - (mid + 1)); // 此时右数组已经完全处理完毕, 所以这里处理的左值一定比右半数组的所有值都大
		}
		// 将剩余的右半数组拷贝到tmp中
		for (int k = j; k <= r; ++k) {
			tmp[pos++] = nums[k];	// 此时左值已处理完, 右半数组直接推至末尾即可
		}
		// 将排序好的tmp取代原数组
		copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
		return inv_count;
	}

	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp(n);
		return mergeSort(nums, tmp, 0, n - 1);
	}
};
#pragma endregion
