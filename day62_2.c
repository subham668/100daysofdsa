#include <stdio.h>

void dfs(int room, int n, int rooms[n][n], int size[], int visited[]) {
    visited[room] = 1;

    for(int i = 0; i < size[room]; i++) {
        int key = rooms[room][i];
        if(visited[key] == 0) {
            dfs(key, n, rooms, size, visited);
        }
    }
}

int canVisitAllRooms(int n, int rooms[n][n], int size[]) {
    int visited[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(0, n, rooms, size, visited);

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int rooms[n][n];
    int size[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for(int j = 0; j < size[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    int result = canVisitAllRooms(n, rooms, size);

    if(result)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}