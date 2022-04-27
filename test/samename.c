#include<stdlib.h>

struct Node { int value; struct Node * next; };

void destroy(struct Node * first) {
    struct Node * prev = NULL;
    struct Node * curr = first;
    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}

int main(void) {
    // create a linked list with values 1 to 20
    struct Node *first = NULL;
    struct Node *last = NULL;
    int i;
    for(i = 1; i <= 20; i++) {
        struct Node *new = malloc(sizeof(struct Node));
        new->value = i;
        new->next = NULL;
        if(first == NULL)
            first = new;
        else
            last->next = new;
        last = new;
    }

    destroy(first);
}