#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

/*链表 删除范围内结点
 *已知线性表中的元素（整数）以值递增有序排列，并以单链表作存储结构。
 *试写一高效算法，删除表中所有大于mink且小于maxk的元素（若表中存在这样的元素），分析你的算法的时间复杂度。
 *链表结点定义如下：
 *struct _lnklist{
    ElemType data;
    struct _lnklist *next;
 *};
 *typedef struct _lnklist Node;
 *typedef struct _lnklist *LinkList;
 *函数原型如下：
 *void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
 *其中L指向链表的头结点。
 */

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    Node* p;
    p = L->next;

    while (p->next->data <= mink) 
    {
        p = p->next;
    }

    Node* q = p->next;
    while (q->data < maxk) 
    {
        p->next = q->next;
        free(q);
        q = p->next;
    }
}

/*链表 倒数查找
 *已知一个带有表头结点的单链表, 假设链表只给出了头指针L。
 *在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数）。
 *函数原型为：int lnk_search(LinkList L, int k, ElemType* p_ele)
 *若查找成功，函数通过指针参数 p_ele 返回该结点 data 域的值，此时函数返回 1；否则，函数返回 0。相关定义如下：
 *struct _lnklist{
    ElemType data;
    struct _lnklist *next;
 *};
 *typedef struct _lnklist Node;
 *typedef struct _lnklist *LinkList;
 */

int lnk_search(LinkList L, int k, ElemType* p_ele)
{
    Node *p = L, *q = L;

    for (int i = 0; i < k && p->next != NULL;i++)
        p = p->next;
    
    if(p->next == NULL)
        return 0;
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        *p_ele = q->data;
        return 1;
    }
}

/*链表 合并
 *设线性表A=(a1, a2,…,am)，B=(b1, b2,…,bn)，试写一个按下列规则合并A、B为线性表C的算法，使得：
 *C= (a1, b1,…,am, bm, bm+1, …,bn) 当m≤n时；
 *或者
 *C= (a1, b1,…,an, bn, an+1, …,am) 当m>n时。
 *线性表A、B、C均以单链表作为存储结构，且C表利用A表和B表中的结点空间构成。注意：单链表的长度值m和n均未显式存储。
 *函数的原型如下：
 *void lnk_merge(LinkList A, LinkList B, LinkList C)
 *即将A和B合并为C，其中 C 已经被初始化为空单链表
 *相关定义如下：

 *struct _lnklist{
    ElemType data;
    struct _lnklist *next;
 *};
 *typedef struct _lnklist Node;
 *typedef struct _lnklist *LinkList;
 */

void lnk_merge(LinkList A, LinkList B, LinkList C)
{

    Node *LA = A, *LB = B, *r = C;
    LA = LA->next;
    LB = LB->next;
    
    while (LA && LB) 
    {
        r->next = LA;
        r = LA;
        LA = LA->next;

        r->next = LB;
        r = LB;
        LB = LB->next;
    }
    r->next = LA ? LA : LB;
}