#include "../include/12IsValid.h"

bool IsValid(string s)
{
	stack<char> stack;
	
	if (s.size() % 2 != 0)
		return false;

	if (s == "")
		return true;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stack.push(')');
		}

		else if (s[i] == '{')
		{
			stack.push('}');
		}

		else if (s[i] == '[')
		{
			stack.push(']');
		}

		else if (!stack.empty())
		{
			if (s[i] == stack.top())
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}

		else if (stack.empty())
		{
			return false;
		}
	}

	return stack.empty();
}