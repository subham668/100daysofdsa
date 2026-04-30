#include <stdio.h>

void dfs(int n, int isConnected[n][n], int visited[], int city) {
    visited[city] = 1;
    for(int i = 0; i < n; i++) {
        if(isConnected[city][i] == 1 && !visited[i]) {
            dfs(n, isConnected, visited, i);
        }
    }
}

int findCircleNum(int n, int isConnected[n][n]) {
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int provinces = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(n, isConnected, visited, i);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    int n = 3;
    int isConnected[3][3] = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    printf("%d", findCircleNum(n, isConnected));

    return 0;
}