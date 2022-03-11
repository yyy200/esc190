#include <stdio.h>

#include "a1.h"


int main(void) {
    Restaurant * resto = initialize_restaurant("Tritan's Bistro");
    close_restaurant(&resto);
    return 0;
}