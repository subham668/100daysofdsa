#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

int postIndex;

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end) return NULL;

    int val = postorder[postIndex--];
    struct Node* root = newNode(val);

    if (start == end) return root;

    int pos = search(inorder, start, end, val);

    root->right = buildTree(inorder, postorder, pos + 1, end);
    root->left  = buildTree(inorder, postorder, start, pos - 1);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}