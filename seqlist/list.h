#pragma once

#define MAXSIZE 100

typedef int ElemType;

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;


