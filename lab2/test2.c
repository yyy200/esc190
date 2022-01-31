#include<stdio.h>
#include<stdlib.h>

#include"lab2_task7.h"


int main(void) {
    int n = 2;
    int *x = malloc(sizeof(int) * n);    
    
    for(int i = 0; i < n; i++) {
        x[i] = i*2;
    }

    append(&x, &n, 3);

    for(int i = 0; i < n; i ++) {
        printf("%d\n", x[i]);
    }
}