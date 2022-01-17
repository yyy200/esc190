#include <stdio.h>
#include "lab1.h"

int main(void) {
    double test_p1 = split_bill(1.00, 0.30, 0.10, 8);
    printf("The split will be: $%.2f.\n", test_p1);


    double test_p2 = adjust_price (25.00);
    printf("The adjusted price is: $%.2f.\n", test_p2 );

    char test_food[] = "Three cheese pizza";
    int test_p3 = sandy_eats(test_food);
    if (test_p3 == 0) {
        printf("Sandy would NOT eat ‘%s’.\n", test_food );
    }
    else {
        printf("Sandy would eat ‘%s’.\n", test_food );
    }

    char test_p4 [30] = "llamADoG";
    imagine_fish(test_p4 );
    printf("Just imagine, a %s!\n", test_p4 );
}