
#pragma region 989_数组形式的整数加法
/*
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

示例 1：
输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234

示例 2：
输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455

示例 3：
输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021

示例 4：
输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
 
提示：
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
如果 A.length > 1，那么 A[0] != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// A.Length <= 10000, 所以不能List->int再相加
	// K -> list, 再翻转相加, 再翻转
	//Runtime: 64 ms, faster than 87.46% of C++ online submissions for Add to Array-Form of Integer.
	//Memory Usage : 28.7 MB, less than 11.11 % of C++ online submissions for Add to Array - Form of Integer.
	vector<int> addToArrayForm2(vector<int>& A, int K) {
		vector<int> B;
		while (K != 0)
		{
			B.push_back(K % 10);
			K /= 10;
		}
		reverse(A.begin(), A.end());

		int index = 0;
		bool bIsOver = false;
		vector<int> res;
		while (index < A.size() && index < B.size())
		{
			int sum = A[index] + B[index] + (bIsOver ? 1 : 0);
			if (sum >= 10)
			{
				sum -= 10;
				bIsOver = true;
			}
			else
			{
				bIsOver = false;
			}
			res.push_back(sum);
			++index;
		}

		while (index < A.size())
		{
			// A更长
			int sum = A[index] + (bIsOver ? 1 : 0);
			if (sum >= 10)
			{
				sum -= 10;
				bIsOver = true;
			}
			else
			{
				bIsOver = false;
			}
			res.push_back(sum);
			++index;
		}

		while (index < B.size())
		{
			// B更长
			int sum = B[index] + (bIsOver ? 1 : 0);
			if (sum >= 10)
			{
				sum -= 10;
				bIsOver = true;
			}
			else
			{
				bIsOver = false;
			}
			res.push_back(sum);
			++index;
		}

		if (bIsOver)
		{
			res.push_back(1);
		}
		reverse(res.begin(), res.end());
		return res;
	}

	// 更巧妙的逐位相加, K不需要额外的List
	//Runtime: 56 ms, faster than 95.35% of C++ online submissions for Add to Array-Form of Integer.
	//Memory Usage : 29 MB, less than 11.11 % of C++ online submissions for Add to Array - Form of Integer.
	vector<int> addToArrayForm3(vector<int>& A, int K) {
		vector<int> res;
		int index = A.size() - 1;
		while (index >= 0 || K > 0)
		{
			if (index >= 0)
			{
				K += A[index];
			}
			res.push_back(K % 10);
			K /= 10;
			--index;
		}
		reverse(res.begin(), res.end());
		return res;
	}

	// 直接对原数组操作更省空间
	//Runtime: 44 ms, faster than 99.91% of C++ online submissions for Add to Array-Form of Integer.
	//Memory Usage : 27.4 MB, less than 11.11 % of C++ online submissions for Add to Array - Form of Integer.
	vector<int> addToArrayForm(vector<int>& A, int K) {
		reverse(A.begin(), A.end());
		int index = 0;
		while (K > 0)
		{
			if (index < A.size())
			{
				K += A[index];
				A[index] = K % 10; // 未越界, 直接赋值
			}
			else
			{
				A.push_back(K % 10); // 越界了, push
			}

			K /= 10;
			++index;
		}
		reverse(A.begin(), A.end());
		return A;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<int> temp{ 1,2,0,0 };
	int k = 34;
	s.addToArrayForm(temp, k);
}