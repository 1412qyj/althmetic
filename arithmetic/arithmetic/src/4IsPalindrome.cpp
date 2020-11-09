#include "../include/4IsPalindrome.h"

bool IsPalindrome(int x)
{
	stringstream sstr;
	string str;
	sstr << x;
	bool ret = true;

	sstr >> str;

	string str_back = str;

	if (!strcmp(str.c_str(), str_back.c_str()))
		return true;
	else
		return false;
}