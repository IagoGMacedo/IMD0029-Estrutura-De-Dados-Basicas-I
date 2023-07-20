#include "SomaUtils.h"

int binarySearch(int a[], int size, int key)
{
	int beg = 0, end = size-1;
	
	while( beg <= end )
	{
		int med = (beg+end)/2;
		if(key < a[med])
		{
			end = med-1;
		}
		else if( key > a[med] )
		{
			beg = med+1;
		}
		else
		{
			return med;
		}
	}

	return -1;
}

bool soma3(int a[], int size, int s)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			int result = binarySearch(a, size, s - (a[i] + a[j]) );
			if( result != -1 )
			{
				return true;
			}
		}
	}
	return false;
}