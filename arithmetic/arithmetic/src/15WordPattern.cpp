#include "../include/15WordPattern.h"

#if 0
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
#else
bool WordPattern(string pattern, string s)
{
	unordered_map<char, string> map;
	unordered_map<string, char> rmap;//出现一个pattern对应多个单词时会出现错误，反向定义一个map
									 //保证pattern和单词做到一一对应
	stringstream sstr(s);
	string str;

	for (char c : pattern)
	{
		//两种返回false的情况
		//sstr >> s 如果等于0，说明pattern的个数和s的元素个数不一致，返回false
		//如果map中有c这个键且c键的值不是s，返回false
		if (!(sstr >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c) )
			return false;

		//在map中添加键值
		map[c] = s;
		rmap[s] = c;
	}
	
	//到这里pattern遍历结束，再验证是否s也为空
	return (sstr >> str) ? false : true;
}


#endif