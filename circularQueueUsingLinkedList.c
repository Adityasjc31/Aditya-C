#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *current=NULL;
struct Node *tail=NULL;
int size,count=0;
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
            if (val != -1)
                printf("Element deleted is : %d", val);
            break;
        case 3:
            display();
            break;
        }
        printf("\n");
    }
}

void enqueue(int val)
{
    if(count == size)
    {
        printf("Queue Full");
        return ;
    }
    current = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL || count ==0)
    {
        current->next=NULL;
        current->data=val;
        head = current;
        tail = current;
    }
    else
    {
        current->next=NULL;
        current->data=val;
        tail->next = current;
        tail = tail->next;
    }
    count++;

    if (count == size)
    {
        tail->next = head;
    }   
}

int dequeue()
{
    if (count==0)
    {
        printf("Queue Empty");
        return -1;
    }
    
    int ret = head->data;
    head=head->next;
    tail->next = head;
    count--;
    return ret;
}

void display()
{
    struct Node *ptr = head;
    int c=0;
    printf("\n[ ");
    while (ptr != NULL && c<size)
    {
        c++;
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}