//预处理
#ifndef QSTACK_H
#define QSTACK_H
#include<stdio.h>
#include<stdlib.h>
//元素类型
#define elements int
//元素初始值
#define InitialElements 0;

/*换个好记的名字*/
//队列
typedef struct queue Qqueue;
//队列指针
typedef Qqueue* Ptrtoqueue;


//结构体声明
//队列
struct queue{
    //队列的规模，即最大储存量
    int scale;
    //队列的前部
    int front;
    //队列的后部
    int rear;
    //队列的主体
    elements * queues;
};


/*函数声明*/
//建栈，建立一个给定大小的队列
Ptrtoqueue Createqueue(int scale);
//清空，将队列清空
void EmptyQqueue(Ptrtoqueue queue);
//入队
void Enqueue(Ptrtoqueue queue, elements x);
//出队
elements Dequeue(Ptrtoqueue queue);
//展示内部结构，用于debug
void display(Ptrtoqueue queue);
/*函数实现*/

Ptrtoqueue Createqueue(int scale){
    Ptrtoqueue queue = (Ptrtoqueue)malloc(sizeof(Qqueue));
    queue->front=0;
    queue->scale=scale+1;//循环队列中，可承载的任务数为整体规模-1;
    queue->rear=0;
    queue->queues=(elements*)malloc(sizeof(elements)*(scale+1));
}

void EmptyQqueue(Ptrtoqueue queue){
    int i;
    for(i=0;i<queue->scale;i++){
        queue->queues[i]=InitialElements;
    }
    queue->front=0;
    queue->rear=0;
}
void Enqueue(Ptrtoqueue queue, elements x){
    queue->rear=(queue->rear+1)%queue->scale;
    if(queue->front==queue->rear){//上溢处理
        queue->rear=(queue->rear-1+queue->scale)%queue->scale;
        printf("error:the queue is full!\n");
        return;
    }
    queue->queues[(queue->rear-1+queue->scale)%queue->scale]=x;
    return;
}
elements Dequeue(Ptrtoqueue queue){
    if(queue->front==queue->rear){
        printf("error:the queue is empty!\n");
        return InitialElements;//有待商榷
    }
    elements result=queue->queues[queue->front];
    queue->queues[queue->front]=InitialElements;
    queue->front=(queue->front+1)%queue->scale;
    return result;
}

void display(Ptrtoqueue queue){
    printf("type:queue\nability:%d\nfront:%d\nrear:%d\nqueue:",queue->scale-1,queue->front,queue->rear);
    int i;
    for(i=queue->front;i!=queue->rear;i=(i+1)%queue->scale){
        printf("%d ",queue->queues[i]);
    }
    printf("\nstate:");
    if(queue->front==queue->rear){
        printf("empty");
    }
    else if (queue->front==(queue->rear+1)%queue->scale){
        printf("full");
    }
    else{
        printf("available");
    }
    printf("\n");
}


#endif