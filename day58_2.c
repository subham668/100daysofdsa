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

int preIndex = 0;

struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end) return NULL;

    int val = preorder[preIndex++];
    struct Node* root = newNode(val);

    if (start == end) return root;

    int pos = search(inorder, start, end, val);

    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);

    return root;
}

void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* q[1000];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        struct Node* node = q[f++];
        printf("%d ", node->data);

        if (node->left) q[r++] = node->left;
        if (node->right) q[r++] = node->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    levelOrder(root);

    return 0;
}