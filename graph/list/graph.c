#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/*
 *返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
 */
int locate_vertex(ListGraph* G, VertexType v)
{
    for(int i = 0; i < G->vexnum; i++)
    {
        if(v == G->vertex[i].data)
            return i;
    }

    return -1;
}

bool insert_vertex(ListGraph *G, VertexType v)
{
    if(locate_vertex(G, v) != -1)
        return false;
    if(++G->vexnum > MAX_VERTEX_NUM)
        return false;
    
    G->vertex[G->vexnum-1].data = v;
    G->vertex[G->vexnum-1].firstarc = NULL;

    return true;
}

bool insert_arc(ListGraph *G, VertexType v, VertexType w)
{
    int i = locate_vertex(G, v);
    if(i == -1 || locate_vertex(G, w) == -1)
        return false;
    
    ArcNode* p = G->vertex[i].firstarc;
    while(p->nextarc != NULL && p->nextarc->adjvex != w)
    {
        p = p->nextarc;
    }

    if(p->nextarc->adjvex == w)
        return false;
    else
    {
        p->nextarc->adjvex = w;
        p->nextarc->nextarc = NULL;

        G->arcnum ++;
    }

    return true;
}

bool del_vertex(ListGraph *G, VertexType v)
{
    int i = locate_vertex(G, v);
    if(i == -1)
        return false;

    ArcNode *p, *q;
    p = G->vertex[i].firstarc;
    while (p != NULL)
    {
        q = p;
        p = p->nextarc;
        free(q);
        G->arcnum --;
    }

    G->vexnum --;

    for(int j = i; j < G->vexnum; j++) 
        G->vertex[j] = G->vertex[j+1];
    
    
    for(int k = 0; k < G->vexnum; k++)
    {
        p = G->vertex[k].firstarc;

        if(p != NULL)
        {
            if(p->adjvex == i)
            {
                G->vertex[k].firstarc = p->nextarc;
                free(p);
                G->arcnum --;
                p = G->vertex[k].firstarc;
            }
            else if(p->adjvex > i)
                p->adjvex --;
            else
            {
                q = p->nextarc;
                while(q != NULL)
                {   
                    if(q->adjvex == i)
                    {
                        p->nextarc = q->nextarc;
                        free(q);
                        G->arcnum --;
                    }
                    else if(q->adjvex > i)
                        q->adjvex--;
                    p = p->nextarc;
                    if(p != NULL)
                        q = p->nextarc;
                    else
                        break;
                }
            }
        }
    }
    return true;
}

void CreateGraph(ListGraph *G)
{
    scanf("%d %d %d", &G->type, &G->vexnum, &G->arcnum); 
    getchar();

    for (int i = 0; i < G->vexnum; ++i)
    {
        scanf("%d", &G->vertex[i].data);
        G->vertex[i].firstarc = NULL; 
    }
    getchar();

    VertexType v1, v2;
    for (int k = 0; k < G->arcnum; ++k)
    {
        scanf("%d %d", &v1, &v2); 
        getchar();

        int i = locate_vertex(G, v1); 
        int j = locate_vertex(G, v2); 
        ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
        arc->adjvex = j;
        arc->nextarc = G->vertex[i].firstarc; 
        // arc->info.weight = w;
        G->vertex[i].firstarc = arc;
    }
}

void DestroyGraph(ListGraph *G)
{
    ArcNode *p, *q;

    for (int i = 0; i < G->vexnum; ++i)
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            q = p;
            p = p->nextarc;
            free(q);
        }
    }

    G->arcnum = G->vexnum = 0;
    G->type = UNDEFINED;
}

void DrawGraph(ListGraph *G)
{
    ArcNode *p;

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%2d |%2d : ", i, G->vertex[i].data); 
        p = G->vertex[i].firstarc;
        if (p == NULL)
            printf("^");
        else
            while (p != NULL)
            {
                printf("--> %d(%d) ", p->adjvex, G->vertex[p->adjvex].data); 
                p = p->nextarc;                                            
            }
        putchar('\n');
    }
}
