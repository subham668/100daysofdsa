// Day47_1.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left,*right;
};

int height(struct Node* root){
    if(!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l>r?l:r)+1;
}

int main(){
    struct Node* root = malloc(sizeof(struct Node));
    root->data = 1;
    root->left = root->right = NULL;

    printf("%d",height(root));
}