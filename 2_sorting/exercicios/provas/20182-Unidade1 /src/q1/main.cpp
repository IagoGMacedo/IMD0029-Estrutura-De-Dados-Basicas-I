#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string revert(string s)
{
	if(s=="")
	{
		return s;
	}
	else
	{
		// s[s.size()-1] == Último caractere
		// s.substr(0, s.size()-1) == Toda a string sem o último caractere
		return s[s.size()-1] + revert(s.substr(0, s.size()-1));
	}
}

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
