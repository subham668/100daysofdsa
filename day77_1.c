#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} List;

void addEdge(List *adj, int u, int v) {
    adj[u].data = realloc(adj[u].data, (adj[u].size + 1) * sizeof(int));
    adj[u].data[adj[u].size++] = v;
}

void dfs(int u, int *vis, List *adj) {
    vis[u] = 1;
    for(int i = 0; i < adj[u].size; i++) {
        int v = adj[u].data[i];
        if(!vis[v])
            dfs(v, vis, adj);
    }
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
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int *vis = calloc(n + 1, sizeof(int));

    dfs(1, vis, adj);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}