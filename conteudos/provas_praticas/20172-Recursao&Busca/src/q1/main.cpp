#include <cassert>
#include <iostream>
int main(void)
{
	assert( "" == revert("") );
	assert( "A" == revert("A") );
	assert( "AB" == revert("BA") );
	assert( "ABCDEfgh" == revert("hgfEDCBA") );
	assert( "EDB" == revert("BDE") );
	assert( "ARARA" == revert("ARARA") );
	assert( revert(revert("lkjhg")) == "lkjhg");
	std::cout << "All tests passed!" << std::endl;
	return 0;
}