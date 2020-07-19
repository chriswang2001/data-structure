#include <stdio.h>
#include "crosslist.h"

int main()
{
    CrossList CL = {NULL, NULL, 0, 0, 0};
    ElemType A[] = {0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 48, 62, 9, 69, 0, 0, 5, 31, 58, 0, 0, 0, 42, 0, 71, 42, 0, 0, 0, 41, 0, 72, 15, 0};
    
    printf("%d\n",init_cross_list(&CL, A, 5, 7));

    printf("%d %d %d\n",CL.rows,CL.cols,CL.nums);

    del_cross_list(&CL, 58);

    DestroyCrossList(&CL);

    return 0;
}