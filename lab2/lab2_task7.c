#include<stdio.h>
#include<stdlib.h>

void append(int** x, int* n, int val){
    (*n) ++;
    *x = realloc(*x, *n);
    (*x)[*n - 1] = val;

/**
<*x> refers to a dynamically allocated integer array
of size <*n> * sizeof(int).
Modifies <*x> such that it has val added to the end.
The modified array should be of length <*n> + 1.
Modifies <*n> such that it is updated to be the value
of the new length of the array <*x>.
HINT: you may find the function realloc (...) helpful
*/
}
