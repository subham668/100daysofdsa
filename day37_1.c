#include <stdio.h>
#define MAX 100

int pq[MAX];
int size=0;

void insert(int x){
    int i=size-1;
    while(i>=0 && pq[i]>x){
        pq[i+1]=pq[i];
        i--;
    }
    pq[i+1]=x;
    size++;
}

int delete(){
    if(size==0) return -1;
    return pq[--size];
}

int peek(){
    if(size==0) return -1;
    return pq[0];
}

int main(){
    int n,x;
    char op[10];
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(op[0]=='i'){
            scanf("%d",&x);
            insert(x);
        }else if(op[0]=='d'){
            printf("%d\n",delete());
        }else if(op[0]=='p'){
            printf("%d\n",peek());
        }
    }
    return 0;
}