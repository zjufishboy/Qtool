#include<stdio.h>
#include<stdlib.h>
#include"../header/Qstack.h"

int main(){
    Ptrtostack x = Createstack(2);
    Pop(x);
    Push(x,3);
    Push(x,3);
    Push(x,3);
    Pop(x);
    Push(x,3);
    EmptyQstack(x);
    printf("%d",x->top);
    return 0;
}