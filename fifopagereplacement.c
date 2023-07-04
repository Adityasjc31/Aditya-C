#include <stdio.h>
#include <stdlib.h>
int pagefault = 0;
void printArray(int *ar, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
    printf("\n");
}
int search(int *ar, int size, int elem)
{
    int x;
    for (x = 0; x < size; x++)
    {
        if (ar[x] == elem)
        {
            return x;
        }
    }
    return -1;
}
void fifo(int *refstring, int size, int pageframe)
{
    int *queue = (int *)malloc(sizeof(int) * pageframe);
    int front = 0;
    int rear = -1;
    int found = -2;
    int x;
    for (x = 0; x < size; x++)
    {
        if (front == pageframe)
        {
            front = 0;
            x--;
            continue;
        }

        found = search(queue, pageframe, refstring[x]);
        if (found == -1 && rear < (pageframe - 1))
        {
            queue[++rear] = refstring[x];
            pagefault++;
        }
        else if (found == -1)
        {
            rear = - 1;
            front++;
            x--;
            continue;
        }
        // printf("Reference String : %d\n", refstring[x]);
        // printf("Queue : ");
        // printArray(queue, pageframe);
        // printf("Page Fault Count : %d\n", pagefault);
    }
}
void main()
{
    int reflen, *refstring = NULL, pageframe, x;
    // reflen = 12;
    // pageframe = 4;
    printf("Enter reference string length : ");
    scanf("%d",&reflen);
    printf("Enter page frame size : ");
    scanf("%d",&pageframe);

    refstring = (int *)malloc(sizeof(int) * reflen);
    printf("Enter reference string = ");
    for (x = 0;x < reflen;x++)
    {
        scanf("%d",&refstring[x]);
    }
    // refstring[0] = 1;
    // refstring[1] = 2;
    // refstring[2] = 3;
    // refstring[3] = 4;
    // refstring[4] = 1;
    // refstring[5] = 2;
    // refstring[6] = 5;
    // refstring[7] = 1;
    // refstring[8] = 2;
    // refstring[9] = 3;
    // refstring[10] = 4;
    // refstring[11] = 5;
    fifo(refstring, reflen, pageframe);
    printf("Page Faults : %d", pagefault);
}