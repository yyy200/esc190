#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int** p;

    int x = 10;
    int y = 11;
    int z = 12;

    int* ptr = (int *) malloc(sizeof(int) * 3);
    *ptr = x;
    *(ptr + 1) = y;
    *(ptr + 2) = z;

    p = &ptr;

    free(ptr);
}