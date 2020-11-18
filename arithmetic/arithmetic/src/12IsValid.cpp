#include "../include/12IsValid.h"

bool IsValid(string s)
{
	stack<char> stack;//创建一个栈
	
	if (s.size() % 2 != 0)//如果栈的值不是2的倍数，直接返回false
		return false;

	if (s == "")//如果是空字符串，返回true
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

		else if (s[i] == '[')//前三个if，是左符号的话，就在压栈对应的有符号
		{
			stack.push(']');
		}

		else if (!stack.empty())//不为空
		{
			if (s[i] == stack.top())//如果当前字符和栈顶元素相同，就出栈
			{
				stack.pop();
			}
			else
			{
				return false;//不然就是错误的，false
			}
		}

		else if (stack.empty())//如果字符串还没结束，栈已经空了，说明左右个数不对称，false
		{
			return false;
		}
	}

	return stack.empty();//string结束，如果stack没结束，false；反之true
}