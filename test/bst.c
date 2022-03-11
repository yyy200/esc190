#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int cargo;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

TreeNode * init_tree(int val) {
    TreeNode * new_node = malloc(sizeof(TreeNode));
    new_node->cargo = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int search(TreeNode * root, int val) {
    TreeNode * curr = root;
    while(curr != NULL) {
        if (curr->cargo == val) return 1;
        else if (curr->cargo > val) curr = curr->right;
        else curr = curr->left;
    }

    return 0;
}

int r_search(TreeNode * root, int val) {
    if(root == NULL) return 0;
    else if(root->cargo == val) return 1;
    else if(root->cargo > val) return r_search(root->left, val);
    else return r_search(root->right, val);
}

void insert(TreeNode ** root_ptr, int val) {
    TreeNode * new_node = init_tree(val);
    
    TreeNode * prev = NULL;
    TreeNode * curr = *root_ptr;

    if(curr == NULL) {
        *root_ptr = new_node;
        return;
    }

    while(curr != NULL) {
        prev = curr;
        if (curr->cargo > val) curr = curr->right;
        else curr = curr->left;
    }

    if (prev->cargo > val) curr->right = new_node;
    else prev->left = new_node;
}

void print_tree(TreeNode * root) {
    if (root == NULL) {printf("\n");return;}
    print_tree(root->left);
    printf("%d", root->cargo);
    print_tree(root->right);
}

int main(void) {
    TreeNode * root = init_tree(5);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 4);
    print_tree(root);
}