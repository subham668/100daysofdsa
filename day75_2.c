#include <stdio.h>
int dfs(int node, int color, int colors[], int graphSize, int graph[][100], int colSize[]) {
    colors[node] = color;

    for(int i = 0; i < colSize[node]; i++) {
        int neigh = graph[node][i];

        if(colors[neigh] == -1) {
            if(!dfs(neigh, 1 - color, colors, graphSize, graph, colSize))
                return 0;
        } else if(colors[neigh] == color) {
            return 0;
        }
    }
    return 1;
}
int isBipartite(int graphSize, int graph[][100], int colSize[]) {
    int colors[100];

    for(int i = 0; i < graphSize; i++)
        colors[i] = -1;

    for(int i = 0; i < graphSize; i++) {
        if(colors[i] == -1) {
            if(!dfs(i, 0, colors, graphSize, graph, colSize))
                return 0;
        }
    }
    return 1;
}
int main() {
    int n = 4;
    int graph[4][100] = {
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };
    int colSize[4] = {3,2,3,2};
    if(isBipartite(n, graph, colSize))
        printf("true");
    else
        printf("false");

    return 0;
}