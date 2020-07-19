#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

void init_stack(Stack *S)
{
    S->top = -1;
}

bool push(Stack* S, ElemType x)
{
	if(S->top == Stack_Size-1)
		return false;
	else
	{
		S->top++;
		S->elem[S->top] = x;
		
		return true;
	}
}

bool pop(Stack* S, ElemType *x)
{
	if(S->top == -1)
		return false;
	else
	{
		*x = S->elem[S->top];
		S->top--;
		
		return true;
	}
}
