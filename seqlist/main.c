#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list_interface.h"

void print(SeqList L)
{
    for(int i = 0; i <= L.last; i++)
        printf("%4d",L.elem[i]);
    putchar('\n');
}

int main()
{
    SeqList L = {{621,227,287,223,44,456,158,371,269,992,378,218,602,881,95,212,193}, 16};
    print(L);
    
    //del_x2y(&L, 1, 9);
    //print(L);

    //del_dupnum(&L);
    //print(L);

    odd_even(&L);
    print(L);

    return 0;
}
