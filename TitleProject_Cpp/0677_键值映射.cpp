
#pragma region 677_键值映射
/*
实现一个 MapSum 类里的两个方法，insert 和 sum。
对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
示例 1:
输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MapSum {
public:
	map<string, int> mp;
	/** Initialize your data structure here. */
	MapSum() {

	}

	void insert(string key, int val) {
		mp[key] = val;

	}

	// 暴力find
	//Runtime: 4 ms, faster than 75.62% of C++ online submissions for Map Sum Pairs.
	//Memory Usage : 9.4 MB, less than 100.00 % of C++ online submissions for Map Sum Pairs.
	int sum(string prefix) {
		int ans = 0;
		string s;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			s = it->first;
			if (s.find(prefix) == 0)
			{
				ans += (it->second);
			}
		}
		return ans;
	}
};

// 前缀树
class Trie {
public:
	bool isEnd = false;
	unordered_map<char, Trie*> m; // map是红黑树, unordered_map是哈希表
	int val = 0;

	Trie() {}

	void insert(string key, int val) {
		Trie* cur = this;
		for (char c : key) {
			if (!cur->m.count(c)) {
				cur->m[c] = new Trie();
			}
			cur = cur->m[c];
		}
		cur->isEnd = true;
		cur->val = val;
	}

	int sum(string prefix) {
		Trie* cur = this;
		for (char c : prefix) {
			if (!cur->m.count(c)) {
				return 0;
			}
			cur = cur->m[c];
		}
		return dfs(cur);
	}

	int dfs(Trie* cur) {
		int val = cur->isEnd ? cur->val : 0;
		for (auto p : cur->m) {
			val += dfs(p.second);
		}
		return val;
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
#pragma endregion
