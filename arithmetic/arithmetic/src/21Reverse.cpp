#include "../include/21Reverse.h"

int Reverse(int x)
{
	stringstream sstr;

	sstr << x;

	string str;

	sstr >> str;
	
	reverse(str.begin(), str.end());

	int ret = atoi(str.c_str());

	return  (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
}