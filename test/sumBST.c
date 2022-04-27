#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * iChild;
    struct Node * rChild;
} Node; 

int sumBST(Node * root) {
    if(root == NULL) {
        return 0;
    }
    int left = sumBST(root->iChild);
    int right = sumBST(root->rChild);
    if(root->data > 10) {
        return left + right + root->data;
    }
    return left + right;
}

int main(void) {
    Node * root = malloc(sizeof(Node));
    root->data = 1;
    root->iChild = NULL;
    root->rChild = NULL;
    Node * temp = root;
    for(int i = 2; i <= 20; i++) {
        temp->rChild = malloc(sizeof(Node));
        temp = temp->rChild;
        temp->data = i;
        temp->iChild = NULL;
        temp->rChild = NULL;
    }
    printf("%d\n", sumBST(root));
}

