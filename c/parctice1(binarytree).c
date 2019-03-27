#include<stdio.h>
#include<stdlib.h>
typedef int Type;    //规定所定义的类型

//结点定义
typedef struct BSTreeNode
{
    Type key;
    struct BSTree *left;
    struct BSTree *right;
    struct BSTree *parent; 
}Node,*BST;

//创建结点
static Node* create_bstree_node(Type key,Node *left,Node *right,Node *parent)
{
    Node *p;
    if(p=(Node*)malloc(sizeof(Node))==NULL) //判断结点是否为空
    {
        return NULL;
    }  
    p->key=key;
    p->left=left;
    p->right=right;
    p->parent=parent;
    return p;
}
//前序遍历,NLR
void preorder_bstree(BST tree)
{
    printf("%d",tree->key);
    preorder_bstree(tree->left);
    preorder_bstree(tree->right);
}

//中序遍历，LNR
void midorder_bstree(BST tree)
{
    midorder_bstree(tree->left);
    printf("%d",tree->key);
    midorder_bstree(tree->right);
}

//后序遍历，LRN
void postorder_bstree(BST tree)
{
    postorder_bstree(tree->left);
    postorder_bstree(tree->right);
    printf("%d",tree->key);
}
