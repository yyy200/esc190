#include"lab3.h"
#include<stdio.h>
#include<stdlib.h>


int main(void){
    struct party_node ** head = malloc(sizeof(struct party_node *));
    // char * ta = malloc(sizeof("Albert"));
    // ta = "Albert";
    char ta[30] = "Albert";
    char base_item[20] = "Soup";

    add_request(head, base_item, 40, ta);
    add_request(head, base_item, 90, ta);
    add_request(head, base_item, 3000, ta);
    add_request(head, base_item, 450, ta);
    add_request(head, base_item, 390, ta);
    add_request(head, base_item, 20, ta);
    add_request(head, base_item, 2, ta);
    add_request(head, base_item, 255, ta);

    print_ll(*head);
    remove_request(head);
    printf("############\n");
    print_ll(*head);
}