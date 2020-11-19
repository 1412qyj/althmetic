#include "../include/4IsPalindrome.h"

#if 0
bool IsPalindrome(int x)
{
	stringstream sstr;
	string str;
	sstr << x;
	bool ret = true;

	sstr >> str;

	string str_back = str;

	reverse(str_back.begin(), str_back.end());

	if (!strcmp(str.c_str(), str_back.c_str()))
		return true;
	else
		return false;
}
#endif


bool IsPalindrome(int x)
{
	long iback = 0;
	int y = x;

	while (x > 0)
	{
		iback = iback * 10 + x % 10;
		x = x / 10;
	}

	if (y == iback)
	{
		return true;
	}
	else
	{
		return false;
	}
}