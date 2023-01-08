#include <stdio.h>
#include <stdlib.h>
int size = 0, end = 0;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;
struct Node *tail = NULL;

void push(int val)
{
    if (size == end)
    {
        printf("Stack OverFlow");
        return;
    }
    current = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        current->next = NULL;
        // current->prv=NULL;
        current->data = val;
        head = current;
        tail = current;
    }
    else
    {
        current->next = tail;
        current->data = val;
        // tail->prv = tail->next;
        // struct Node *temp = current;
        tail = current;
        // tail = temp;
    }

    end++;
}

void display()
{
    struct Node *ptr = tail;
    printf("\n[");
    while (ptr != NULL)
    {
        printf("%d<-", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

int pop()
{
    if (tail != NULL)
    {
        int val = tail->data;
        tail = tail->next;
        end--;
        return val;
    }
    else
    {
        printf("Stack UnderFlow");
        return -1;
    }
}

int peek()
{
    int val = tail->data;
    return val;
}

void main()
{
    int ch = 0, val;
    printf("Enter size of stack : ");
    scanf("%d", &size);

    while (ch != -1)
    {
        printf("Menu\n1 - Add Element\n2 - Delete Element\n3 - Get Last Element\n4 - Display\n(-1) - To Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            val = pop();
            if (val != -1)
            {
                printf("Deleted Value is  : %d", val);
            }
            break;

        case 3:
            val = peek();
            printf("Last Value is  : %d", val);
            break;

        case 4:
            display();
        default:
            exit(0);
        }
        printf("\n");
    }
}