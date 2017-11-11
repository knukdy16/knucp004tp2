#include <stdio.h>
#include <stdlib.h>

void insert(int e, int a[], int i ) {
        a[0] = e;
        while(e < a[i]) {
                a[i+1] = a[i];
                i--;
        }
        a[i+1] = e;
}

void insertionSort(int a[], int n) {
        int j, temp;
        for(j=2;j<=n-1;j++) {
                temp = a[j];
                insert(temp, a, j-1);
        }
}
/*
int main() {
        int i;
        int a[100 + 1];
        for(i = 1; i < 101; i++) {
                a[i] = 100 + 1 - i;
                printf("%d ", a[i]);
        }

        insertionSort(a, 100 + 1);
        printf("\n Sorted Array:\n ");
        for(i = 1; i < 100 + 1; i++) {
                printf("%d ", a[i]);
        }
        puts("");
}*/
