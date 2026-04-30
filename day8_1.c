#include <stdio.h>
int power(int a, int b) {
    if(b == 0)
        return 1;
    return a * power(a, b - 1);
}
int main() {
    int a, b;
    printf("Enter the base value: ");
    scanf("%d", &a);
    printf("Enter the exponent value: ");
    scanf("%d", &b);
    printf("Result of %d raised to power %d is:\n", a, b);
    printf("%d", power(a, b));
    return 0;
}
