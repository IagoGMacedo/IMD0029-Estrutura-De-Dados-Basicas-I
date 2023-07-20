#include "Search.h"
#include <cassert>
#include <iostream>

int main(void)
{
	int v1[] = {0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
	assert( 6 == bitonicSearch(v1, sizeof(v1)/sizeof(int), 9) );

	int v2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 100, 90};
	assert( 7 == bitonicSearch(v2, sizeof(v2)/sizeof(int), 17) );

	int v3[] = {10, 11, 12, 90, 80, 70, 60, 50, 4, 3, 2};
	assert( 1 == bitonicSearch(v3, sizeof(v3)/sizeof(int), 11) );

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
