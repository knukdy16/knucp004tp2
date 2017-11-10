#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <limits.h>
#include "sorting.h"

void main()
{
        int sizeA = 0, sizeB = 0, i = 1;
        int a[MAX_SIZE] = {0}, b[MAX_SIZE] = {0};
        struct timeval t1, t2;

        readfile(a, &sizeA);
        readfile(b, &sizeB);
        b[sizeB+1] = INT_MAX;

        gettimeofday(&t1, NULL);
        insertionSort(a, sizeA);
        gettimeofday(&t2, NULL);

        printf("\n");
        printf("%.0lf milliseconds\n", (t2.tv_sec*1000 + t2.tv_usec*0.001) - (t1.tv_sec*1000 + t1.tv_usec*0.001));

        gettimeofday(&t1, NULL);
        printf("before quicksort\n");
        quickSort(a, 1, sizeB);
        printf("after quicksort\n");
        gettimeofday(&t2, NULL);
        printf("%.01f milliseconds\n", (t2.tv_sec*100 + t2.tv_usec*0.001) - (t1.tv_sec*1000 + t1.tv_usec*0.001));

}
