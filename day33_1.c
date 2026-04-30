#include <stdio.h>
#include <ctype.h>

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || m == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], stack[100];
    int top = -1;

    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top > -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--;
        } else {
            while (top > -1 && prec(c) <= prec(stack[top])) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    while (top > -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    return 0;
}