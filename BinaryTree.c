#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;
Node *create(int data);
void display(Node *);
Node *root = NULL;

void insert(Node *ptr, int data, int level)
{
    if (root == NULL)
    {
        root = create(data);
        return;
    }

    if (ptr->left == NULL)
    {
        ptr->left = create(data);
        return;
    }

    if (ptr->right == NULL)
    {
        ptr->right = create(data);
        return;
    }

    if (level == 0)
    {
        level = (int)pow(2, level + 1);
        insert(ptr->left, data, level);
    }
    else
    {
        insert(ptr->right, data,level);
    }
}

int main()
{
    // char val[100];
    // gets(val);
    // puts(val);
    // for (size_t i = 0; i < len(); i++)
    // {
    //     if()
    //     {}
    // }

    // // printf("\n");
    // // display(root);
    // // getdepth(0,0,root);
    // // printf("%d",maxdepth);
    return 0;
}

Node *create(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}
void display(Node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        display(temp->left);
        display(temp->right);
    }
}