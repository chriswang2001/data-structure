#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Queue* create_queue()
{
    static Queue q;
    q.i = q.j = 0;
    q.array = (void**)malloc(Queue_Size*sizeof(void*));

    return &q;
}

bool is_empty_queue(Queue *tree)
{
    if(tree->i == tree->j)
        return true;
    else
        return false;
}

void* del_queue(Queue *tree)
{
    if(tree->i == tree->j)
	    return false;
    
    int t = tree->i;
    tree->i = (tree->i + 1) % Queue_Size;
	return tree->array[t];
}

void add_queue(Queue *tree, void *node)
{	
	tree->array[tree->j]= node;
	tree->j = (tree->j +1) % Queue_Size;
}

void free_queue(Queue *tree)
{
    tree->i = tree->j = 0;
    free(tree->array);
}