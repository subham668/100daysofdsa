// Day47_2.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left,*right;
};

int maxDepth(struct Node* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l>r?l:r)+1;
}

int main(){
    struct Node* root = malloc(sizeof(struct Node));
    root->val = 1;

    root->left = NULL;
    root->right = malloc(sizeof(struct Node));
    root->right->val = 2;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("%d",maxDepth(root));
}