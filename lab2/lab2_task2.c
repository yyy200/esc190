#include<stdio.h>
#include<stdlib.h>

int main(void){
    int x = 0;
    int y = x;
    int* ptr_x = &x;
    int* ptr_y = &y;
    int** pptr_x = &ptr_x;
    int** pptr_y = &ptr_y;
    printf("x contains the value %d at location %p\n", *ptr_x, ptr_x);
    printf("y contains the value %d at location %p\n", *ptr_y, ptr_y);
}