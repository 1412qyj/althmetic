#ifndef __CPP_BINARY_TREE_PATH_H
#define __CPP_BINARY_TREE_PATH_H

#include "common.h"
#include <sstream>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

vector<string> BinaryTreePaths(TreeNode* root);
TreeNode * CreateTree(int *data, int index, int size);
#endif