#include "../include/common.h"
#include "../include/1ContainsNearbyDuplicate.h"
int main()
{
	//print Author and Language
	printf("%s\n", GetAuthor());
	printf("%s\n", GetLanguage());

	int nums[5] = {1, 2, 3, 0, 1};
	int key = 3;

	printf("%d\n", ContainsNearbyDuplicate(nums, 5, key));
	system("pause");
	return 0;
}