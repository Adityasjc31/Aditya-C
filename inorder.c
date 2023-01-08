#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    struct tree *left;
    int data;
    struct tree *right;
} TreeNode;

TreeNode *stack = NULL;
int size;
void stackUp(int);
void push(TreeNode *);
void main()
{
    int size;
    printf("Enter size of the array : ");
    scanf("%d",&size);
    stackUp(size);

}

void stackUp(int s)
{
    size = s;
    stack = (TreeNode *)malloc(sizeof(TreeNode) * size);
}
