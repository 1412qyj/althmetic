#include "../include/13MyAtoi.h"

//bool FirstIsSub(const char ch)
//{
//	if (ch == '-')
//		return true;
//	else
//		return false;
//}
//
//bool IsNum(const char ch)
//{
//	if (ch >= 'a' && ch <= 'z' || ch >= 'A' || ch <= 'Z')
//		return true;
//	else
//		return false;
//}

int MyAtoi(string s)
{
	stringstream sstr(s);
	float ret = 0.0f;

	if (sstr >> ret)
	{
		if (ret >= INT_MAX)
		{
			return INT_MAX;
		}

		if (ret <= INT_MIN)
		{
			return INT_MIN;
		}

		return static_cast<int>(ret);
	}
	else
	{
		return 0;
	}


	//int flag = 1;
	//stringstream sstr(s);
	//float ret = 0.0f;

	////字符串为空，返回0
	//if (s.empty())
	//{
	//	return 0;
	//}

	////字符串第一个是负号，设置符号位
	//if (FirstIsSub(s[0]))
	//{
	//	flag = -1;
	//}
	//else
	//{
	//	//是数字
	//	if (IsNum(s[0]))
	//	{
	//		sstr >> ret;

	//		if (ret > )
	//	}
	//	else //不是数字
	//	{
	//		return 0;
	//	}
	//}

	
}