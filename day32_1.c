#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    if (scanf("%d", &m) != 1) m = 0;

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    free(stack);
    return 0;
}