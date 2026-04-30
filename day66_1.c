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

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[MAX];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}