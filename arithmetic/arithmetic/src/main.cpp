#include "../include/5MinDepth.h"


int main()
{
	//print Author and Language
	printf("%s\n", GetAuthor());
	printf("%s\n", GetLanguage());

	int nums[11] = {1, 2, 3, -1 ,4, 5, -1, -1, -1, -1, -1};

	TreeNode *p_tree = CreateTree(nums, 0, 11);

#ifdef PRINT
	prinTree(p_tree);
#endif
	cout << MinDepth(p_tree) << endl;

	system("pause");
	return 0;
}