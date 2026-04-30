#include <stdio.h>
#include <stdlib.h>

struct KthLargest{
    int *heap;
    int size;
    int k;
};

void swap(int *a,int *b){
    int t=*a;*a=*b;*b=t;
}

void heapifyUp(struct KthLargest* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->heap[p]>obj->heap[i]){
            swap(&obj->heap[p],&obj->heap[i]);
            i=p;
        }else break;
    }
}

void heapifyDown(struct KthLargest* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<obj->size && obj->heap[l]<obj->heap[small]) small=l;
        if(r<obj->size && obj->heap[r]<obj->heap[small]) small=r;
        if(small!=i){
            swap(&obj->heap[i],&obj->heap[small]);
            i=small;
        }else break;
    }
}

void init(struct KthLargest* obj,int k){
    obj->heap=(int*)malloc(sizeof(int)*k);
    obj->size=0;
    obj->k=k;
}

int add(struct KthLargest* obj,int val){
    if(obj->size<obj->k){
        obj->heap[obj->size]=val;
        heapifyUp(obj,obj->size);
        obj->size++;
    }else if(val>obj->heap[0]){
        obj->heap[0]=val;
        heapifyDown(obj,0);
    }
    return obj->heap[0];
}

int main(){
    struct KthLargest obj;
    init(&obj,3);

    add(&obj,4);
    add(&obj,5);
    add(&obj,8);
    add(&obj,2);

    printf("%d\n",add(&obj,3));
    printf("%d\n",add(&obj,5));
    printf("%d\n",add(&obj,10));
    printf("%d\n",add(&obj,9));
    printf("%d\n",add(&obj,4));

    return 0;
}