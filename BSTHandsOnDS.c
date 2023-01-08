#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} TreeNode;

TreeNode *root = NULL, *new;
void createNode(int);
void insert(TreeNode *node, int);
void display(TreeNode *);
void main()
{
    int size, x, val;
    scanf("%d", &size);
    for (x = 0; x < size; x++)
    {
        scanf("%d", &val);
        createNode(val);
    }

    display(root);
}

void createNode(int data)
{
    new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = data;
    new->right = new->left = NULL;
    if (root == NULL)
    {
        root = new;
    }
    else
    {
        insert(root, data);
    }
}

void insert(TreeNode *node, int data)
{
    if (node->left == NULL)
    {
        node->left = new;
        return ;
    }

    if (node->right == NULL && node->data < data)
    {
        node->right = new;
        return ;
    }

    if (node->data < data)
    {
        insert(node->right,data);
        return ;
    }
    else
    {
        insert(node->left,data);
    }
}

void display(TreeNode *node)
{
    if (node != NULL)
    {
        display(node->left);
        printf("%d ", node->data);
        display(node->right);
    }
}