// Day45_2.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void levelOrder(struct Node* root){
    if(!root) return;

    struct Node* queue[1000];
    int front=0,rear=0;

    queue[rear++] = root;

    while(front<rear){
        int size = rear-front;
        while(size--){
            struct Node* temp = queue[front++];
            printf("%d ",temp->data);

            if(temp->left) queue[rear++] = temp->left;
            if(temp->right) queue[rear++] = temp->right;
        }
        printf("\n");
    }
}

int main(){
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);
}