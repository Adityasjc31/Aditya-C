#include<stdio.h>
int partition(int arr[],int beg,int end);
void quick_sort(int arr[],int beg,int end);
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

int partition(int ar[], int low, int high)
{
    int x,i=low-1;
    for (x = low;x < high;x++)
    {
        if (ar[x] < ar[high])
        {
            i++;
            swap(&ar[i],&ar[x]);
        }
    }
    swap(&ar[i+1],&ar[high]);
    return (i+1);
}

void quick_sort(int arr[], int beg, int end)
{
    int part;
    if (beg<end)
    {
        part = partition(arr,beg,end);
        quick_sort(arr,beg,part-1);
        quick_sort(arr,part+1,end);
    }
    
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *ar, int size)
{
    int x = 0;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
}