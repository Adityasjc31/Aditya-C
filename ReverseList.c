#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *start = NULL,*end = NULL;

Node * create(int data);
void insert(int);
Node* reverse();

Node * create(int data)
{
    Node *new  = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert(int data)
{
    if(start == NULL)
    {
        start = create(data);
        end = start;
    }
    else
    {
        end->next = create(data);
        end = end->next;
    }
}

void display(Node *PTR)
{
    Node *ptr = PTR;
    printf("\n[");
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        if(ptr->next != NULL)
        {
            printf("->");
        }
        ptr = ptr->next;
    }
    printf("]\n");
}

void main()
{
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(11);

    display(start);
    Node *rev =  reverse();
    display(rev);
}

Node * reverse()
{
    Node *prev = NULL,*current = start,*next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}