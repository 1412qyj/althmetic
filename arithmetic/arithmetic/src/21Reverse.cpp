#include "../include/21Reverse.h"

#if 1
int Reverse(int x)
{
	long sum = 0;

	while (x != 0) {
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	
	
	if (sum >= INT_MAX || sum <= INT_MIN)
		sum = 0;
	
	
	return sum;
}


#else
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

#endif