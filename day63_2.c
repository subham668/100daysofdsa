#include <stdio.h>

void dfs(int image[][100], int m, int n, int r, int c, int oldColor, int newColor) {
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    if(image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, m, n, r+1, c, oldColor, newColor);
    dfs(image, m, n, r-1, c, oldColor, newColor);
    dfs(image, m, n, r, c+1, oldColor, newColor);
    dfs(image, m, n, r, c-1, oldColor, newColor);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int image[100][100];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if(oldColor != color) {
        dfs(image, m, n, sr, sc, oldColor, color);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}