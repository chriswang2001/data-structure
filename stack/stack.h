#pragma once

#include <stdbool.h>

#define Stack_Size 50

typedef int ElemType;

typedef struct
{
    ElemType elem[Stack_Size];
    int top;
}Stack;

extern bool push(Stack* S, ElemType x);
extern bool pop(Stack* S, ElemType *x);
extern void init_stack(Stack *S);
