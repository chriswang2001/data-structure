#include "queue.h"
#include "queue_interface.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 *队列 循环链表表示队列
 *假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针）
 */

/*
 *队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue *LQ);
 */
bool init_queue(LinkQueue *LQ)
{
	*LQ = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(*LQ != NULL)
	{
		(*LQ)->next = *LQ;
		return true;
	}
	else
		return false;
}

/*
 *入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue *LQ, ElemType x);
 */
bool enter_queue(LinkQueue *LQ, ElemType x)
{	
	LinkQueueNode* rear;
	rear = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if((rear != NULL))
	{
		rear->data = x;
		rear->next = (*LQ)->next;
		(*LQ)->next = rear;
		*LQ = (*LQ)->next;
		return true;
	}
	else
		return false;
}

/*
 *出队列，成功返回真，且*x为出队的值，否则返回假 bool leave_queue(LinkQueue *LQ, ElemType *x);
 */
bool leave_queue(LinkQueue *LQ, ElemType *x)
{
	LinkQueueNode* front, *head;
	if((*LQ)->next != *LQ)
	{	
		head = (*LQ)->next;
		front = head->next;
		head->next = front->next;
		if(head->next == head)
			*LQ = head;
		(*x) = front->data;
		free(front);
		return true;
	}
	else
		return false;
}