#include<stdio.h>
#include<stdlib.h>
typedef int Type;

typedef struct BSTreeNode
{
    Type    key;
    struct  BSTreeNode *left;
    struct  BSTreeNode *right;
    struct  BSTreeNode *parent;
}Node,*BSTree;

//创建结点的代码
static Node* create_bstree_node(Type key,Node *parent,Node *left,Node *right)
{
    Node* p;
    if((p=(Node*)malloc(sizeof(Node)))==NULL)
    {
        return NULL;
    }
    p->key = key;
	p->left = left;
	p->right = right;
	p->parent = parent;
	return p;
}

//前序遍历
void preorder_bstree(BSTree tree)
{
    if(tree!=NULL)
    {
        printf("%d",tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

//查找
Node* bstree_search(BSTree x,Type key)
{
    if(x==NULL||x->key==key)
    {
        return x;
    }
    if(key<x->key)
    {
        return bstree_search(x->left,key);
    }
    else
    {
        return bstree_search(x->right,key);
    }    
}

Node* bstree_maximum(BSTree tree)
{
    if(tree==NULL)
    {
        reutrn NULL;
    }
    while(tree->right!=NULL)
    {
        tree=tree->right;
    }
    return tree;
}

static Node* bstree_insert(BSTree tree,Node *z)
{
    Node *y=NULL;
    Node *x=tree;

    //查找z的插入位置
    while(x!=NULL)
    {
        y=x;
        if()
    }
}