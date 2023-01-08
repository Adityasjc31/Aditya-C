#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
}Node;
Node *start,*temp,*newptr;
Node * create();
void display(Node *);
void ins(Node *);
void main()
{
    int ch;
    start = NULL;
    do
    {
        printf("Menu\n1 - Create a node\n2 - Insert an element\n3 - Display\n(-1) - Exit\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            newptr = create();
            break;
        
        case 2:
            ins(newptr);
            break;
        
        case 3:
            display(start);
            break;

        default:
            printf("Wrong Choice");
        }
    } while (ch != -1);
}

Node * create()
{
    int val;
    Node *ptr = (Node *)malloc(sizeof(Node));
    printf("Enter any number : ");
    scanf("%d",&val);
    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}

void ins(Node *ptr)
{
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        temp = start;
        start = ptr;
        ptr->next = temp;
    }
}

void display(Node *ptr)
{
    temp = ptr;
    printf("[ ");
    while(temp != NULL)
    {
        printf("%d",temp->val);
        if(temp->next!=NULL)
        {
            printf("->");
        }
        temp = temp->next;
    }
    printf(" ]");
}