#include"test.h"
#ifndef HEAP_Q
#define HEAP_Q
#define element int
typedef struct MinHeap{
    //元素实体
    element * elements;
    //当前使用量
    int scale;
    //容量
    int capacity;
}* mHeap;
void report(mHeap h){
    printf("report\n");
    printf("\tscale:%d\n",h->scale);
    printf("\tcapacity:%d\n",h->capacity);
    printf("\telements:[");
    int i=0;
    for(i=1;i<h->scale;i++){
        printf("%d ",h->elements[i]);
    }
}
mHeap createMinHeap(int capacity){
    if(capacity<=0){
        printf("[E]capacity should be huger than 0\n");
        return NULL;
    }
    mHeap h=(mHeap)malloc(sizeof(struct MinHeap));
    h->elements=(element*)malloc(sizeof(element)*capacity);
    h->capacity=capacity;
    h->scale=0;
    return h;
}
bool MinHeapInsert(mHeap h,element e){
    if(h->scale==h->capacity)
        return false;
    h->scale++;
    h->elements[h->scale] = e;
    int s,p;
    for (s=h->scale; s > 1;) {
        //寻找这个结点的父结点
        p = s / 2;
        if (h->elements[p] > h->elements[s]) {
            h->elements[0] = h->elements[p];
            h->elements[p] = h->elements[s];
            h->elements[s] = h->elements[0];
            h->elements[0] = 0;
            s = p;
        } else {
            break;
        }
    }
    return true;
}
#endif