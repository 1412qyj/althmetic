#include "../include/18PlusOne.h"


#if 1

vector<int> PlusOne(vector<int> &digits)
{
	if (digits.back() != 9)
	{
		digits[digits.size() - 1] += 1;

		return digits;
	}

	else
		digits[digits.size() - 1] = 0;

	for (int i = digits.size() - 2; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i] += 1;

			return digits;
		}

		else
		{
			digits[i] = 0;
		}
	}

	if (digits.front() == 0)
		digits.insert(digits.begin(), 1, 1);

	return digits;
}

#else
vector<int> PlusOne(vector<int>& digits)
{
	bool carry = false;
	
	digits[digits.size() - 1] += 1;

	if (digits[digits.size() - 1] > 9)
	{
		digits[digits.size() - 1] -= 10;
		carry = true;
	}

	for (int i = digits.size() - 2; i >= 0; i--)
	{
		if (carry == false)
			break;

		digits[i] += carry;

		if (digits[i] > 9)
		{
			digits[i] -= 10;
			carry = true;
		}
		else
		{
			carry = false;
		}
	}

	if (carry)
	{
		digits.insert(digits.begin(), 1);
	}

	return digits;
}

#endif