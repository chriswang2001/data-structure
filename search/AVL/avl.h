#pragma once

#define data_file "./data.in"
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;

node_t* avl_insert(node_t *root, int val);
node_t* avl_search(node_t* q, int key);
node_t* CreateFromFile();
void Destroy(node_t *root);
void PreOrder(node_t* root);