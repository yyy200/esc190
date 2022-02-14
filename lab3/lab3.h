#include<stdio.h>
#include<stdlib.h>

struct party_node {
    char* item; // name of the party item
    double price; // price of the item
    char* ta; // name of TA requesting the item
    struct party_node *next; // pointer to the next node
};

int add_request(struct party_node **head, char *item, double price, char *ta);

void remove_request(struct party_node **head);

void make_sorted(struct party_node **head);

double finalize_list(struct party_node **head , double budget );

void print_ll(struct party_node *head);