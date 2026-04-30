#include <limits.h>
#include <stdlib.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int visited[n];
    int minDist[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;
    int cost = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        cost += minDist[u];

        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    return cost;
}