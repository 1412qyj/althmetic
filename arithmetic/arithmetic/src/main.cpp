#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/15WordPattern.h"
#endif

using namespace std;

int main()
{

#ifdef DEBUG
	string pattern("aba");
	string str("1 2 2");

	cout << WordPattern(pattern, str) << endl;
#endif

	system("pause");
	return 0;
}