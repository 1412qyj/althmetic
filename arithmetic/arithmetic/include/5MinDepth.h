#ifndef __CPP_MIN_DEPTH_H
#define __CPP_MIN_DEPTH_H

#include "common.h"
//#define PRINT

#define MIN(a, b) ((a) < (b) ? (a) : (b))



int MinDepth(TreeNode* root);


#ifdef PRINT
void prinTree(TreeNode *p_tree);
#endif

#endif