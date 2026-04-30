// Day45_1.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int arr[], int n, int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root = create(arr[i]);
    root->left = build(arr,n,2*i+1);
    root->right = build(arr,n,2*i+2);
    return root;
}

int height(struct Node* root){
    if(!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l>r?l:r)+1;
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root = build(arr,n,0);
    printf("%d",height(root));
}