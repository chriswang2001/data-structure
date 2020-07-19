#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

/*
 *返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
 */
int matrix_locate_vertex(MatrixGraph *MG, VertexType vex)
{
    for(int i = 0; i < MG->vexnum; i++)
    {
        if(vex == MG->vertex[i])
            return i;
    }

    return -1;
}

/*图中插入顶点
 *当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
 */
bool matrix_insert_vertex(MatrixGraph *G, VertexType v)
{
    if(matrix_locate_vertex(G, v) != -1)
        return false;
    if(G->vexnum == MAX_VERTEX_NUM)
        return false;

    G->vertex[G->vexnum] = v;
    for(int i = 0; i <= G->vexnum; i++)
        G->arcs[i][G->vexnum] = 0;
    for(int i = 0; i <= G->vexnum; i++)
        G->arcs[G->vexnum][i] = 0;
    G->vexnum ++;

    return true;
}

/*图中插入边
 *当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
 */
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w)
{
    int vn, wn;
    vn = matrix_locate_vertex(G, v);
    wn = matrix_locate_vertex(G, w);
    
    if(vn == -1 || wn == -1)
        return false;
    
    if(G->arcs[vn][wn] == 1)
        return false;

    G->arcs[vn][wn] = 1;
    G->arcnum ++;
    if(G->type == UDG)
        G->arcs[wn][vn] = 1;
    return true;
}

/*
 *创建图
 */
void CreateGraph(MatrixGraph *G) 
{
    scanf("%d %d %d", &G->type, &G->vexnum, &G->arcnum);
    getchar();

    for (int i = 0; i < G->vexnum; i++)         
        for (int j = 0; j < G->vexnum; j++)
            G->arcs[i][j] = 0;

    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%d", &G->vertex[i]); 
    }
    getchar();

    VertexType v1, v2;
    for (int k = 0; k < G->arcnum; k++)
    {
        scanf("%d %d", &v1, &v2); 
        getchar();
        int i = matrix_locate_vertex(G, v1);
        int j = matrix_locate_vertex(G, v2);
        G->arcs[i][j] = 1; 
        if (G->type > DG)
            G->arcs[j][i] = 1;
    }
}

/*
 *销毁图
 */
void DestroyGraph(MatrixGraph *G)
{
    for (int i = 0; i < G->vexnum; i++)         
        for (int j = 0; j < G->vexnum; j++)
            G->arcs[i][j] = 0;

    for (int i = 0; i < G->vexnum; i++)
        G->vertex[i] = 0;
    G->vexnum = G->arcnum = 0;
    G->type = UNDEFINED;
}

/*
 *打印图
 */
void DrawGraph(MatrixGraph *G)
{
    putchar(' ');
    for (int i = 0; i < G->vexnum; ++i)
        printf("%4d", G->vertex[i]);
    putchar('\n');

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%d", G->vertex[i]);
        for (int j = 0; j < G->vexnum; ++j)
                printf("%4d", G->arcs[i][j]);
        putchar('\n');
    }
}