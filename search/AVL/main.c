#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    node_t *t = CreateFromFile();
    PreOrder(t);
    Destroy(t);

    return 0;
}