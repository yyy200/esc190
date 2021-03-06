#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab3.h"


int add_request(struct party_node **head, char *item, double price, char *ta){

    if (!strcmp(item, "IDE")){
        return -1;
    }

    struct party_node* new_node = malloc(sizeof(struct party_node));

    // Allocating extra for null character
    new_node->item = malloc(sizeof(*item)*strlen(item) + 1);
    new_node->ta = malloc(sizeof(*ta)*strlen(ta) + 1);
    
    strcpy(new_node->item, item);
    new_node->price = price;
    strcpy(new_node->ta, ta);
    new_node->next = *head;
    *head = new_node;
    return 0;
}

void remove_request(struct party_node **head) {
    if (*head == NULL) return;

    struct party_node* temp = *head;
    *head = (*head)->next;
    
    free(temp->ta);
    free(temp->item);
    free(temp);
    
};

void sort(struct party_node **head){
    // Go through list, find midpoint
    struct party_node * mid = *head;
    // struct party_node * after_mid = *head; 
    struct party_node * end = *head;

    // print_ll(*head);

    int length = 0;

    while(end->next != NULL) {
        end = end->next;
        length ++;
        if (length % 2 == 0)  {
            mid = mid->next;
        }
    }
    length ++; 

    if(length  == 1) {
        return;
    }
    struct party_node * aftermid = mid->next;

    sort(&aftermid);
    mid->next = NULL;
    sort(head);

    struct party_node * cursor_1 =  *head;
    struct party_node * cursor_2 = aftermid;

    struct party_node * main_cursor = NULL; 
    struct party_node * new_head = NULL; 

    // printf("#### CURSOR 1 ####\n");
    // print_ll(cursor_1);
    // printf("#### CURSOR 2 ####\n");
    // print_ll(cursor_2);
    //  printf("#### MAIN CURSOR ####\n");
    // print_ll(main_cursor);

    if(cursor_1->price > cursor_2->price){
        main_cursor = cursor_1;
        cursor_1 = cursor_1->next;  
    }
    else {
        main_cursor = cursor_2;
        cursor_2 = cursor_2->next;
    }
    
    main_cursor->next = NULL;
    new_head = main_cursor;

    while(cursor_1 != NULL && cursor_2 != NULL ) {
        if(cursor_1->price > cursor_2->price){
            main_cursor->next = cursor_1;
            cursor_1 = cursor_1->next;
            main_cursor = main_cursor->next;
        }
        else {
            main_cursor->next = cursor_2;
            cursor_2 = cursor_2->next;
            main_cursor = main_cursor->next;
        }

        main_cursor->next = NULL;
    }

    // printf("#### MAIN CURSOR v1 ####\n");
    // print_ll(main_cursor);


    if(cursor_1 != NULL) {
        // printf("#### CURSOR 1 v2 ####\n");
        // print_ll(cursor_1);
        main_cursor->next = cursor_1;
    }
    else if (cursor_2 != NULL) {
        // printf("#### CURSOR 2 v2 ####\n");
        // print_ll(cursor_2);
        main_cursor->next = cursor_2;
    }


    // printf("#### MAIN CURSOR v2 ####\n");
    // print_ll(main_cursor);

    *head = new_head;
}

void make_sorted(struct party_node **head){
    sort(head);
};

double finalize_list(struct party_node **head , double budget ) {
    struct party_node * curr = *head;
    struct party_node * prev = NULL;

    while(curr != NULL) {
        if (curr->price > budget){  
            remove_request(&curr);
            if(prev) prev->next = curr;
            else *head = curr;
        }
        else {
            budget -= curr->price;
            prev = curr;
            curr = curr->next;
        }
    }

    return budget;
};

void print_ll(struct party_node *head){
    struct party_node* curr = head; 
    printf("??????????????????????????????\n\nhead\t->\t%p\n\n", head);

    while (curr != NULL){
        printf("??????????????????????????????\n");
        printf("%s\n", curr -> item);
        printf("%f\t->\t%p\n", curr -> price, curr->next);
        printf("%s\n", curr -> ta);
        curr = curr -> next;
    } 
    printf("??????????????????????????????\n");

}