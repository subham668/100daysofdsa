// Day46_1.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int val){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void levelOrder(struct Node* root){
    if(!root) return;

    struct Node* q[1000];
    int f=0,r=0;

    q[r++] = root;

    while(f<r){
        struct Node* temp = q[f++];
        printf("%d ",temp->data);

        if(temp->left) q[r++] = temp->left;
        if(temp->right) q[r++] = temp->right;
    }
}

int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    levelOrder(root);
}