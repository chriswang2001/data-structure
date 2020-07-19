#pragma once

#include <stdbool.h>

#define MAXSIZE 10  /*队列的最大长度*/

typedef int ElemType;

typedef struct _QueueNode {
    ElemType data;          /*数据域*/
    struct _QueueNode *next;      /*指针域*/
}LinkQueueNode, *LinkQueue;