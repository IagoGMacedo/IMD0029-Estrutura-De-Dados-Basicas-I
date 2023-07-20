#include "Sort.h"
#include <iostream>

inline void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

inline int medianOfThree(int v[], int left, int right)
{
    int mid = (left + right)/2;

    if( v[right] < v[left] )
    {
        swap(v[left], v[right]);        
    }
    if( v[mid] < v[left] )
    {
        swap(v[mid], v[left]);
    }
    if( v[right] < v[mid] )
    {
        swap(v[right], v[mid]);
    }
    return mid;
}

void qSort(int v[], int left, int right)
{
	if(left < right)
	{
		// BEGIN: Partition		
		int median = medianOfThree(v, left, right);
		swap(v[right], v[median]);
		int pivo = v[right];

		int i = left, j = right-1;
		while(i <= j)
		{
			while(v[i] < pivo && i <= j)
			{
				++i;
			}
			while(v[j] > pivo && i <= j)
			{
				--j;
			}
			if(i <= j)
			{
				swap(v[i], v[j]);
				++i;
				--j;
			}
		}
		swap(v[i], v[right]);
		// END: Partition

		qSort(v, left, i-1);
		qSort(v, i+1, right);
	}
}

void sort(int v[], int size)
{
	qSort(v, 0, size-1);
}
