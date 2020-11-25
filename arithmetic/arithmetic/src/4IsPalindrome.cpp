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
	int iback = 0;

	if (x < 0 || (!(x % 10) && x != 0))
	{
		return false;
	}

	while (x > iback)
	{
		iback = iback * 10 + x % 10;
		x = x / 10;
	}

	if (x == iback || iback / 10 == x)
	{
		return true;
	}
	else
	{
		return false;
	}
}