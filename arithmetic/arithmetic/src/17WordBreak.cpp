#include "../include/17WordBreak.h"

#if 0
bool WordBreak(string s, vector<string>& wordDict)
{
	if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
		return true;


	for(int i = 1; i < s.size(); i++)
	{
		if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end())
		{
			if (WordBreak(s.substr(i), wordDict))//如果剩余子串也找到索引
				return true;
		}
	}
	
	return false;
}

#else
bool WordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> wordDictSet (wordDict.begin(), wordDict.end());
	vector<bool> dp(s.size()+1);
	
	dp[0] = true;
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
				dp[i] = true;
				break;
			}
		}
	}
	for (vector<bool>::iterator iter = dp.begin(); iter != dp.end(); iter++)
		cout << *iter << endl;
	return dp[s.size()];
}

#endif