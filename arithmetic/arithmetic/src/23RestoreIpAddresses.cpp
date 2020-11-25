#include "../include/23RestoreIpAddresses.h"

vector<string> res;//最后返回的字符串，找到一个适合的数字就插入
vector<string> RestoreIpAddresses(string s) 
{
	string cur = s;
	int size = s.size();

	Handle(size, 0, -1, cur, s);

	return res;
}
void Handle(int n, int pointNum, int lastPoint, string& cur, string& ori) 
{
	if (pointNum == 3)
	{
		//判断最后一个数值是否是正确的
		if (Isvalid(lastPoint + 1, n - 1, ori))
			res.push_back(cur);//加到公共数据中

		return;
	}
	for (int i = lastPoint + 1; i < n - 1; i++)
	{
		if (Isvalid(lastPoint + 1, i, ori))
		{
			//在cur中插入.,要加上点的数量
			cur.insert(cur.begin() + i + pointNum + 1, '.');
			Handle(n, pointNum + 1, i, cur, ori);

			//回退插入之前
			cur.erase(i + pointNum + 1, 1);
		}
	}
	return;
}
bool Isvalid(int firstPlace, int lastPlace, string &s)
{
	int sum = 0;

	for (int i = firstPlace; i <= lastPlace; i++)
	{
		//当其中的非一位数第一位是0时
		if (s[firstPlace] == '0' && firstPlace != lastPlace)
			return false;

		sum = sum * 10 + s[i] - '0';

		if (sum > 255)
			return false;
	}



	return true;
}