#include <iostream>
#include <Windows.h>
#include "../include/9AddBinary.h"
using namespace std;

int main()
{
	cout <<  AddBinary("110", "111") << endl;

	string s1("110");
	string s2("111");


	cout << s1.at(2) + s2.at(2) << endl;

	system("pause");
	return 0;
}