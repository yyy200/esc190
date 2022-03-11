#include <stdio.h>

#include "a1.h"


int main(void) {
    Restaurant * resto = initialize_restaurant("Tritan's frozen delights");
    print_menu(resto->menu);
    print_menu(resto->menu);
    char order_quantities[] = "32,34,2";
    char od[] = "12,13";

    Order * order = build_order("B1L1B2", order_quantities);
    Order* order_1 = build_order("B1B3", od);

    enqueue_order(order, resto);
    enqueue_order(order_1, resto);
    Order * my_order = dequeue_order(resto);
    print_order(my_order);
   

    printf("%.2f\n", get_order_total(my_order, resto->menu));
    print_receipt(my_order, resto->menu);

  printf("%lu", sizeof(resto->menu));
 clear_order(&my_order);

    close_restaurant(&resto);
    return 0;
}