#include <stdio.h>

#include "TSMatrix.h"

int main()
{
    TSMatrix A = 
    {
        {
            {1, 1, 11},
            {2, 1, 11},
            {3, 2, 29},
            {4, 1, 35},
            {5, 2, 32}
        },
         7, 2, 5,
    };

    TSMatrix B = 
    {
        {
            {7, 1, 47}
        },
         7, 2, 1,
    };

    TSMatrix C;

    ShowTSMatrix(&A);
    ShowTSMatrix(&B);

    add_matrix(&A, &B, &C);

    ShowTSMatrix(&C);

    return 0;
}