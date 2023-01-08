#include<stdio.h>
#include<stdlib.h>
#include "quicksortPartAtLastIndex.c"
int binarySearch(int *ar,int size,int val);
void main()
{
    int *ar=NULL,i=0,size,val;
    printf("Enter size of array : ");
    scanf("%d",&size);
    ar = (int*)malloc(size*sizeof(int));
    printf("Enter elements : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d",&ar[i]);
    }

    quickSort(ar,size);
    printf("Redefined Array : \n");
    display(ar,size);
    printf("\nEnter element whose index it to be found : ");
    scanf("%d",&val);

    i = binarySearch(ar,size,val);
    if(i==-1)
    {
        printf("Not Found");
    }
    else
    {
        printf("Element is at index = %d",i);
    }
}

int binarySearch(int *ar,int size,int val)
{
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(ar[mid]==val)
        {
            return mid;
        }
        else if(val < ar[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid +1;
        }
    }
    return -1;
}