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
int maxElementIndex(int *ar,int size)
{
    int max=0;
    int x=0;
    for (x = 1;x < size;x++)
    {
        if (ar[max]<ar[x])
        {
            max = x;
        }
    }
    return max;
}

void LRU(int *refstring, int size, int pageframe)
{
    int *queue = (int *)malloc(sizeof(int) * pageframe);
    int *age = (int *)malloc(sizeof(int) * pageframe);
    int y = 0,max;
    int rear = -1;
    int found = -2;
    int x;
    for (y = 0; y < pageframe; y++)
    {
        age[y] = 0;
    }
    for (x = 0; x < size; x++)
    {
        found = search(queue, pageframe, refstring[x]);
        for (y = 0; y <pageframe; y++)
        {
            age[y] += 1;
        }
        if (found == -1 && rear < (pageframe - 1))
        {
            max = maxElementIndex(age,pageframe);
            rear = max-1;
            queue[++rear] = refstring[x];
            age[rear]=0;
            pagefault++;
        }
        else if (found == -1)
        {
            max = maxElementIndex(age,pageframe);
            rear=max-1;
            x--;
            continue;
        }
        else
        {
            age[found] = 0;
        }
        // printf("\nReference String : %d\n", refstring[x]);
        // printf("Queue : ");
        // printArray(queue, pageframe);
        // printf("Age Register : ");
        // printArray(age, pageframe);
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
    // refstring[0] = 0;
    // refstring[1] = 2;
    // refstring[2] = 1;
    // refstring[3] = 6;
    // refstring[4] = 4;
    // refstring[5] = 0;
    // refstring[6] = 1;
    // refstring[7] = 0;
    // refstring[8] = 3;
    // refstring[9] = 1;
    // refstring[10] = 2;
    // refstring[11] = 1;
    LRU(refstring, reflen, pageframe);
    printf("Page Faults : %d", pagefault);
}