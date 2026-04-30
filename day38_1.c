#include <stdio.h>
#define MAX 100

int dq[MAX];
int front=-1,rear=-1;

int empty(){return front==-1;}

int size(){
    if(front==-1) return 0;
    if(rear>=front) return rear-front+1;
    return MAX-front+rear+1;
}

void push_front(int x){
    if(front==-1){
        front=rear=0;
        dq[front]=x;
    }else{
        front=(front-1+MAX)%MAX;
        dq[front]=x;
    }
}

void push_back(int x){
    if(front==-1){
        front=rear=0;
        dq[rear]=x;
    }else{
        rear=(rear+1)%MAX;
        dq[rear]=x;
    }
}

void pop_front(){
    if(empty()) return;
    if(front==rear) front=rear=-1;
    else front=(front+1)%MAX;
}

void pop_back(){
    if(empty()) return;
    if(front==rear) front=rear=-1;
    else rear=(rear-1+MAX)%MAX;
}

int get_front(){
    if(empty()) return -1;
    return dq[front];
}

int get_back(){
    if(empty()) return -1;
    return dq[rear];
}

void display(){
    if(empty()) return;
    int i=front;
    while(1){
        printf("%d ",dq[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
}

int main(){
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    pop_front();
    printf("%d\n",get_front());
    printf("%d\n",get_back());
    printf("%d\n",size());
    display();
    return 0;
}