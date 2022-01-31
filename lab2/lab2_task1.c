#include<stdio.h>
#include<stdlib.h>

int main(void){
    int x = 0;
    int* ptr = &x;
    printf("x contains the value %d at location %p\n", *ptr , ptr);
}