// Day44_2.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void preorder(struct Node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // example tree: [1,null,2,3]

    struct Node* root = create(1);
    root->left = NULL;

    root->right = create(2);
    root->right->left = create(3);
    root->right->right = NULL;

    preorder(root);

    return 0;
}