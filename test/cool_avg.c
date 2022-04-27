#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

float averageLinkedList(struct Node * L, int * n) {
    if(L->next == NULL) {
        return (float)L->data;
    }
    
    Node *  temp = L;
    int size = 0;
    while(temp != NULL) {
        size ++;
        temp = temp->next;
    }

    return (L->data +  (size - 1.0) * averageLinkedList(L->next, n))/size;
}

float avg(struct Node * L, int * n) {
    if(L == NULL){
        return 0;
    }
    if(L->next == NULL) {
        return (float)L->data;
    }
    (*n) ++;
    printf("%d\n", L->data);
    return (L->data +  avg(L->next, n))/(*n);
}

int main(void) {
    Node * L = malloc(sizeof(Node));
    L->data = 1;
    L->next = NULL;
    Node * temp = L;
    for(int i = 2; i <= 20; i++) {
        temp->next = malloc(sizeof(Node));
        temp = temp->next;
        temp->data = i;
        temp->next = NULL;
    }

    int n = 0;
    printf("%.2f\n", averageLinkedList(L, &n));
}