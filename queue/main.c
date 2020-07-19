#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "queue_interface.h"

void print(LinkQueue LQ)
{
    for (LinkQueue i = LQ->next->next; i != LQ; i = i->next)
    {
        printf("%d", i->data);
    }
    
}

void destroy(LinkQueue LQ)
{
    LinkQueue t;
     
    while(LQ != NULL)
    {
        t = LQ;
        LQ = LQ->next;
        free(t);
    }
}

int main()
{
    LinkQueue L;

    init_queue(&L);
    for(int i = 1; i < 10; i++)
        enter_queue(&L, i);
    print(L);
    int k;
    leave_queue(&L, &k);
    print(L);
    
    destroy(L);

    return 0;
}