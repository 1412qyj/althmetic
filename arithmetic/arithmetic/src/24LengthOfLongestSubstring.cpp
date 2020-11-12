#include "../include/24LengthOfLongestSubstring.h"

int LengthOfLongestSubstring(string s)
{
	int curMax = 1;
	int Max = 1;
	vector<char> vecCur;

	for (int i = 0; i < s.size(); i++)
	{
		vecCur.push_back(s[i]);
		for (int j = i + 1; j < s.size(); j++)
		{
			//在现有的最大字串中找当前的字符
			if (find(vecCur.begin(), vecCur.end(), s[j]) == vecCur.end())
			{
				vecCur.push_back(s[j]);
				curMax++;
				continue;
			}

			Max = (curMax > Max) ? curMax : Max;
			
			curMax = 0;
			vecCur.clear();
		}
	}

	return Max;
}