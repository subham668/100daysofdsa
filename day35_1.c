#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(rear==NULL){
        front=rear=t;
        return;
    }
    rear->next=t;
    rear=t;
}

void display(){
    struct Node* temp=front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    display();
    return 0;
}