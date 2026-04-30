#include <stdio.h>

void dfs(int city, int n, int isConnected[n][n], int visited[]) {
    visited[city] = 1;

    for(int i = 0; i < n; i++) {
        if(isConnected[city][i] == 1 && visited[i] == 0) {
            dfs(i, n, isConnected, visited);
        }
    }
}

int findCircleNum(int n, int isConnected[n][n]) {
    int visited[n];
    int count = 0;

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i, n, isConnected, visited);
            count++;
        }
    }

    return count;
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

    int result = findCircleNum(n, isConnected);
    printf("%d\n", result);

    return 0;
}