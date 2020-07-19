#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

/*
 *顺序表 删除指定范围
 *设计一个高效的算法，从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素（假设y>=x），
 *要求时间复杂度为O(n)，空间复杂度为O(1)。
 *函数原型如下：
 *void del_x2y(SeqList *L, ElemType x, ElemType y);
 */
void del_x2y(SeqList* L, ElemType x, ElemType y)
{
    for (int j = 0; j <= L->last;)
     {
        if (L->elem[j] >= x && L->elem[j] <= y) 
        {
            for (int i = j; i < L->last; i++) 
            {
                L->elem[i] = L->elem[i + 1];
            }
            L->last -= 1;
        } else
            j++;
    }
}
/*
void del_x2y(SeqList* L, ElemType x, ElemType y)
{
    int i, n = 0;
    for (i = 0; i <= (*L).last; i++) 
    {
        if (!((*L).elem[i] >= x && (*L).elem[i] <= y))
            (*L).elem[n++] = (*L).elem[i];
    }
    (*L).last = n - 1;
}
*/

/*顺序表 删除重复
 *编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。
 要求时间复杂度为O(n)，空间复杂度为O(1)。
 *函数原型如下：
 *void del_dupnum(SeqList *L)
 */
void del_dupnum(SeqList* L)
{
    for (int j = 0; j <= L->last; j++) 
    {
        for (int i = j + 1; i <= L->last;) 
        {
            if (L->elem[i] == L->elem[j]) 
            {
                for (int k = i; k < L->last; k++) 
                {
                    L->elem[k] = L->elem[k + 1];
                }
                L->last--;
            } 
            else
                i++;
        }
    }
}

/*顺序表 数据调整
 *已知顺序表L中的数据元素类型为int。
 *设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，并要求算法的时间复杂度为O(n),空间复杂度为O（1）。
 *函数原型如下：
 *void odd_even(SeqList *L);
 */
void odd_even(SeqList* L)
{
    for (int j = 0; j < L->last; j++)
        for (int k = 0; k < L->last - j; k++) 
        {
            if ((L->elem[k] % 2) < (L->elem[k + 1] % 2)) 
            {
                int t = L->elem[k];
                L->elem[k] = L->elem[k + 1];
                L->elem[k + 1] = t;
            }
        }
}

/*
void odd_even(SeqList* L)
{
    int i = -1, j;
    int tmp;
    for (j = 0; j <= (*L).last; j++)
    {
        if ((*L).elem[j] % 2 == 1) 
        {
            i++;
            if (i != j) 
            {
                tmp = (*L).elem[i];
                (*L).elem[i] = (*L).elem[j];
                (*L).elem[j] = tmp;
            }
        }
    }
}
*/