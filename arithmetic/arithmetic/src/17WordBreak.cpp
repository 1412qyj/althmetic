#include "../include/17WordBreak.h"

bool WordBreak(string s, vector<string>& wordDict)
{
	string s_cmp;

	for (int i = 0; i < wordDict.size(); i++)
		s_cmp += wordDict[i];

	if (s_cmp == s)
	{
		return true;
	}
	else
	{
		return false;
	}
}