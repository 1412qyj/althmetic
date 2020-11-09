#include "../include/common.h"
#include "../include/7MaxDepth.h"
#include <iostream>
using namespace std;

int main()
{
	//print Author and Language
	printf("%s\n", GetAuthor());
	printf("%s\n", GetLanguage());

	int nums[7] = {3, 9, 20, -1, -1, 15, 7};
	TreeNode *p_tree = CreateTree(nums, 0, 7);

	printTree(p_tree);

	system("pause");
	return 0;
}