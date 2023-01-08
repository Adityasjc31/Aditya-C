#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} Node;

void createTree(Node *tree, int val);
int input();
Node *createNode(int val);
void insert(Node *parent, int val);
void printTree(Node *);

Node *tree = NULL;
void main()
{
    int val, opt;
    do
    {
        printf("*****Menu*****\n1 - Create Binary Tree\n2 - Display\n(-1) - Exit\n\nEnter your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter number of elements : ");
            scanf("%d", &val);
            createTree(tree, val);
            break;

        case 2:
            printTree(tree);
            break;
        default:
            break;
        }
    } while (opt != -1);
}

void createTree(Node *tree, int elems)
{
    int newval = input();
    if (tree == NULL)
    {
        Node *node = createNode(newval);
        tree = node;
        elems--;
        if (elems > 0)
        {
            createTree(tree, elems);
        }
    }
    else if (elems > 1)
    {
        insert(tree, newval);
        elems--;
        createTree(tree, elems);
    }
}

void insert(Node *parent, int val)
{
    if (parent == NULL)
    {
        return;
    }

    if (parent->data > val)
    {
        if (parent->left == NULL)
        {
            parent->left = createNode(val);
        }
        else
        {
            insert(parent->left, val);
        }
    }
    else
    {
        if (parent->right == NULL)
        {
            parent->right = createNode(val);
        }
        else
        {
            insert(parent->right, val);
        }
    }
}

int input()
{
    int val;
    printf("Enter an element : ");
    scanf("%d", &val);
    return val;
}

Node *createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(Node *tree)
{
    if (tree != NULL)
    {
        printf("%d->", tree->data);
        printTree(tree->left);
        printTree(tree->right);
    }
}