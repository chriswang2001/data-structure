#include "graph.h"
#include <stdio.h>

int main()
{
    ListGraph G;

    CreateGraph(&G);
    DrawGraph(&G);

    int v;
    scanf("%d", &v);
    // insert_vertex(&G, 15);
    // insert_arc(&G, 63, 45);
    del_vertex(&G, v);
    putchar('\n');
    printf("%d",G.arcnum);
    
    putchar('\n');
    DrawGraph(&G);
    
    DestroyGraph(&G);
    
    return 0;
}