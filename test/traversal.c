#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node * left;
    struct Node * right;
} Node;

void inorder(Node * root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d, ", root->val);
    inorder(root->right);
}

void postorder(Node * root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->val);
}

void preorder(Node * root) {
    if(root == NULL) return;
    printf("%d, ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int search(Node * root, int val) {
    if(root == NULL) return 0;
    if(root->val == val) return 1;

    if(root->val > val) return search(root->left, val);
    else return search(root->right, val);
}

int iterSearch(Node * root, int val) {
    Node * curr = root;
    while(curr != NULL){
        if(curr->val == val) return 1;
        if(curr->val > val) curr = curr->left;
        else curr = curr->right;
    }
    return 0;
}

int min(Node * root) {
    Node * curr = root;
    while(curr->left != NULL) {
        curr = curr->left;
    }

    return curr->val;
}

int max(Node * root) {
    Node * curr = root;
    while(curr->right != NULL) {
        curr = curr->right;
    }

    return curr->val;
}

void bf(Node * root) {

}

void df(Node * root) {

}