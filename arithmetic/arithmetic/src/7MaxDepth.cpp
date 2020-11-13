#include "../include/7MaxDepth.h"

int MaxDepth(TreeNode* root)
{
	int maxl = 0;
	int maxr = 0;


	if (root->left != nullptr)
	{
		maxl = MaxDepth(root->left);
	}

	if (root->right != nullptr)
	{
		maxr = MaxDepth(root->right);
	}

	return (maxl > maxr) ? (maxl+1) : (maxr+1);
}

TreeNode * CreateTree7(int *data, int index, int size)
{
	TreeNode *pnode = nullptr;

	if (index > size || data[index] == -1)
		return nullptr;

	else
	{
		pnode = (TreeNode *)malloc(sizeof(TreeNode));

		pnode->val = data[index];
		pnode->left = CreateTree7(data, 2 * index + 1, size);
		pnode->right = CreateTree7(data, 2 * index + 2, size);
	}

	return pnode;
}

