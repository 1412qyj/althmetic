#include "../include/17WordBreak.h"

#if 1
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
	int l = 0;//左pos
	int r = 1;//右pos
	
	while (!s.empty())
	{
		//此时找到的r是这个单词的后一个位置
		if (find(wordDict.begin(), wordDict.end(), s.substr(l, r)) != wordDict.end())
		{
			//找到就擦除
			s.erase(0, r);
			r = 1;
			continue;
		}

		if (r == s.size())
			break;

		r++;
	}

	return s.empty();
}

#endif