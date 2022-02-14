#include"lab3.h"
#include<stdio.h>
#include<stdlib.h>


int main(void){
    struct party_node ** head = malloc(sizeof(struct party_node *));
    // char * ta = malloc(sizeof("Albert"));
    // ta = "Albert";
    char ta[30] = "Albert";
    char base_item[20] = "Soup";

    
    add_request(head, base_item, 20, ta);
    add_request(head, base_item, 15, ta);
    add_request(head, base_item, 230, ta);
    add_request(head, base_item, 12, ta);
    add_request(head, base_item, 5, ta);


    print_ll(*head);
    printf("########\n");
    make_sorted(head);
    print_ll(*head);
   

}