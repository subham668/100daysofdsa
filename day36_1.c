#include <stdio.h>
#define MAX 100

int q[MAX];
int front=0,rear=0;

void enqueue(int x){
    q[rear]=x;
    rear=(rear+1)%MAX;
}

void dequeue(){
    front=(front+1)%MAX;
}

void display(){
    int i=front;
    while(i!=rear){
        printf("%d ",q[i]);
        i=(i+1)%MAX;
    }
}

int main(){
    int n,m,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) dequeue();
    display();
    return 0;
}