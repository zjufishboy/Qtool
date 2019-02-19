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
//栈
typedef struct stack Qstack;
//栈指针
typedef Qstack* Ptrtostack;


//结构体声明
//栈
struct stack{
    //栈的规模，即最大储存量
    int scale;
    //栈顶
    int top;
    //栈的主体
    elements * stacks;
};


/*函数声明*/
//建栈，建立一个给定大小的栈
Ptrtostack Createstack(int scale);
//入栈，将一个元素入栈
void Push(Ptrtostack stack, elements x);
//出栈，将栈顶元素出栈
elements Pop(Ptrtostack stack);
//清空，将栈清空
void EmptyQstack(Ptrtostack stack);

/*函数实现*/

Ptrtostack Createstack(int scale){
    Ptrtostack ptrtostack=(Ptrtostack)malloc(sizeof(Qstack));
    ptrtostack->scale=scale;
    ptrtostack->top=0;
    ptrtostack->stacks=(elements*)malloc(sizeof(elements)*scale);
    return ptrtostack;
}

void Push(Ptrtostack stack, elements x){
    if(stack->top==stack->scale){
        printf("error:the stack is full!\n");
        return;
    }
    stack->top++;
    stack->stacks[stack->top]=x;
    return;
}

elements Pop(Ptrtostack stack){
    if(stack->top==0){
        printf("error:the stack is empty\n");
        return InitialElements;
    }
    elements result=stack->stacks[stack->top];
    stack->stacks[stack->top]=InitialElements;
    stack->top--;
    return result;
}

void EmptyQstack(Ptrtostack stack){
    int i=0;
    for(i=0;i<stack->top;i++){
        stack->stacks[i]=InitialElements;
    }
    stack->top=0;
}




#endif