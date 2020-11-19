#include "../include/5MinDepth.h"

int MinDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int ret = 0;

	if (root->left == nullptr && root->right != nullptr)
	{
		ret = MinDepth(root->right)+1;
	}

	else if (root->right == nullptr && root->left != nullptr)
	{
		ret = MinDepth(root->left)+1;
	}

	else if (root->left != nullptr && root->right != nullptr)
	{
		ret = MIN(MinDepth(root->right), MinDepth(root->left)) + 1;
	}
	else if (root->left == nullptr && root->right == nullptr)
	{
		ret = 1;
	}

	return ret;

}



#ifdef PRINT
void prinTree(TreeNode *p_tree)
{
	if (p_tree != nullptr)
	{
		cout << p_tree->val << endl;

		prinTree(p_tree->left);

		prinTree(p_tree->right);
	}
}

#endif