#include "graph.h"
#include <stdio.h>

int main()
{
    MatrixGraph G;
    CreateGraph(&G);
    DrawGraph(&G);
    matrix_insert_vertex(&G, 15);
    matrix_insert_arc(&G, 63, 45);
    putchar('\n');
    DrawGraph(&G);
    DestroyGraph(&G);
    
    return 0;
}