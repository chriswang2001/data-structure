#pragma once

typedef int ElemType;
 
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;