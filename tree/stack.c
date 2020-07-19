#include "tree.h"
#include <stdbool.h>

void init_stack(Stack *S)
{
    S->top = -1;
}

bool push(Stack *S, ElemType x)
{
    if (S->top == (Stack_Size - 1))
        return false;
    S->top++;
    S->elem[S->top] = x;
    return true;
}

bool pop(Stack *S, ElemType *px)
{
    if (S->top == -1)
        return false;
    else
    {
        *px = S->elem[S->top];
        S->top--;
        return true;
    }
}

bool top(Stack *S, ElemType *px)
{
    if (S->top == -1)
        return false;
    else
    {
        *px = S->elem[S->top];
        return true;
    }
}

bool is_empty(Stack *S)
{
    if(S->top == -1)
        return true;
    else
        return false;
}
