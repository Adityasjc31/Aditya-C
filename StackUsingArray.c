#include <stdio.h>
#include <stdlib.h>
int size = 0, top = -1;
int *ar = NULL;
void push(int val)
{
    if (top == size)
    {
        printf("Stack OverFlow\n");
    }
    else
    {
        ar[++top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack UnderFlow\n");
        return -1;
    }
    else
    {
        return ar[top--];
    }
}

int peek()
{
    return ar[top];
}

void main()
{
    int ch = 0, val;
    printf("Enter size of stack : ");
    scanf("%d", &size);

    ar = (int *)malloc(size * sizeof(int));
    while (ch != -1)
    {
        printf("Menu\n1 - Add Element\n2 - Delete Element\n3 - Get Last Element\n(-1) - To Exit\n");
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
        }

        printf("\n");
    }
}