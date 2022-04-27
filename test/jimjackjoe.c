#include<stdio.h>

int main(void) {
    char * names[] = { "jim", "jack", "joe"};
    for(int i = 0; i < 3; i++) {
        printf(" %s", names[i], names[i]);
    }
}