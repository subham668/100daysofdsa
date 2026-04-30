#include <stdio.h>
int main() {
    int a, b, c = 1;
    printf("Enter the power: ");
    scanf("%d", &a);
    for(b = 1; b <= a; b++) {
        c = c * 2;
    }
    printf("%d", c);
    return 0;
}
