#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v, w;
} Edge;

typedef struct {
    Edge *data;
    int size;
} List;

void addEdge(List *adj, int u, int v, int w) {
    adj[u].data = realloc(adj[u].data, (adj[u].size + 1) * sizeof(Edge));
    adj[u].data[adj[u].size].v = v;
    adj[u].data[adj[u].size].w = w;
    adj[u].size++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    List *adj = malloc((n + 1) * sizeof(List));
    for(int i = 1; i <= n; i++) {
        adj[i].data = NULL;
        adj[i].size = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    int *key = malloc((n + 1) * sizeof(int));
    int *mst = calloc(n + 1, sizeof(int));

    for(int i = 1; i <= n; i++) key[i] = INT_MAX;
    key[1] = 0;

    int total = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1, min = INT_MAX;
        for(int j = 1; j <= n; j++) {
            if(!mst[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        mst[u] = 1;
        total += key[u];

        for(int j = 0; j < adj[u].size; j++) {
            int v = adj[u].data[j].v;
            int w = adj[u].data[j].w;
            if(!mst[v] && w < key[v]) {
                key[v] = w;
            }
        }
    }

    printf("%d\n", total);
    return 0;
}