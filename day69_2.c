#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int n, int k) {
    int adj[101][101];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = -1;

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u][v] = w;
    }

    int dist[101];
    int visited[101] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, min = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1 && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    int max = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > max)
            max = dist[i];
    }

    return max;
}

int main() {
    int n = 4, k = 2;
    int timesSize = 3;

    int data[3][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int* times[3];

    for (int i = 0; i < timesSize; i++)
        times[i] = data[i];

    int result = networkDelayTime(times, timesSize, n, k);

    printf("%d\n", result);

    return 0;
}