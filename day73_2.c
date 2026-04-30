#include <stdio.h>

int find(int parent[], int x) {
    if(parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int a, int b) {
    int pa = find(parent, a);
    int pb = find(parent, b);
    if(pa != pb)
        parent[pa] = pb;
}

int* findRedundantConnection(int edges[][2], int n) {
    static int result[2];
    int parent[n+1];

    for(int i = 1; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if(find(parent, u) == find(parent, v)) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(parent, u, v);
        }
    }

    return result;
}

int main() {
    int edges1[3][2] = {{1,2},{1,3},{2,3}};
    int *res1 = findRedundantConnection(edges1, 3);
    printf("[%d,%d]\n", res1[0], res1[1]);

    int edges2[5][2] = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    int *res2 = findRedundantConnection(edges2, 5);
    printf("[%d,%d]\n", res2[0], res2[1]);

    return 0;
}