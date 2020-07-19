#pragma once

#include "queue.h"
#include <stdbool.h>

extern bool init_queue(LinkQueue *LQ);
extern bool enter_queue(LinkQueue *LQ, ElemType x);
extern bool leave_queue(LinkQueue *LQ, ElemType *x);