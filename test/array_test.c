#include<stdio.h>
#include<stdlib.h>

int * insert(int * arr, int * n, int val) {
    arr  = realloc(arr, sizeof(int) * (*n + 1));
    arr[*n] = val;
    *n += 1;
    return arr;
}

void print_arr(int * arr, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 4;
    int * arr = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    print_arr(arr, n);
    arr = insert(arr, &n, 6);
    print_arr(arr, n);
}