#include "NumberUtils.h"

string fromDecToBin(int n)
{
	if(n == 0 || n == 1)
	{
		return std::to_string(n);
	}
	else
	{
		int div = n / 2;
		int mod = n % 2;
		return fromDecToBin(div) + std::to_string(mod);
	}
}