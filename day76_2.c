#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* map[101];

struct Node* clone(struct Node* node) {
    if (!node) return NULL;

    if (map[node->val]) return map[node->val];

    struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
    copy->val = node->val;
    copy->numNeighbors = node->numNeighbors;
    copy->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    map[node->val] = copy;

    for (int i = 0; i < node->numNeighbors; i++) {
        copy->neighbors[i] = clone(node->neighbors[i]);
    }

    return copy;
}

struct Node* cloneGraph(struct Node* node) {
    for (int i = 0; i <= 100; i++) map[i] = NULL;
    return clone(node);
}