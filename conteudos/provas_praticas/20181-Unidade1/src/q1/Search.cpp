#include "Search.h"
#include <iostream>

int binSearchRight(int v[], int left, int right, int key)
{
	if(left > right)
	{
		return -1;
	}

	int mid = (left+right)/2;
	if(key < v[mid])
	{
		return binSearchRight(v, left, mid-1, key);
	}
	else if(key > v[mid] || v[mid+1]==key)
	{
		return binSearchRight(v, mid+1, right, key);
	}
	else
	{
		return mid;
	}
}

int findRightmost(int v[], int size, int key)
{
	if(v[size-1]==key)
	{
		return size-1;
	}
	else
	{
		return binSearchRight(v, 0, size-2, key);
	}
}
