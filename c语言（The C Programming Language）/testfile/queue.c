#include<stdio.h>
#include<stdlib.h>
#include"../header/Qqueue.h"

int main(){
    Ptrtoqueue x = Createqueue(3);
    Enqueue(x,1);
    Enqueue(x,3);
    Enqueue(x,5);
    Dequeue(x);
    Enqueue(x,7);
    Dequeue(x);
    Enqueue(x,9);
    Dequeue(x);
    Enqueue(x,11);
    Dequeue(x);
    display(x);
    EmptyQqueue(x);

    return 0;
}