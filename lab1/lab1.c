#include "lab1.h"

// Libraries
#include <stdio.h>
#include <math.h>
#include <string.h>

#define _GNU_SOURCE

double split_bill(double base_amount, double tax_rate, double tip_rate, int num_people) {
    // Calculate the total bill seperate from the split bill so it can be used later
    double total = (base_amount * (1 + tax_rate) * (1 + tip_rate));
    double result = total/num_people;

    // floors the result implicilty into an int to see if the amount payed would be
    // discrepant from the total, if so, 1 cent must be added

    result = (int)(result*100);
    result /= 100;

    if (num_people * result < total) result += 0.01;

    return result;
}

double adjust_price(double original_price) {
    return 10 * pow(original_price, 0.5);
}

int sandy_eats(char menu_item[]) {
    // get substring of menu_item after j, otherwise NULL (falsy)
    char* j = strcasestr(menu_item, "j");
    char* k = strcasestr(menu_item, "k");
    char* l = strcasestr(menu_item, "l");
    char* fish = strcasestr(menu_item, "fish");

    int length = strlen(menu_item);

    // check if any is tru then coerse to an int (0, 1)
    return (int) !(j || k || l || fish || length % 2 == 1);
}

void imagine_fish(char * thing) {
    // size of the array divided by the size of 1 character gives its length 
    int length = strlen(thing);
    // Insert one character of fish at every space after the index of length
    char * sptr;
    sptr = &(thing[length]);
    sptr[0] = 'f';
    sptr[1] = 'i';
    sptr[2] = 's';
    sptr[3] = 'h';    
}