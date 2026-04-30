#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val,freq;
};

struct Node h[10000];
int size=0;

void swap(struct Node *a,struct Node *b){struct Node t=*a;*a=*b;*b=t;}

void up(int i){
    while(i>0){
        int p=(i-1)/2;
        if(h[p].freq<h[i].freq){swap(&h[p],&h[i]);i=p;}
        else break;
    }
}

void down(int i){
    while(1){
        int l=2*i+1,r=2*i+2,b=i;
        if(l<size && h[l].freq>h[b].freq) b=l;
        if(r<size && h[r].freq>h[b].freq) b=r;
        if(b!=i){swap(&h[i],&h[b]);i=b;}
        else break;
    }
}

void insert(int val,int freq){
    h[size].val=val;
    h[size].freq=freq;
    up(size);
    size++;
}

struct Node extract(){
    struct Node t=h[0];
    h[0]=h[--size];
    down(0);
    return t;
}

int main(){
    int nums[]={1,1,1,2,2,3};
    int n=6,k=2;

    int freq[20001]={0};

    for(int i=0;i<n;i++) freq[nums[i]+10000]++;

    for(int i=0;i<20001;i++){
        if(freq[i]>0) insert(i-10000,freq[i]);
    }

    for(int i=0;i<k;i++){
        struct Node t=extract();
        printf("%d ",t.val);
    }

    return 0;
}