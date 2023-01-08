#include <stdio.h>
#include <stdlib.h>
int size;
int *ar = NULL;
int front = -1, rear = -1;
void enqueue(int val);
int dequeue();
void display();
void main()
{
    int x, val, ch = 0;
    printf("Enter size of queue : ");
    scanf("%d", &size);

    ar = (int *)malloc(size * sizeof(int));
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
    if ((rear < (size - 1) && front == -1) || (front != rear && front > -1))
    {
        rear++;
        if (rear == size)
        {
            rear = 0;
        }
        ar[rear] = val;
    }
    else
    {
        printf("Queue is Full\n");
    }
}

int dequeue()
{
    if (!(front == -1 && rear == -1))
    {
        front++;
        if (front == size)
        {
            front = 0;
        }
        int v = ar[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        return v;
    }
    else
    {
        printf("Queue Empty\n");
        return -1;
    }
}

void display()
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
    printf("\n");
}