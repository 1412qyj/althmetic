#include "../include/15WordPattern.h"

bool WordPattern(string pattern, string s)
{
	//先判断个数
	int pos = 0;
	int count = 0;

	while (pos < s.size())
	{
		pos = s.find(' ', pos);
		if (pos == -1)
			break;

		pos++;
		count++;
	}

	//如果字符串个数和给定形式的个数不同直接返回false
	if (++count != pattern.size())
		return false;

	//拆解s
	stringstream sstr_s(s);
	string str_tmp;
	vector<string> vec_s;

	while (sstr_s >> str_tmp)
	{
		vec_s.push_back(str_tmp);
		str_tmp.clear();
	}

	//找到a，b的模板
	string str_temple_a = vec_s[pattern.find('a')];
	string str_temple_b = vec_s[pattern.find('b')];

	pos = 0;
	//分析pattern
	while (pos < count)
	{
		//如果是a类
		if (pattern[pos] == 'a')
		{
			//和a模板比较
			if (str_temple_a != vec_s[pos])
				return false;
		}

		if (pattern[pos] == 'b')
		{
			//和b模板比较
			if (str_temple_b != vec_s[pos])
				return false;
		}

		pos++;
	}

	return true;
}