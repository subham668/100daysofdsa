#include <stdio.h>
#define MAX 100

int s1[MAX],s2[MAX];
int top1=-1,top2=-1;

void push1(int x){s1[++top1]=x;}
int pop1(){return s1[top1--];}
void push2(int x){s2[++top2]=x;}
int pop2(){return s2[top2--];}

void push(int x){push1(x);}

int pop(){
    if(top2==-1){
        while(top1!=-1) push2(pop1());
    }
    return pop2();
}

int peek(){
    if(top2==-1){
        while(top1!=-1) push2(pop1());
    }
    return s2[top2];
}

int empty(){
    return top1==-1 && top2==-1;
}

int main(){
    push(1);
    push(2);
    push(3);
    printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",empty());
    return 0;
}