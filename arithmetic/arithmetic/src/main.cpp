#include <iostream>
#include <Windows.h>
#include <sstream>
using namespace std;

int main()
{
	int i = 1;

	stringstream sstr;

	sstr << i;

	string s1 = "";

	s1 += sstr.str();
	
	

	cout << s1 << endl;

	system("pause");
	return 0;
}