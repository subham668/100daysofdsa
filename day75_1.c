#include <stdio.h>
#include <string.h>

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
    memset(visited, 0, sizeof(visited));

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
    int n;
    scanf("%d", &n);

    int isConnected[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    printf("%d", findCircleNum(n, isConnected));

    return 0;
}