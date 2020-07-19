#include "TSMatrix.h"
#include <stdbool.h>
#include <stdio.h>

void add_matrix_MorN(const TSMatrix *M, TSMatrix *Q, int* k, int* x)
{
    Q->data[*k] = M->data[*x];
    (*x)++; (*k)++;
}

void add_matrix_MandN(const TSMatrix *M, const TSMatrix *N, TSMatrix *Q, int* k, int* x, int*y)
{
    Q->data[*k] = M->data[*x];
    Q->data[*k].e = M->data[*x].e + N->data[*y].e;
    (*k)++; (*x)++; (*y)++;
}

/*
 *pM, pN, pQ 分别指向三个矩阵，
 *当 pM 和 pN 两个矩阵不可加时，函数返回 false，
 *否则函数返回 true，且 pQ 指向两个矩阵的和。
 */
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
    if(pM->m != pN->m || pM->n != pN->n)
        return false;
    
    pQ->m = pM->m;
    pQ->n = pM->n;
    
    int x = 0, y = 0, k = 0;
    int elem;
    
    while(x < pM->len && y < pN->len)
    {
        if(pM->data[x].i < pN->data[y].i)
            add_matrix_MorN(pM, pQ, &k, &x);
        
        else if(pM->data[x].i > pN->data[y].i)
            add_matrix_MorN(pN, pQ, &k, &y);
        
        else if(pM->data[x].i == pN->data[y].i)
        {
            if(pM->data[x].j == pN->data[y].j)
            {
                
                if(elem = pM->data[x].e + pN->data[y].e)
                    add_matrix_MandN(pM, pN, pQ, &k, &x, &y);
                
                else
                {
                    x++; y++;
                }
            }

            else if(pM->data[x].j < pN->data[y].j)
                add_matrix_MorN(pM, pQ, &k, &x);

            else if(pM->data[x].j > pN->data[y].j)
                add_matrix_MorN(pN, pQ, &k, &y);
        }  
    }

    while(x < pM->len)
        add_matrix_MorN(pM, pQ, &k, &x);

    while(y < pN->len)
        add_matrix_MorN(pN, pQ, &k, &y);

    pQ->len = k;

    return true;
}

/*
 * 打印三元组稀疏矩阵（只打印非零元）
 */
void ShowTSMatrix(TSMatrix *M)
{
    printf("%d %d %d\n",M->m, M->n, M->len);
    for (int k = 0; k < M->len; ++k)
        printf("(%4d, %4d, %4d)\n", M->data[k].i, M->data[k].j, M->data[k].e);
}