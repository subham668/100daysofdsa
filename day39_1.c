#include <stdio.h>
#define MAX 100

int h[MAX];
int size=0;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void up(int i){
    while(i>0){
        int p=(i-1)/2;
        if(h[p]>h[i]){swap(&h[p],&h[i]);i=p;}
        else break;
    }
}

void down(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size && h[l]<h[s]) s=l;
        if(r<size && h[r]<h[s]) s=r;
        if(s!=i){swap(&h[i],&h[s]);i=s;}
        else break;
    }
}

void insert(int x){
    h[size]=x;
    up(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int m=h[0];
    h[0]=h[--size];
    down(0);
    return m;
}

int peek(){
    if(size==0) return -1;
    return h[0];
}

int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(op[0]=='i'){
            scanf("%d",&x);
            insert(x);
        }else if(op[0]=='e'){
            printf("%d\n",extractMin());
        }else if(op[0]=='p'){
            printf("%d\n",peek());
        }
    }
    return 0;
}