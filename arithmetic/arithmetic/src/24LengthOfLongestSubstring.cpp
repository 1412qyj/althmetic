#include "../include/24LengthOfLongestSubstring.h"

#if 1

int LengthOfLongestSubstring(string s)
{
	int max = 0;//最大字串长度
	int tmpmax = 0;//当前周期字串长度
	int start = 0;//字串开始的下标位置
	int hashmap[128] = {0};//字符串哈希表（ascii一共128个）
	int i = 0;//循环下标

	for (i = 0; i < s.size(); i++)
	{
		if (hashmap[s[i]] > start)//如果哈希索引的值比start大，即遇到重复字符了
		{
			tmpmax = i - start;//获取当前的字串长度

			max = (tmpmax > max) ? tmpmax : max;//更新总的字串长度

			start = hashmap[s[i]];//将起始位置start的值设置成不存在当前字符的最新位置
		}

		hashmap[s[i]] = i + 1;//如果哈希表中的索引的值比start小（初始化为0，如果没有录入过肯定比start小）
							  //存放这个字符出现位置的下一个位置，即重复字符出现后的新start位置
	}

	tmpmax = i - start;

	return (tmpmax > max ? tmpmax : max);

}

#else

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

#endif