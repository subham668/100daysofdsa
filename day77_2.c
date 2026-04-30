#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} List;

void addEdge(List *adj, int u, int v) {
    adj[u].data = realloc(adj[u].data, (adj[u].size + 1) * sizeof(int));
    adj[u].data[adj[u].size++] = v;
}

void dfs(int u, int parent, int *disc, int *low, int *time,
         List *adj, int **res, int *returnSize) {
    disc[u] = low[u] = (*time)++;

    for(int i = 0; i < adj[u].size; i++) {
        int v = adj[u].data[i];

        if(v == parent) continue;

        if(disc[v] == -1) {
            dfs(v, u, disc, low, time, adj, res, returnSize);

            if(low[v] < low[u]) low[u] = low[v];

            if(low[v] > disc[u]) {
                res[*returnSize] = malloc(2 * sizeof(int));
                res[*returnSize][0] = u;
                res[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if(disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {

    List *adj = malloc(n * sizeof(List));
    for(int i = 0; i < n; i++) {
        adj[i].data = NULL;
        adj[i].size = 0;
    }

    for(int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int *disc = malloc(n * sizeof(int));
    int *low = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) disc[i] = -1;

    int time = 0;
    int **res = malloc(connectionsSize * sizeof(int*));
    *returnSize = 0;

    dfs(0, -1, disc, low, &time, adj, res, returnSize);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 2;

    return res;
}