//Word Pattern
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//现把str的单词分割存到一个vector 里面去，然后采用两个hash-map 存这两个模式，比较对应的单词。
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> st;
		string temp;
		for (auto i : str)
		{
			if (i == ' ')
			{
				st.push_back(temp);
				temp = "";
			}
			else
			{
				temp = temp + i;
			}
		}
		st.push_back(temp);
		if (st.size() != pattern.size())
			return false;
		unordered_map<char, string> mp1;
		unordered_map<string, char>map2;
		for (int i = 0; i < st.size(); i++)
		{
			if (mp1.find(pattern[i]) == mp1.end() && map2.find(st[i]) == map2.end())
			{
				mp1[pattern[i]] = st[i];
				map2[st[i]] = pattern[i];
			}
			else if (mp1[pattern[i]] != st[i])
				return false;

		}
		return true;
	}
};

