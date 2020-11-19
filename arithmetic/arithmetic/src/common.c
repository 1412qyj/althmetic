#include "../include/common.h"


char *GetAuthor()
{
	return "qinyujia";
}

char * GetLanguage()
{
	return "CPP";
}

TreeNode * CreateTree(int *data, int index, int size)
{
	TreeNode *pnode = nullptr;

	if (index >= size || data[index] == -1)
		return nullptr;

	else
	{
		pnode = (TreeNode *)malloc(sizeof(TreeNode));

		pnode->val = data[index];
		pnode->left = CreateTree(data, 2 * index + 1, size);
		pnode->right = CreateTree(data, 2 * index + 2, size);
	}

	return pnode;
}
