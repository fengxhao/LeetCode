//205Isomorphic Strings&&
//detail:
//For example,
//Given "egg", "add", return true.
//Given "foo", "bar", return false.
//Given "paper", "title", return true.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char,char>mp1;
         unordered_map<char,char>mp2;
         if(s.size()!=t.size())
         return false;
         for (int i=0;i<s.size();i++)
         {
             
            if(mp1.find(t[i])==mp1.end()&&mp2.find(s[i])==mp2.end())
              {
                  mp1[t[i]]=s[i];
                  mp2[s[i]]=t[i];
              }
            if(t[i]!=mp2[s[i]]||s[i]!=mp1[t[i]])
                return false; 
        }
         return true;
    }
};

//290. Word Pattern
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
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