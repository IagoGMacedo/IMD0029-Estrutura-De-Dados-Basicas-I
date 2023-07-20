#include "Sort.h"
#include <iostream>

void merge(int v[], int left, int mid, int right)
{
	int init1 = left, init2 = mid+1;

	int size = right-left+1;
	int* aux = new int[size];

	int k = 0;
	while(init1 <= mid && init2 <= right)
	{
		if(v[init1] <= v[init2])
		{
			aux[k] = init1;
			++init1;
		}
		else
		{
			aux[k] = init2;
			++init2;
		}
		++k;
	}

	while(init1 <= mid)
	{
		aux[k] = init1;
		++init1;
		++k;
	}

	while(init2 <= right)
	{
		aux[k] = init2;
		++init2;
		++k;
	}

	k = 0;

	for(int i = left; i <= right; ++i)
	{
		v[i] = aux[k];
		++k;
	}
}

void mergesort(int v[], int left, int right)
{
	if( left < right )
	{
		int mid = left + (right-left)/2;
		mergesort(v, left, mid);
		mergesort(v, mid+1, right);
		merge(v, left, mid, right);
	}
}

void sort(int v[], int size)
{
	mergesort(v, 0, size-1);
}
