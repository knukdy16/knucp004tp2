#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void insert(int e, int a[], int i )
{
        a[0] = e;
        while(e < a[i])
        {
                a[i+1] = a[i];
                i--;
        }
        a[i+1] = e;
}

void insertionSort(int a[], int n)
{
        int j, temp;
        for(j=2;j<=n;j++)
        {
                temp = a[j];
                insert(temp, a, j-1);
        }
}
