#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

void insert(int data);
struct Tree *root,*current;
void main()
{
    int level = 0, x, size = 0, temp;
    printf("Enter levels for a tree : ");
    scanf("%d", &level);
    printf("Enter elements of the tree : ");

    for (x = level - 1; x >= 0; x--)
    {
        size = size + pow(2, x);
    }
    printf("%d\n", size);
    
    for (x = 0; x < size; x++)
    {
        current = root;
        printf("Enter element : ");
        scanf("%d", &temp);
        insert(temp);
        
    }
}

void insert(int data)
{
    if (current == NULL)
    {
        struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else if (current->left == NULL)
    {
        struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root->left = temp;
    }
    else if (current->right == NULL)
    {
        struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root->right = temp;
    }
    else
    {
        current = current->left;
        insert(data);
        current = current->right;
        insert(data);
    }
}