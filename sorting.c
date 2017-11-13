#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include "sorting.h"

void main(int argc, char* argv[]) {
        int size = 0; // store array size
        int *ary_size = &size; // pointer to save array size
                               // from load_ary
        int *arr1, *arr2, *arr3; // arr1 saves original.
                                 // arr2 saves insertion.
                                 // arr3 saves quick.
        int i;
        struct timeval t1, t2;

        arr1 = load_ary(argv, ary_size);
/*
        puts("loaded <arr1>");
        for(i = 0; i < size; i++) {
                printf("%d %d\n", i, arr1[i]);
        }
*/
        arr2 = set_arr2(arr1, size);
        arr3 = set_arr3(arr1, size);

        gettimeofday(&t1, NULL);
        insertionSort(arr2, size + 1);
        gettimeofday(&t2, NULL);
        printf("%0.lf miliseconds\n", (t2.tv_sec*1000 + t2.tv_usec*0.001) - (t1.tv_sec*1000 + t1.tv_usec*0.001));

        writefile(arr2, size, "insertion.txt");
       
        gettimeofday(&t1, NULL);
        quickSort(arr3, 0, size - 1);
        gettimeofday(&t2, NULL);
        printf("%0.lf miliseconds\n", (t2.tv_sec*1000 + t2.tv_usec*0.001) - (t1.tv_sec*1000 + t1.tv_usec*0.001));
        
        writefile(arr3, size, "quick.txt");
}
