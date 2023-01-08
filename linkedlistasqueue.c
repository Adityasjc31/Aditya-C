#include <stdio.h>
#include <stdlib.h>
int size = 0, c = 0;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *current = NULL;
struct Node *tail = NULL;

void enqueue(int val);
int dequeue();
void display();
void main()
{
    int x, val, ch = 0;
    printf("Enter size of queue : ");
    scanf("%d", &size);
    while (ch > -1)
    {
        printf("Menu\n1 - Add\n2 - Delete\n3 - Display\n(-1) - Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if(val!=-1)
                printf("Element deleted is : %d", val);
            break;
        case 3:
            display();
            break;
        }
    }
}

void enqueue(int val)
{
    if (c == size)
    {
        printf("Queue is full");
        return;
    }
    current = (struct Node *)malloc(sizeof(struct Node));
    // printf("In Enqueue");
    if (head == NULL)
    {
        current->data = val;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else
    {
        current->next = NULL;
        current->data = val;
        tail->next = current;
        tail = tail->next;
    }
    c++;
}

void display()
{
    struct Node *ptr = head;
    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}

int dequeue()
{
    if (head == NULL)
    {
        printf("UnderFlow");
        return -1;
    }
    int val = head->data;
    head = head->next;
    return val;
}