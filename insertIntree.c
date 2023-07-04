#include <stdio.h>
#include "Node.c"
int INSERTED = 0;
Node *block(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}

Node *insert(Node *node, int elem)
{
    if (node == NULL)
    {
        return block(elem);
    }
    else if (node->left == NULL)
    {
        node->left = insert(node->left, elem);
    }
    else if (node->right == NULL)
    {
        node->right = insert(node->right, elem);
    }

    
}