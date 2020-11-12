#include "../include/23RestoreIpAddresses.h"

//模块函数公共处理的数据
static vector<string> ret;

vector<string> RestoreIpAddresses(string s)
{
	string cur = s;
	int size = s.size();

	Handle(size, 0, -1, cur ,s);

	return ret;
}

//分析ip地址字符串函数
void Handle(int size, int pointNum, int lastPointPlace, string &cur, string &ori)
{
	//已经打了三个点了
	if (pointNum == 3)
	{
		//判断最后一个数值是否是正确的
		if (isValid(lastPointPlace + 1, size - 1, ori))
			ret.push_back(cur);//加到公共数据中

		return;
	}

	//寻找打点的位置：上一个点的后面位置到串的末尾前一个位置可以打点
	for (int i = lastPointPlace + 1; i < size-1; i++)
	{
		if (isValid(lastPointPlace + 1, i, ori))
		{
			//在cur中插入.,要加上点的数量
			cur.insert(cur.begin() + i + pointNum + 1, '.');
			Handle(size, pointNum+1, i, cur, ori);

			//回退插入之前
			cur.erase(i + pointNum + 1, 1);
		}
	}

	return;
}

//判断传的数是否符合要求
bool isValid(int firstPlace, int lastPlace, string &s)
{
	int sum = 0;

	for (int i = firstPlace; i <= lastPlace; i++)
	{
		//当其中的非一位数第一位是0时
		if (s[firstPlace] == '0' && firstPlace != lastPlace)
			return false;

		sum = sum * 10 + s[i] - '0';
	}

	if (sum > 255)
		return false;

	return true;
}