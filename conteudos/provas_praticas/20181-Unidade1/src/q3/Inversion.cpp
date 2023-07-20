#include "Inversion.h"

int countInversions(int v[], int size)
{
	int count = 0;
	for(int i = 0; i < size; ++i)
	{
		for(int j = i+1; j < size; ++j)
		{
			if( i < j && v[i] > v[j])
			{
				++count;
			}
		}
	}
	return count;
}
