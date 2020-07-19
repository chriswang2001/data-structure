#pragma once

#include <stdbool.h>
#define MAX_VERTEX_NUM 20

typedef int VertexType;

typedef enum
{
    DG, UDG, UNDEFINED
}GraphType;

typedef struct OtherInfo
{
    // int weight;
}InfoPtr;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr* info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode;

typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
bool del_vertex(ListGraph *G, VertexType v); 
void CreateGraph(ListGraph *G);
void DestroyGraph(ListGraph *G);
void DrawGraph(ListGraph *G);
