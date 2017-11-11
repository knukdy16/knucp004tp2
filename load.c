#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sorting.h"

int *load_ary(char *av[], int* cn) {
        FILE *in_fd;
        int buf;
        int count_num = 0;
        char *file_dir_temp;
        int *arr;
        int arr_i = 0;

        file_dir_temp = (char *)malloc(sizeof(av[1])+2);
        sprintf(file_dir_temp, "./%s", av[1]);
        // printf("%s\n", temp);

        in_fd = fopen(file_dir_temp, "r");

        if(in_fd == NULL)
                oops("error loading file", "");
/*      else {
                printf("load successful\n");
        }
*/
        while(0 < fscanf(in_fd, "%d", &buf)) {
                // printf("%d   |       %d\n", ++count_num, buf);
                ++count_num;
        }

        // printf("all counted number: %d\n", count_num);

        arr = (int *)malloc(sizeof(int)*count_num);

        fseek(in_fd, 0, SEEK_SET);

        while(0 < fscanf(in_fd, "%d", &buf)) {
                arr[arr_i++] = buf;
        }
        /*
        for(arr_i = 0; arr_i < count_num; arr_i++)
                printf("%d => %d\n", arr_i, arr[arr_i]);
        */
        *cn = count_num;

        if(fclose(in_fd) == -1)
                oops("error closing file", "");

        return arr;
}

int* set_arr2(int* arr1, int size) { // for insertionSort
        int* set_arr;
        int i;
        set_arr = (int *)malloc(sizeof(int)*(size + 1));

        for(i = 1; i <= size; i++) {
                set_arr[i] = arr1[i-1];
        }
/*
        puts("<arr2>");
        for(i = 1; i <= size; i++) {
                printf("%d %d\n", i, set_arr[i]);
        }
*/
/*
        puts("<arr2>");
        for(i = 1; i <= 10; i++) {
                printf("%d %d\n", i, set_arr[i]);
        }

        puts("<arr2>");
        for(i = size-10; i <= size; i++) {
                printf("%d %d\n", i, set_arr[i]);
        }
*/
        return set_arr;
}

int* set_arr3(int* arr1, int size) { // for quickSort
        int *set_arr;
        int i;
        set_arr = (int *)malloc(sizeof(int)*(size + 1));

        for(i = 0; i < size; i++) {
                set_arr[i] = arr1[i];
        }
        set_arr[size] = INT_MAX;
/*
        puts("<arr3>");
        for(i = 0; i <= size; i++) {
                printf("%d %d\n", i, set_arr[i]);
        }
*/
        return set_arr;
}

/*
int main(int ac, char *av[]) {
        int* ary1;
        int cn;
        int i;

        ary1 = load_ary(av, &cn);

        for(i = 0; i < cn; i++) {
                printf("%d %d\n", i, ary1[i]);
        }
}
*/
void oops(char *s1, char *s2) {
        fprintf(stderr, "error:%s", s1);
        perror(s2);
        exit(1);
}
