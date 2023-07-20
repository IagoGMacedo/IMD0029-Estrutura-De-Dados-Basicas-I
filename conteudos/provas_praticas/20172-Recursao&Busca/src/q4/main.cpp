#include "SomaUtils.h"
#include <cassert>
#include <iostream>

int main(void)
{
	int v1[] = {0, 4, 7, 9, 10, 13, 20, 27};
	// Existe: 14 == 0 + 4 + 10 |--> true
	assert( soma3(v1, sizeof(v1)/sizeof(int), 14) );
	// Não existe:
	assert( !soma3(v1, sizeof(v1)/sizeof(int), 300) );

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
