#ifndef __CONTAIN_NEARBY_DUPLICATE_H
#define __CONTAIN_NEARBY_DUPLICATE_H
#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b)) 

#ifdef __cplusplus
extern "C" {
#endif
	bool ContainsNearbyDuplicate(int* nums, int numsSize, int k);

#ifdef __cplusplus
}
#endif

#endif