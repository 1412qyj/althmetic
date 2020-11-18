#include "../include/9AddBinary.h"

#if 1
string AddBinary(string a, string b)
{
	if (a.size() < b.size())
		a.insert(0, b.size() - a.size(), '0');
	else
		b.insert(0, a.size() - b.size(), '0');

	bool carry = false;

	for (int i = a.size() - 1; i >= 0; i--)
	{
		a[i] = a[i] + b[i] + carry - '0';

		if (a[i] > '1')
		{
			a[i] -= 2;
			carry = true;
		}
		else
		{
			carry = false;
		}
	}
	
	if (carry)
	{
		a.insert(0, 1, '1');
	}

	return a;
}
#else

string AddBinary(string a, string b)
{
	bool carry = false;
	int tmp = 0;

	if (a.size() - b.size() > 0)
	{
		b.insert(0, a.size() - b.size(), '0');
	}
	else if (a.size() - b.size() < 0)
	{
		a.insert(0, b.size() - a.size(), '0');
	}

	for (int i = a.size() - 1; i >= 0; i--)
	{
		tmp = a[i]+ b[i] + carry - '0' - '0';

		//判断tmp有没有溢出
		if (tmp > 1)
		{
			carry = true;
			tmp -= 2;
		}
		else
		{
			carry = false;
		}

		a.replace(i, 1, 1, tmp+'0');

	}

	if (carry)
	{
		a.insert(0, 1, '1');
	}

	return a;

}

#endif