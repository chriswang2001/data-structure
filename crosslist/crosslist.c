#include <stdio.h>
#include <stdlib.h>
#include "crosslist.h"

#define OVERFLOW -1
/*实现十字链表的初始化操作：
 *其中 L 指向 CrossList 结构，且各成员已被初始化为0；
 *A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
 *A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
 *m 表示十字链表的行数，n 表示十字链表的列数。
 *init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。
 */
int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
    L->rows = m;
    L->cols = n;
    L->nums = 0;

    if(!(L->rowhead = (OLink*)malloc(m*sizeof(OLink))))
        exit(OVERFLOW);
    for(int j = 0; j < m; j++)
        L->rowhead[j] = NULL;
    
    if(!(L->colhead = (OLink*)malloc(n*sizeof(OLink))))
        exit(OVERFLOW);
    for(int k = 0; k < n; k++)
        L->colhead[k] = NULL;

    for(int j = 0; j < m; j++)
        for(int k = 0; k < n; k++)
        {
            if(*A)
            {   
                OLink t = (OLink)malloc(sizeof(OLNode));
                t->row = j;
                t->col = k;
                t->value = *A;
                t->right = NULL;
                t->down = NULL;

                OLink x = L->rowhead[j];
                if(x)
                {
                    while(x->right)
                        x = x->right;
                    x->right = t;
                }
                else
                    L->rowhead[j] = t;
                
                OLink y = L->colhead[k];
                if(y)
                {
                    while(y->down)
                        y = y->down;        
                    y->down = t;
                }
                else
                    L->colhead[k] = t;

                A++;
                L->nums++;
            }
            else
                A++;
        }
    return L->nums;    
}

/*实现十字链表的删除操作：
 *其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
 *del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。
 */
int del_cross_list(PCrossList L, ElemType k)
{
    OLink pre;
    OLink p;
    OLink q;

    int a = 0;
    for (int i = 0; i < L->rows; i++) 
    {
        pre = L->rowhead[i];
        while (pre != NULL) 
        {
            if (pre->value == k) 
            {
                p = L->colhead[pre->col];
                q = L->rowhead[pre->row];
                if (p == pre)
                    L->colhead[pre->col] = pre->down;
                else 
                {
                    while (p->down != pre)
                        p = p->down;
                    p->down = pre->down;
                }

                if (q == pre)
                    L->rowhead[pre->row] = pre->right;
                else 
                {
                    while (q->right != pre)
                        q = q->right;
                    q->right = pre->right;
                }
                OLink t = pre;
                pre = pre->right;
                free(t);
                
                a++;
                L->nums--;
            } 
            else 
            {
                pre = pre->right;
            }
        }
    }
    return a;
}

/*
 *打印十字链表
 */
void PrintCrossList(PCrossList M)
{
    for(int i = 0; i < M->rows; ++i)
        for (OLink p = M->rowhead[i]; p != NULL; p = p->right)
            printf("(%d, %d, %d)\n", p->row, p->col, p->value);
}

/*
 *销毁十字链表
 */
void DestroyCrossList(CrossList *M)
{
    OLNode *p, *q;

    for (int i = 0; i < M->rows; ++i)
    {
        p = M->rowhead[i];
        while (p != NULL)
        {
            q = p;
            p = p->right;
            free(q);
        }
    }

    free(M->rowhead);
    free(M->colhead);
}