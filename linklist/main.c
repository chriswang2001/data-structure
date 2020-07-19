#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "list_interface.h"

void InitList(LinkList *L)
{
    (*L) = (Node*)malloc(sizeof(Node)); //生成头结点
    (*L)->next = NULL; //头结点的指针域为空
}

bool InsList(LinkList L, int i, ElemType e)
{
	Node* p = L->next;
    Node* q;
	int k = 1;
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != L && k < i)  /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == L && k < i)   /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return false;
	}

	q = (Node*)malloc(sizeof(Node));   /*申请一个新的结点S */
	q->data = e;                       /*值e置入s的数据域*/
	q->next = p->next;				/*修改指针，完成插入操作*/
	p->next = q;
	
    return true;
}

void print(LinkList L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    putchar('\n');
}

int main()
{
    LinkList L;
    InitList(&L);

    for (int i = 1; i < 10; ++i)
        InsList(L, i, (i+10-2)*5);
    print(L);
    
    int a;
    lnk_search(L, 3, &a);
    printf("%d",a);
    print(L);

    return 0;
}
