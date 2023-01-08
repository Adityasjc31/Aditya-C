#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void quickSort(int *ar,int size);
void QuickSort(int *ar, int low, int high);
int makePartition(int *ar, int size, int i);
void display(int *ar, int size);
void main()
{
    int x, size;
    int *ar = NULL;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));
    printf("Enter elements :\n");
    for (x = 0; x < size; x++)
    {
        scanf("%d", &ar[x]);
    }

    printf("Unsorted Array\n");
    display(ar, size);
    quickSort(ar, size);
    printf("\nSorted Array\n");
    display(ar, size);
}

void quickSort(int *ar,int size)
{
    QuickSort(ar, 0, (size - 1));
}

void QuickSort(int *ar, int low, int high)
{
    int part;
    if (low < high)
    {
        part = makePartition(ar, low, high);
        // printf("\n");
        // display(ar, 7);
        QuickSort(ar, low, part - 1);
        QuickSort(ar, part + 1, high);
    }
}
int makePartition(int *ar, int low, int high)
{
    int x, i = low - 1;
    for (x = low; x <=high - 1; x++)
    {
        if (ar[x] < ar[high])
        {
            i++;
            swap(&ar[i], &ar[x]);
        }
    }
    
    swap(&ar[i + 1], &ar[high]);
    return (i + 1);
}
void display(int *ar, int size)
{
    int x = 0;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}