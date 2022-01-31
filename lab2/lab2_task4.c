#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int *p = (int *) malloc(sizeof(int));
    printf("Value stored at address %p: %d\n", p, *p);
    *p = 1;
    printf("Value stored at address %p: %d\n", p, *p);
    free(p);
    printf("Value stored at address %p: %d\n", p, *p);
}