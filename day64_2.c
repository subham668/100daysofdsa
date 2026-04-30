#include <stdio.h>

#define MAX 100

int queue[MAX * MAX][2];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

void dequeue(int *x, int *y) {
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
}

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int fresh = 0, time = 0;
    int i, j;

    front = rear = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 2)
                enqueue(i, j);
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;
        time++;

        for (i = 0; i < size; i++) {
            int x, y;
            dequeue(&x, &y);

            for (j = 0; j < 4; j++) {
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                }
            }
        }
    }

    if (fresh == 0)
        return time;
    return -1;
}

int main() {
    int m, n, i, j;
    int grid[MAX][MAX];

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d", orangesRotting(grid, m, n));

    return 0;
}