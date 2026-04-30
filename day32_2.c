#include <stdio.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
}

void push(MinStack *s, int val) {
    s->top++;
    s->stack[s->top] = val;

    if (s->top == 0)
        s->minStack[s->top] = val;
    else {
        if (val < s->minStack[s->top - 1])
            s->minStack[s->top] = val;
        else
            s->minStack[s->top] = s->minStack[s->top - 1];
    }
}

void pop(MinStack *s) {
    if (s->top >= 0)
        s->top--;
}

int top(MinStack *s) {
    if (s->top >= 0)
        return s->stack[s->top];
    return -1;
}

int getMin(MinStack *s) {
    if (s->top >= 0)
        return s->minStack[s->top];
    return -1;
}

int main() {
    MinStack s;
    init(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    printf("%d\n", getMin(&s));

    pop(&s);

    printf("%d\n", top(&s));    
    printf("%d\n", getMin(&s)); 

    return 0;
}