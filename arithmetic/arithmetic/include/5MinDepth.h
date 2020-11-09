#ifndef __CPP_MIN_DEPTH_H
#define __CPP_MIN_DEPTH_H

#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int MinDepth(TreeNode* root);

#endif