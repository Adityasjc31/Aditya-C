#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);
void main()
{
    int opt, val;
    struct node *ptr;
    create_tree(tree);
    do
    {
        printf("\n******MAIN MENU******\n1 - Insert Element\n2 - Preorder Traversal\n3 - Inorder Traversal\n4 - Postorder\n5 - Find the smallest element\n6 - Find the largest element\n7 - Delete an element\n8 - Count the total number of nodes\n9 - Count the total number of external nodes\n10 - Count the total number of internal nodes\n11 - Determine the height of tree\n12 - Find the mirror image of the tree\n13 - Delete the tree\n14 - Exit\n\nEnter your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the value of the new node : ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        case 2:
            printf("\nThe elements of the tree are : \n");
            preorderTraversal(tree);
            break;
        case 3:
            printf("\nThe elements of the tree are : \n");
            inorderTraversal(tree);
            break;

        case 4:
            printf("\nThe elements of the tree are : \n");
            postorderTraversal(tree);
            break;

        case 5:
            ptr = findSmallestElement(tree);
            printf("\nSmallest element is : %d", ptr->data);
            break;

        case 6:
            ptr = findLargestElement(tree);
            printf("\nLargest element is : %d", ptr->data);
            break;

        case 7:
            printf("\nEnter the element to be deleted : ");
            scanf("%d", &val);
            tree = deleteElement(tree, val);
            break;

        case 8:
            printf("\nTotal number of nodes = %d", totalNodes(tree));
            break;

        case 9:
            printf("\nTotal number of external nodes = %d", totalExternalNodes(tree));
            break;

        case 10:
            printf("\nTotal number of internal nodes = %d", totalInternalNodes(tree));
            break;

        case 11:
            printf("\nThe height of the tree = %d", Height(tree));
            break;

        case 12:
            tree = mirrorImage(tree);
            break;

        case 13:
            tree = deleteTree(tree);
            break;
        }
    } while (opt != 14);
}

void create_tree(struct node *tree)
{
    tree = NULL;
}

struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

void preorderTraversal(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d\t",tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d",tree->data);
        inorderTraversal(tree->right);
    }
    
}

void postorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d",tree->data);
    }
}

struct node *findSmallestElement(struct node *tree)
{
    if(tree == NULL || tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return findSmallestElement(tree->left);
    }
}

struct node *findLargestElement(struct node *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return tree;
    }
    else
    {
        return findLargestElement(tree->right);
    }
}

struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur,*parent,*suc,*psuc,*ptr;
    if (tree->left == NULL)
    {
        printf("\nThe tree is empty");
        return tree;
    }

    parent = tree;
    cur = tree->left;
    while (cur != NULL && val!=cur->data)
    {
        parent = cur;
        cur = (val<cur->data) ? cur->left : cur->right;
    }

    if (cur == NULL)
    {
        printf("\nThe value to be deleted is not present in the tree");
        return tree;
    }

    if (cur->left == NULL)
    {
        ptr = cur->right;
    }
    else if(cur->right == NULL)
    {
        ptr = cur->left;
    }
    else
    {
        psuc = cur;
        cur = cur->left;
        while (suc->left != NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        
        if (cur == psuc)
        {
            suc->left = cur->right;
        }
        else
        {
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }

    if (parent->left == cur)
    {
        parent->left = ptr;
    }
    else
    {
        parent->right = ptr;
    }
    free(cur);
    return tree;
}

struct node *mirrorImage(struct node *tree)
{
    struct node *ptr;
    if (tree != NULL)
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}

int totalNodes(struct node * tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return totalNodes(tree->left) + totalNodes(tree->right) + 1;
    }
}

int totalExternalNodes(struct node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if(tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    else
    {
        return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
    }
    
}

int totalInternalNodes(struct node *tree)
{
    if(tree == NULL || (tree->left == NULL && tree->right == NULL))
    {
        return 0;
    }
    else
    {
        return totalInternalNodes(tree->left) + totalInternalNodes(tree->right);
    }
}

int Height(struct node *tree)
{
    int leftheight,rightheight;
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if (leftheight > rightheight)
        {
            return (leftheight + 1);
        }
        else
        {
            return (rightheight + 1);
        }
    }
}

struct node *deleteTree(struct node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}