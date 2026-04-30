#include <stdlib.h>

void dfs(int u, int parent, int *vis, int *disc, int *low, int *ap,
         int **adj, int *adjSize, int *time) {
    vis[u] = 1;
    disc[u] = low[u] = (*time)++;
    int children = 0;

    for(int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if(v == u) continue;

        if(!vis[v]) {
            children++;
            dfs(v, u, vis, disc, low, ap, adj, adjSize, time);

            if(low[v] < low[u]) low[u] = low[v];

            if(parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if(v != parent) {
            if(disc[v] < low[u]) low[u] = disc[v];
        }
    }

    if(parent == -1 && children > 1)
        ap[u] = 1;
}

int* articulationPoints(int V, int** adj, int* adjSize, int* returnSize) {
    int *vis = calloc(V, sizeof(int));
    int *disc = malloc(V * sizeof(int));
    int *low = malloc(V * sizeof(int));
    int *ap = calloc(V, sizeof(int));

    int time = 0;

    for(int i = 0; i < V; i++) {
        if(!vis[i])
            dfs(i, -1, vis, disc, low, ap, adj, adjSize, &time);
    }

    int count = 0;
    for(int i = 0; i < V; i++)
        if(ap[i]) count++;

    if(count == 0) {
        int *res = malloc(sizeof(int));
        res[0] = -1;
        *returnSize = 1;
        return res;
    }

    int *res = malloc(count * sizeof(int));
    int idx = 0;

    for(int i = 0; i < V; i++)
        if(ap[i]) res[idx++] = i;

    *returnSize = count;
    return res;
}