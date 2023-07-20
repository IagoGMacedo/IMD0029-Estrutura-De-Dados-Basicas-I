#include "NumberUtils.h"
#include <cassert>
#include <iostream>

int main(void)
{
	assert( "0" == fromDecToBin(0) );
	assert( "1" == fromDecToBin(1) );
	assert( "10" == fromDecToBin(2) );
	assert( "11" == fromDecToBin(3) );
	assert( "101" == fromDecToBin(5) );
	assert( "10000" == fromDecToBin(16) );
	assert( "11001" == fromDecToBin(25) );
	assert( "11111" == fromDecToBin(31) );
	assert( "100000000" == fromDecToBin(256) );
	assert( "100010001" == fromDecToBin(273) );
	assert( "111111111" == fromDecToBin(511) );

	std::cout << "All tests passed!" << std::endl;

	return 0;
}
