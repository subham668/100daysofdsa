#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL){
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(){
    if(front == NULL){
        printf("-1\n");
        return;
    }
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
}

int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        char op[10];
        scanf("%s",op);

        if(op[0]=='e'){  
            int x;
            scanf("%d",&x);
            enqueue(x);
        } else {  
            dequeue();
        }
    }
    return 0;
}