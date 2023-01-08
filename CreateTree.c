#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};
struct Tree *insertTree(int data, struct Tree *tr);
void printTree(struct Tree *tr, int level);
void main()
{
    struct Tree *tree = NULL;
    int data;
    while (1)
    {
        printf("\nKey to insert|");
        scanf("%d", &data);
        if (data == 0)
            break;
        tree = insertTree(data, tree);
    }
    printf("\n Tree Display;\n");
    printTree(tree, 1);
}

void printTree(struct Tree *tr, int level)
{
    int i;
    if (tr)
    {
        printTree(tr->right, level + 1);
        printf("\n\n");
        for (i = 0; i < level; i++)
            printf("       ");
        printf("%d", tr->data);
        printTree(tr->left, level + 1);
    }
}

struct Tree *insertTree(int data, struct Tree *tr)
{
    if (tr == NULL)
    {
        tr = (struct Tree *)malloc(sizeof(struct Tree));
        tr->data = data;
        tr->left = NULL;
        tr->right = NULL;
        return tr;
    }

    if (tr->left == NULL)
    {
        tr->left = insertTree(data, tr->left);
        return tr;
    }

    if (tr->right == NULL)
    {
        tr->right = insertTree(data, tr->right);
        return tr;
    }

    if (tr->left == NULL)
    {
        tr->left = insertTree(data, tr->left);
    }
    else
    {
        tr->right = insertTree(data, tr->left);
    }
    return tr;
}
// {
//     if (tr==NULL)
//     {
//         tr=(struct Tree*)malloc(sizeof(struct Tree));
//         tr->data = data;
//         tr->left = NULL;
//         tr->right = NULL;
//         return tr;
//     }

//     if (data < tr->data)
//     {
//         tr->left = insertTree(data,tr->left);
//     }
//     else
//     {
//         tr->right = insertTree(data,tr->right);
//     }
//     return tr;
// }