#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

/*
 *向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
 */
node_t* avl_insert(node_t *root, int val)
{
    node_t* S = (node_t *)malloc(sizeof(node_t));
    S->val = val;
    S->left = S->right = NULL;
    S->height = 0;

    if (root == NULL)
    {
        root = S;
        return S;
    }

    /* 首先查找S的插入位置fp，同时记录距S的插入位置最近且
    平衡因子不等于0（等于-1或1）的结点A，A为可能的失衡结点*/
    node_t* p = root;   node_t* fp = NULL;
    node_t* A = root;   node_t* FA = NULL;

    while (p != NULL)
    {
        if (p->val == val)
        {
            free(S);
            return root;
        }

        if (p->height != 0)
        {
            A = p;
            FA = fp;
        }

        fp = p;
        if (val < p->val)
            p = p->left;
        else
            p = p->right;
    }

    /* 插入S*/
    if (val < fp->val)
        fp->left = S;
    else
        fp->right = S;

    /* 确定结点B，并修改A的平衡因子*/
    node_t *B;
    if (val < A->val)
    {
        B = A->left;
        A->height = A->height + 1;
    }
    else
    {
        B = A->right;
        A->height = A->height - 1;
    }

    /* 修改B到S路径上各结点的平衡因子（原值均为0）*/
    p = B;
    while (p != S)
    {
        if (val < p->val)
        {
            p->height = 1;
            p = p->left;
        }
        else
        {
            p->height = -1;
            p = p->right;
        }
    }

    /* 判断失衡类型并做相应处理 */
    if (A->height == 2 && B->height == 1) /* LL型 */
    {
        A->left = B->right;
        B->right = A;
        A->height = 0;
        B->height = 0;

        if (FA == NULL)
            root = B;
        else if (A == FA->left)
            FA->left = B;
        else
            FA->right = B;

        return root;
    }

    else if (A->height == 2 && B->height == -1) /* LR型 */
    {
        node_t* C = B->right;

        B->right = C->left;
        A->left = C->right;
        C->left = B;
        C->right = A;
        if (S->val < C->val)
        {
            A->height = -1;
            B->height = 0;
            C->height = 0;
        }
        else if (S->val > C->val)
        {
            A->height = 0;
            B->height = 1;
            C->height = 0;
        }
        else
        {
            A->height = 0;
            B->height = 0;
        }

        if (FA == NULL)
            root = C;
        else if (A == FA->left)
            FA->left = C;
        else
            FA->right = C;
        
        return root;
    }

    else if (A->height == -2 && B->height == 1) /* RL型 */
    {
        node_t* C = B->left;
        B->left = C->right;
        A->right = C->left;
        C->left = A;
        C->right = B;
        if (S->val < C->val)
        {
            A->height = 0;
            B->height = -1;
            C->height = 0;
        }
        else if (S->val > C->val)
        {
            A->height = 1;
            B->height = 0;
            C->height = 0;
        }
        else
        {
            A->height = 0;
            B->height = 0;
        }

        if (FA == NULL)
            root = C;
        else if (A == FA->left)
            FA->left = C;
        else
            FA->right = C;

        return root;
    }

    else if (A->height == -2 && B->height == -1) /* RR型 */
    {
        B = A->right;
        A->right = B->left;
        B->left = A;
        A->height = 0;
        B->height = 0;

        if (FA == NULL)
            root = B;
        else if (A == FA->left)
            FA->left = B;
        else
            FA->right = B;

        return root;
    }

    return root;
}

node_t* avl_search(node_t* q, int key)
/*在根指针bst所指二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{

    while (q != NULL)
    {
        if (q->val == key)
            return q; /*查找成功*/
        if (q->val > key)
            q = q->left; /*在左子树中查找*/
        else
            q = q->right; /*在右子树中查找*/
    }
    
    return NULL; /*查找失败*/
} /*SearchBST*/

node_t* CreateFromFile()
{
    FILE *fp;
    fp = fopen(data_file, "r");

    int len, key;

    fscanf(fp, "%d", &len);

    node_t *bst = NULL; 
    for (int i = 0; i < len; ++i)
    {
        fscanf(fp,"%d",&key);
        bst = avl_insert(bst, key);
    }
    
    fclose(fp);

    return bst;
}

void Destroy(node_t *root)
{
    if (root != NULL)
    {
        Destroy(root->left); /*后序遍历左子树*/
        Destroy(root->right); /*后序遍历右子树*/
        free(root);               /*释放结点*/
    }
}

void PreOrder(node_t* root)
{
    if (root == NULL) 
    {
        printf(" . ");
        return;
    }

    printf("%2d-%d", root->val,root->height);
    PreOrder(root->left);
    PreOrder(root->right);
}