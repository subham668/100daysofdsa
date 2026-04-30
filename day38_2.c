#include <stdio.h>
#include <stdlib.h>

struct KthLargest{
    int *h;
    int size,k;
};

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void up(struct KthLargest* o,int i){
    while(i>0){
        int p=(i-1)/2;
        if(o->h[p]>o->h[i]){swap(&o->h[p],&o->h[i]);i=p;}
        else break;
    }
}

void down(struct KthLargest* o,int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<o->size && o->h[l]<o->h[s]) s=l;
        if(r<o->size && o->h[r]<o->h[s]) s=r;
        if(s!=i){swap(&o->h[i],&o->h[s]);i=s;}
        else break;
    }
}

void init(struct KthLargest* o,int k){
    o->h=(int*)malloc(sizeof(int)*k);
    o->size=0;
    o->k=k;
}

int add(struct KthLargest* o,int v){
    if(o->size<o->k){
        o->h[o->size]=v;
        up(o,o->size);
        o->size++;
    }else if(v>o->h[0]){
        o->h[0]=v;
        down(o,0);
    }
    return o->h[0];
}

int main(){
    struct KthLargest o;
    init(&o,3);
    printf("%d\n",add(&o,4));
    printf("%d\n",add(&o,5));
    printf("%d\n",add(&o,8));
    printf("%d\n",add(&o,2));
    printf("%d\n",add(&o,3));
    printf("%d\n",add(&o,5));
    printf("%d\n",add(&o,10));
    printf("%d\n",add(&o,9));
    printf("%d\n",add(&o,4));
    return 0;
}