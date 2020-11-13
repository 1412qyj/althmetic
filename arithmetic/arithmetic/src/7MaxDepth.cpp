#include "../include/7MaxDepth.h"

int MaxDepth(TreeNode* root)
{
	int maxl = 0;
	int maxr = 0;

	if (root == nullptr)
	{
		return 0;
	}

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

static TreeNode * CreateTree(int *data, int index, int size)
{
	TreeNode *pnode = nullptr;

	if (index < size)
	{
		pnode = (TreeNode *)malloc(sizeof(TreeNode));
		if (nullptr == pnode)
		{
			perror("malloc");
			return NULL;
		}

		pnode->val = data[index];
		pnode->left = CreateTree(data, 2 * index + 1, size);
		pnode->right = CreateTree(data, 2 * index + 2, size);

		return pnode;
	}

	
	return nullptr;
}

