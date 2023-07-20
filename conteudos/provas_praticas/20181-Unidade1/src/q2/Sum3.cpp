#include "Sum3.h"

int bSearch(int v[], int left, int right, int key)
{
	if(left > right)
	{
		return -1;
	}

	int mid = (left+right)/2;
	if(key < v[mid])
	{
		return bSearch(v, left, mid-1, key);
	}
	else if(key > v[mid])
	{
		return bSearch(v, mid+1, right, key);
	}
	else
	{
		return mid;
	}
}

bool existsSum3(int v[], int size, int sum)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			int toSearch = sum - v[i] - v[j];
			int index = bSearch(v, 0, size-1, toSearch);
			if(index != -1)
			{
				return true;
			}
		}
	}
	return false;
}
