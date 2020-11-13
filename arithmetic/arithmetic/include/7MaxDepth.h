#ifndef __CPP_MAX_DEPTH_H
#define __CPP_MAX_DEPTH_H

#include "common.h"



struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

	int MaxDepth(TreeNode*);
	TreeNode * CreateTree7(int *data, int index, int size);




#endif