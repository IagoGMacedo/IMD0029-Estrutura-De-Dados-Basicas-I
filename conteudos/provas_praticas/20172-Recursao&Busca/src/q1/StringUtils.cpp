#include "StringUtils.h"

string aux(string s, string &result, int i, int size)
{
	if( i == size )
	{
		return result;
	}
	else
	{
		
		return aux(s, result, i+1, size) + s[i];
	}
}

string revert(string s)
{
	string auxs = "";
	return aux(s, auxs, 0, s.size());
}