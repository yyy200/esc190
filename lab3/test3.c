#include"lab3.h"
#include<stdio.h>
#include<stdlib.h>


int main(void){
    struct party_node ** head = malloc(sizeof(struct party_node *));
    // char * ta = malloc(sizeof("Albert"));
    // ta = "Albert";
    char ta[30] = "Albert";
    char base_item[20] = "Soup";

    for(int i = 0; i < 10; i++){

        add_request(head, base_item, i*10.3,ta);
    }

<<<<<<< HEAD
<<<<<<< HEAD
    print_ll(*head);
    printf("########\n");
    make_sorted(head);
=======
>>>>>>> parent of e7225bb (I am the best coder in the world no one is above me this is a long commit messagge . OMG i am so amazing?)
    print_ll(*head);
    remove_request(head);
    printf("############\n");
    print_ll(*head);
=======
    print_ll(*head);
    remove_request(head);
    printf("############\n");
    print_ll(*head);
>>>>>>> parent of e7225bb (I am the best coder in the world no one is above me this is a long commit messagge . OMG i am so amazing?)
}