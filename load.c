#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void oops(char *s1, char *s2);

int *load_ary(char *av[], int* count) {
        FILE *in_fd;
        int buf;
        int count_num = 0;
        char *file_dir_temp;
        int *arr1;
        int arr1_i = 0;

        file_dir_temp = (char *)malloc(sizeof(av[1])+2);
        sprintf(file_dir_temp, "./%s", av[1]);
        // printf("%s\n", temp);

        in_fd = fopen(file_dir_temp, "r");

        if(in_fd == NULL)
                oops("error loading file", "");
        else {
                printf("load successful\n");
        }

        while(0 < fscanf(in_fd, "%d", &buf)) {
                // printf("%d   |       %d\n", ++count_num, buf);
                ++count_num;
        }

        printf("all counted number: %d\n", count_num);

        arr1 = (int *)malloc(sizeof(int)*count_num);

        fseek(in_fd, 0, SEEK_SET);

        while(0 < fscanf(in_fd, "%d", &buf)) {
                arr1[arr1_i++] = buf;
        }

        if(fclose(in_fd) == -1)
                oops("error closing file", "");

        *count = count_num;

        return arr1;
}

int main(int ac, char *av[]) {
        int i;
        int size = 0;
        int* arr1 = NULL;
        arr1 = load_ary(av, &size);
        for(i = 0; i < size; i++)
                printf("%d => %d\n", i, arr1[i]);
}

void oops(char *s1, char *s2) {
        fprintf(stderr, "error:%s", s1);
        perror(s2);
        exit(1);
}
