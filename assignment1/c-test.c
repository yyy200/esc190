#include <stdio.h>

#include "a1.h"


int main(void) {
    Restaurant * resto = initialize_restaurant("The cooles retauran");
    print_menu(resto->menu);
  //   char item[] ="2,3,3";
  //   char item2[] ="2,3,3";
  //   char item3[] ="2,3,3";
  //   char item4[] ="2,3,3";
  //   char item5[] ="2,3,3";
  //   char item6[] ="2,3,3";
  //   Order * order5 = build_order("B2B3L1", item);
  //   enqueue_order(order5, resto);
  // Order * order4 = build_order("B2B3L1", item2);
  //   enqueue_order(order4, resto);
  // Order * order3 = build_order("B2B3L1", item3);
  //   enqueue_order(order3, resto);
  // Order * order2 = build_order("B2B3L1", item4);
  //   enqueue_order(order2, resto);
  // Order * order1 = build_order("B2B3L1", item5);
  //   enqueue_order(order1, resto);

  // Order * order6 = dequeue_order(resto);
  // print_order(order6);
  // clear_order(&order6);
  close_restaurant(&resto);
    return 0;
}