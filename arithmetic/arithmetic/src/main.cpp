#include <iostream>
#include "../include/3IsUgly.h"
using namespace std;
int main()
{
	//print Author and Language
	printf("%s\n", GetAuthor());
	printf("%s\n", GetLanguage());

	cout << IsUgly(6) << endl;

	system("pause");
	return 0;
}