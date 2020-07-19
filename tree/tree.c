#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void visit_node(BiTNode *node)
{
    printf("%d ",node->data);
}

void pre_order(BiTree root)
{
    Stack s;
    init_stack(&s);

    visit_node(root);
    while(root)
    {
        if(root->left)
            visit_node(root->left);
        if(root->right)
            push(&s, root->right);

        root = root->left;
    }

    while(!is_empty(&s))
    {
        pop(&s, &root);
        visit_node(root);
        while(root)
        {
            if(root->left)
                visit_node(root->left);
            if(root->right)
                push(&s, root->right);
            
            root = root->left;
        }
    }
}

/*
 *已知二叉树按照二叉链表方式存储，利用栈的基本操作写出先序遍历非递归形式的算法：
 *在遍历过程中，pre_order函数需要调用 visit_node 函数来实现对结点的访问
 */
// void pre_order(BiTree root)
// {
//     Stack s;
//     init_stack(&s);

//     push(&s, root);
//     while (!is_empty(&s)) {
//         pop(&s, &root);
//         visit_node(root);
//         if (root->right)
//             push(&s, root->right);
//         if (root->left)
//             push(&s, root->left);
//     }
// }

/*
 *路径
 *编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。
 *其中，root指向二叉树的根结点，node指向二叉树中的另一结点，
 *s 为已经初始化好的栈，该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；如未找到，则函数返回 false, 
 */
bool path(BiTNode* root, BiTNode* node, Stack* s)
{
    BiTree T = root, p = NULL;
    if (T == NULL || node == NULL || !is_empty(s))
        return false;
    while (T || !is_empty(s)) 
    {
        while (T) 
        {
            push(s, T);
            if (T == node)
                return true;
            T = T->left;
        }
        top(s, &T);
        if (!T->right || T->right == p) 
        {
            p = T;
            pop(s, &T);
            T = NULL;
        } 
        else
            T = T->right;
    }
    return false;
}
// bool path(BiTNode* root, BiTNode* node, Stack* s)
// {
//     if(root)
//         push(s, root);
//     else 
//         return false;

//     if(root == node)
//         return true;
//     if(root->left)
//         if(path(root->left, node, s))
//             return true;
//     if(root->right)
//         if(path(root->right, node, s))
//             return true;
        
//     pop(s, &root);
//     return false;    
// }

/*
 *共同祖先
 *假设二叉树采用二叉链表方式存储， root指向根结点，p所指结点和q所指结点为二叉树中的两个结点，
 *编写一个计算它们的最近的共同祖先
 *其中 root 指向二叉树的根结点，p 和 q 分别指向二叉树中的两个结点。
 *提示：在完成本题时，可利用 path 函数获取p和q两个结点到根结点之间的路径，之后再计算两条公共路径得出最近的共同祖先。
 */
BiTNode* nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q)
{
    Stack sp, sq;
    init_stack(&sp);
    init_stack(&sq);
    path(root, p, &sp);
    path(root, q, &sq);

    int i;
    for(i = 0; sp.elem[i] == sq.elem[i]; i++);
    
    return sp.elem[i-1];
}

/*
 *树转二叉树
 *使用队列，编写transfrom函数，将普通树转换成对应的二叉树。
 *其中 root 为普通树的根结点，函数返回该树对应二叉树的根结点。
 */
BiTNode* transform(CSNode* root)
{
    if (root == NULL)
        return NULL;

    //初始化根节点
    BiTree broot = (BiTree)malloc(sizeof(struct Node));
    broot->data = root->data;
    broot->left = broot->right = NULL;

    //普通树、二叉树初始化、加入队列
    Queue* queue = create_queue();
    Queue* bqueue = create_queue();
    add_queue(queue, root);
    add_queue(bqueue, broot);

    //当普通树的队列不为空时
    while (!is_empty_queue(queue)) 
    {
        //从两个队列中分别取出一个结点
        CSNode* node = del_queue(queue);
        BiTree bTreeNode = del_queue(bqueue);

        int i;
        BiTree former = bTreeNode;
        //遍历普通树结点的所有孩子结点，将孩子加入队列
        for (i = 0; i < MAX_CHILDREN_NUM; i++) {
            if (node->children[i]) {
                BiTree bnode = (BiTree)malloc(sizeof(struct Node));
                bnode->left = bnode->right = NULL;
                bnode->data = node->children[i]->data;
                if (i == 0) //普通树的第一个孩子作为二叉树的左孩子
                    bTreeNode->left = bnode;
                else //后面的孩子结点作为前面结点的右孩子
                    former->right = bnode;
                former = bnode;

                add_queue(queue, node->children[i]);
                add_queue(bqueue, bnode);
            }
        }
    }
    free(queue->array);
    free(queue);
    free(bqueue->array);
    free(bqueue);
    return broot;
}
// BiTNode* transform(CSNode *root)
// {
//     static BiTree t;
//     if(root)
//     {   
//         t = (BiTNode*)malloc(sizeof(BiTNode));
//         t->data = root->data;
//         t->left = NULL;
//         t->right = NULL;
//     }
//     else
//         return NULL;

//     Queue *p, *q;
//     p = create_queue();
//     q = create_queue();

//     static BiTNode* pre;
//     if (root->children[0]) 
//     {
//         pre = (BiTNode*)malloc(sizeof(BiTNode));
//         pre->data = root->children[0]->data;
//         pre->left = NULL;
//         pre->right = NULL;

//         t->left = pre;
//         add_queue(p, root->children[0]);
//         add_queue(q, pre);
//     }

//     static BiTNode* cur;
//     for (int i = 1; root->children[i]; i++) 
//     {
//         cur = (BiTNode*)malloc(sizeof(BiTNode));
//         cur->data = root->children[i]->data;
//         cur->left = NULL;
//         cur->right = NULL;

//         pre->right = cur;
//         pre = cur;
//         add_queue(p, root->children[i]);
//         add_queue(q, cur);
//     }

//     while (!is_empty_queue(p) && !is_empty_queue(q)) 
//     {
//         CSNode* m = del_queue(p);
//         BiTNode* n = del_queue(q);
//         *n = *(transform(m));
//     }

//     return t;
// }

void CreateBiTree(BiTree *root, const DataType *p)
{
    static int i = 0;

    if (p[i] == -1)
    {
        *root = NULL;
        ++i;
    }
    else
    {
        *root = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*root)->data = p[i++];
        CreateBiTree(&((*root)->left), p); //生成左子树
        CreateBiTree(&((*root)->right), p); //生成右子树
    }
}

void DestroyBiTree(BiTree root)
{
	if (root == NULL) return;
	
	DestroyBiTree(root->left); /*后序遍历左子树*/
	DestroyBiTree(root->right); /*后序遍历右子树*/
	free(root);					 /*释放结点*/
}