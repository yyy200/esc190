#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int *p = (int *) malloc(sizeof(int));
    int *q = (int *) malloc(sizeof(int) * 2);

    *p = 1;
    *q = 10;
    q = p;

    // The error lies in freeing the memory at address p twice as q= p
    // furthermore, the initial memory at address q_1 is never freed
    free(q);

    free(p);
}