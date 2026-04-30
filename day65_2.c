#include <stdio.h>

#define MAX 1000

int visited[MAX];

int dfs(int node, int parent, int adj[MAX][MAX], int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, adj, V))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int edges[E][2];
    int adj[MAX][MAX] = {0};

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int hasCycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, V)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("true");
    else
        printf("false");

    return 0;
}