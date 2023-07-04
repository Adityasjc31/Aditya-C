#include<stdio.h>
#include "insertIntree.c"

Node *root=NULL;
void printLevel(Node *node,int level);
int Height(Node *tree);
void main()
{
    root = insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
}

void printLevel(Node *node, int level)
{
    if (node  == NULL)
    {
        return ;
    }

    if (level == 1)
    {
        printf("%d",node->data);
    }
    else
    {
        printLevel(node->left,level-1);
        printLevel(node->right,level-1);
    }
}

int Height(Node *tree)
{
    int leftHeight,rightHeight;
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        leftHeight = Height(tree->left);
        rightHeight = Height(tree->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight+1;
        }
        else
        {
            return rightHeight+1;
        }
    }
}