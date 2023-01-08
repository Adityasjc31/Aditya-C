#include<stdio.h>
#include<stdlib.h>
void heapify(int *ar,int size,int i);
void swap(int *a,int *b);
void HeapSort(int *ar,int size);
void display();

void main()
{
    int size;
    int *ar = NULL;
    int x;
    printf("Enter number of elements for array : ");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));

    printf("Enter elements for the array\n");
    for ( x = 0; x < size; x++)
    {
        scanf("%d",&ar[x]);
    }

    printf("Unsorted Array\n");
    display(ar,size);
    printf("\nSorted Array\n");
    HeapSort(ar,size);
    display(ar,size);
}

void display(int *ar,int size)
{
    int x=0;
    for (x = 0; x < size; x++)
    {
        printf("%d ",ar[x]);
    }
}

void heapify(int *ar,int size,int i)
{
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && ar[left]>=ar[max])
    {
        max = left;
    }

    if(right < size && ar[right]>=ar[max])
    {
        max = right;
    }

    if(max != i)
    {
        swap(&ar[i],&ar[max]);

        heapify(ar,size,max);
    }
}

void HeapSort(int *ar,int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ar,size,i);
    }
    //printf("Heapfiyed Array : \n");
    //display(ar,size);

    for (i = size - 1; i >= 0; i--) 
    {
        swap(&ar[0], &ar[i]);
        heapify(ar, i, 0);
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}