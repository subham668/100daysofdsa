#include <stdio.h>
#define MAX 100

struct MyQueue{
    int s1[MAX],s2[MAX];
    int top1,top2;
};

void init(struct MyQueue* q){
    q->top1=-1;
    q->top2=-1;
}

void push(struct MyQueue* q,int x){
    q->s1[++q->top1]=x;
}

int pop(struct MyQueue* q){
    if(q->top2==-1){
        while(q->top1!=-1){
            q->s2[++q->top2]=q->s1[q->top1--];
        }
    }
    return q->s2[q->top2--];
}

int peek(struct MyQueue* q){
    if(q->top2==-1){
        while(q->top1!=-1){
            q->s2[++q->top2]=q->s1[q->top1--];
        }
    }
    return q->s2[q->top2];
}

int empty(struct MyQueue* q){
    return q->top1==-1 && q->top2==-1;
}

int main(){
    struct MyQueue q;
    init(&q);
    push(&q,1);
    push(&q,2);
    push(&q,3);
    printf("%d\n",peek(&q));
    printf("%d\n",pop(&q));
    printf("%d\n",empty(&q));
    return 0;
}