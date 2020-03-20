#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
    printf("\telements:[\n");
    int i=1,j=1,k=1;
    while(j<=h->scale){
        while(j<2*i&&j<=h->scale){
            printf("%d ",h->elements[j]);
            j++;
        }
        printf("\n");
        i*=2;
    }
    printf("]\n");
}
mHeap createMinHeap(int capacity){
    if(capacity<=0){
        printf("[E]capacity should be huger than 0\n");
        return NULL;
    }
    mHeap h=(mHeap)malloc(sizeof(struct MinHeap));
    h->elements=(element*)malloc(sizeof(element)*(capacity+1));
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
element MinHeapPop(mHeap h){
    if(h->scale==0)
        return -1;
    element res=h->elements[1];
    h->elements[1]=h->elements[h->scale];
    h->scale--;
    int p=1,minChild=0;
    while(p*2<=h->scale){
        if(p*2+1>h->scale){
            minChild=p*2;
        }
        else {
            minChild = h->elements[p*2]<h->elements[p*2+1]?p*2:p*2+1;
        }
        if(h->elements[p]>h->elements[minChild]){
            h->elements[0] = h->elements[p];
            h->elements[p] = h->elements[minChild];
            h->elements[minChild] = h->elements[0];
            h->elements[0] = 0;
            p=minChild;
        }
        else{
            break;
        }
    }
    return res;
}
int main(){
    mHeap h=createMinHeap(9);
    int nums[]={9,8,7,6,5,4,3,2,1};
    int len=9,i=0;
    for(i=0;i<len;i++){
        MinHeapInsert(h,nums[i]);
        report(h);
    }
        
    for(i=0;i<len;i++){
        MinHeapPop(h);
        report(h);
    }

    
}