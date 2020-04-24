
#pragma region Interview_0051_�����е������
/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������

ʾ�� 1:

����: [7,5,6,4]
���: 5

���ƣ�
0 <= ���鳤�� <= 50000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	// ���� - ���Իᳬʱ
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

	// �鲢 [7 5 6 4]
	int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
		if (l >= r) {
			return 0;
		}

		int mid = (l + r) / 2;
		// ��l, mid���1ʱ, Ϊ��Ϊ�鲢����, ������֮����copy��ԭ����
		int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
		// �����߼����������������������, �ڼ�����ͬʱ������
		int i = l, j = mid + 1, pos = l;
		while (i <= mid && j <= r) {
			// �����ź���������, ��ֵ����ֵС, ��ζ��, ����������ֵ֮ǰ�Ķ�����ֵС, (j - (mid + 1))������
			// Ȼ����ֵ������
			if (nums[i] <= nums[j]) {
				tmp[pos] = nums[i];  // ������ֵ������ֵ�����Ƶ�ʱ���ܱ�֤�ǵ�ʱ��С��, ������ʱ����
				++i;
				inv_count += (j - (mid + 1));
			}
			// ��ֵ����ֵ��, ��ֱֵ��������
			else {
				tmp[pos] = nums[j]; // ������ֵ������ֵ�����Ƶ�ʱ���ܱ�֤�ǵ�ʱ��С��, ������ʱ����
				++j;
			}
			++pos;
		}
		// ��ʣ���������鿽����tmp��
		for (int k = i; k <= mid; ++k) {
			tmp[pos++] = nums[k];
			inv_count += (j - (mid + 1)); // ��ʱ�������Ѿ���ȫ�������, �������ﴦ�����ֵһ�����Ұ����������ֵ����
		}
		// ��ʣ����Ұ����鿽����tmp��
		for (int k = j; k <= r; ++k) {
			tmp[pos++] = nums[k];	// ��ʱ��ֵ�Ѵ�����, �Ұ�����ֱ������ĩβ����
		}
		// ������õ�tmpȡ��ԭ����
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
