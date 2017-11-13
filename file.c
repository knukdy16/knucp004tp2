#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void readfile(int a[], int* size)
{
        FILE *fp;
        char fname[20] = "input.txt";
        int i = 1;

        if((fp = fopen(fname, "r")) == NULL)
        {
                fprintf(stderr, "File is not open\n");
                exit(1);
        }

        while(!feof(fp))
        {
                fscanf(fp, "%d", &a[i++]);
                (*size)++;
        }
        (*size)--;

        fclose(fp);
}

void writefile(int a[], int size, char fname[])
{
        FILE *out_fd;
        int i = 1;

        if((out_fd = fopen(fname, "w")) == NULL)
        {
                fprintf(stderr, "File is not open\n");
                exit(1);
        }

        for(i=1;i<=size;i++)
                fprintf(out_fd, "%d ", a[i]);

        fclose(out_fd);
}
