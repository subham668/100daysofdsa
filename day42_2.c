#include <stdlib.h>

#define MAX 10000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int heap[], int i){
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] < heap[i]){
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void maxHeapifyDown(int heap[], int size, int i){
    while(2*i+1 < size){
        int l = 2*i+1, r = 2*i+2, largest = i;
        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;
        if(largest != i){
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
}

void minHeapifyUp(int heap[], int i){
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] > heap[i]){
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void minHeapifyDown(int heap[], int size, int i){
    while(2*i+1 < size){
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if(l < size && heap[l] < heap[smallest]) smallest = l;
        if(r < size && heap[r] < heap[smallest]) smallest = r;
        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    obj->maxHeap[obj->maxSize++] = num;
    maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);

    obj->minHeap[obj->minSize++] = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
    maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

    minHeapifyUp(obj->minHeap, obj->minSize - 1);

    if(obj->minSize > obj->maxSize){
        obj->maxHeap[obj->maxSize++] = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

double findMedian(MedianFinder* obj) {
    if(obj->maxSize > obj->minSize){
        return obj->maxHeap[0];
    }
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}