#pragma once
#include "list.h"

extern void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk);
extern int lnk_search(LinkList L, int k, ElemType* p_ele);
extern void lnk_merge(LinkList A, LinkList B, LinkList C);

