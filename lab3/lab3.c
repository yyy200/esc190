#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab3.h"


int add_request(struct party_node **head, char *item, double price, char *ta){

    if (!strcmp(item, "IDE")){
        return -1;
    }

    struct party_node* new_node = malloc(sizeof(struct party_node));

    new_node->item = malloc(sizeof(*item)*strlen(item));
    new_node->ta = malloc(sizeof(*ta)*strlen(ta));
    
    strcpy(new_node->item, item);
    new_node->price = price;
    strcpy(new_node->ta, ta);
    new_node->next = *head;
    *head = new_node;
    return 0;

}

void remove_request(struct party_node **head) {
    struct party_node* new_head = (*head)->next;
    free(*head);
    *head = new_head;
};

void make_sorted(struct party_node **head){
    // Go through list, find midpoint
    // if only one node is present -> list is sorted 
    // pass head and mid to make_sorted
    // sort the returned list from recursive call based on price
};

double finalize_list(struct party_node **head , double budget ) {
    // Go through list
    // At each node, 
        // remove node if over budget
        // else minus price from budget

    // return remaining budget
    return budget;
};

void print_ll(struct party_node *head){
    struct party_node* curr = head; 
    while (curr != NULL){
        printf("––––––––––\n");
        printf("%s\n", curr -> item);
        printf("%f\n", curr -> price);
        printf("%s\n", curr -> ta);
        curr = curr -> next;
    } 
    printf("––––––––––\n");

}