#pragma once

#include <stdbool.h>

//tree
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

#define MAX_CHILDREN_NUM 5
struct _CSNode
{
    DataType data;
    struct _CSNode *children[MAX_CHILDREN_NUM];
//其中，子树的根节点的指针存放在children数组的前k个元素中，即如果children[i]的值为NULL，而children[i-1]不为NULL，则表明该结点只有i棵子树，子树根结点分别保存在children[0]至children[i-1]中。
};
typedef struct _CSNode CSNode;

void visit_node(BiTNode *node);
void CreateBiTree(BiTree *root, const DataType *p);
void DestroyBiTree(BiTree root);
void pre_order(BiTree root);
BiTNode* nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q);
BiTNode* transform(CSNode *root);

//stack
#define Stack_Size 50

typedef BiTNode* ElemType;
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
}Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false
bool path(BiTNode* root, BiTNode* node, Stack* s);

//queue
#define Queue_Size 50

struct __Queue
{
    int i, j; //指向数组内元素的游标
    void **array;
};
typedef struct __Queue Queue;

Queue* create_queue(); //创建队列
bool is_empty_queue(Queue *tree); //队为空返回true,不为空时返回false
void* del_queue(Queue *tree); //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree); //释放队列
