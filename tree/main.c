#include "tree.h"
#include <stdio.h>

int main()
{
    // BiTree t1;
    // DataType data1[] = {1,3,7,-1,-1,6,3,-1,-1,8,-1,-1,5,2,-1,-1,-1};
    // CreateBiTree(&t1, data1);
    // pre_order(t1);
    // DestroyBiTree(t1);

    BiTree t2;
    DataType data2[] = {0, 55, 1, 79, -1, -1, 85, -1, -1, 398, 848, -1, -1, 26, -1, -1, 355, 86, -1, -1, 380, 42, -1, -1, 64, -1, -1};
    CreateBiTree(&t2, data2);
    
    Stack s;
    init_stack(&s);
    BiTNode* t = t2->left->right->left;
    path(t2, t, &s);
    printf("%d\n",s.top);
    for(int i = 0; i <= s.top; i++)
        printf("%d ",s.elem[i]->data);
    
    DestroyBiTree(t2);

    return 0;
}