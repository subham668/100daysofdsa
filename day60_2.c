#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera
    }

    // If any child has camera
    if (left == 1 || right == 1) {
        return 2; // covered
    }

    return 0; // not covered
}

int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

// Example usage
int main() {
    /*
        Example Tree:
            0
           /
          0
         / \
        0   0
    */

    struct TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->right = createNode(0);

    printf("Minimum Cameras: %d\n", minCameraCover(root));

    return 0;
}