#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "sorting.h"
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void quickSort(int a[], int left, int right) {
        int pivot, i, j;
        int temp;
        if(left < right) {
                i = left; j = right + 1;
                pivot = a[left];
                do {
                        do {
                                i++;
                        } while(a[i] < pivot);
                        do {
                                j--;
                        } while (pivot < a[j]);
                        if(i < j)
                                SWAP(a[i], a[j], temp);
                } while (i < j);
                SWAP(a[left], a[j], temp);
                quickSort(a, left, j-1);
                quickSort(a, j+1, right);
        }
}
/*
void main(void) {
        int i;
        int a[MAX_SIZE + 1];
        for(i = 0; i < MAX_SIZE; i++) {
                a[i] = MAX_SIZE - i;
                printf("%d ", a[i]);
        }
        a[MAX_SIZE] = INT_MAX;
        quickSort(a, 0, MAX_SIZE - 1);
        printf("\n Sorted Array:\n");
        for(i = 0; i < MAX_SIZE; i++) {
                printf("%d ", a[i]);
        }
        puts("");
}*/
