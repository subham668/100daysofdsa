#include <stdio.h>
#include <stdlib.h>

#define MAX 2005

int visited[MAX];
int recStack[MAX];

struct Node {
    int data;
    struct Node* next;
};

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(int node, struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int v = temp->data;

        if (!visited[v]) {
            if (dfs(v, adj))
                return 1;
        } else if (recStack[v]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}

int canFinish(int numCourses, int prerequisites[][2], int size) {
    struct Node* adj[MAX];

    for (int i = 0; i < numCourses; i++)
        adj[i] = NULL;

    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(adj, b, a);
    }

    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj))
                return 0;
        }
    }

    return 1;
}

int main() {
    int numCourses, size;
    scanf("%d %d", &numCourses, &size);

    int prerequisites[size][2];

    for (int i = 0; i < size; i++) {
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    if (canFinish(numCourses, prerequisites, size))
        printf("true");
    else
        printf("false");

    return 0;
}