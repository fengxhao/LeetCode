//438. Find All Anagrams in a String
//Input:
//s: "cbaebabacd" p: "abc"
//Output:
//[0, 6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//采用两个hash_map来保存mp1主要存p，mp2,主要用来存s的，使用固定窗口大小。
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		unordered_map<char, int>mp1;
		unordered_map<char, int>mp2;
		vector<int> res;
		int  flag = 1;
		for (int i = 0; i<p.size(); i++)
			mp1[p[i]]++;
		for (int j = 0; j < s.size(); j++)
		{
			flag = 1;
			mp2[s[j]]++;
			if (j >= p.size())
			{
				mp2[s[j - p.size()]]--;
				
			}
			   for (auto &s : mp1)
				{
					if (s.second == mp2[s.first])
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					res.push_back(j - p.size()+1);
		}
		return res;
	}
};