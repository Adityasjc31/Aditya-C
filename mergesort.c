#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *ar, int l, int r);
void merge(int *ar, int l, int mid, int r);
void display(int *ar,int size);
void main()
{
    int left = 0, right, mid, size;
    int *ar = NULL;
    int x;
    printf("Enter number of elements for array : ");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));
    right = size - 1;

    printf("Enter elements for the array\n");
    for ( x = 0; x < size; x++)
    {
        scanf("%d",&ar[x]);
    }

    printf("Unsorted Array\n");
    display(ar,size);
    mergeSort(ar,left,right);
    printf("\nSorted Array\n");
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

void mergeSort(int *ar, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(ar, left, mid);
        mergeSort(ar, mid + 1, right);

        merge(ar, left, mid, right);
    }
}
int p = 0;
void merge(int *ar, int l, int mid, int r)
{
    int s1 = mid-l+2;
    int s2 = r-mid+1,val;

    int ar1[s1];
    int ar2[s2];

    int x,y,z;

    for(x=0;x<s1-1;x++)
    // for(x=0;x<s1;x++)
    {
        ar1[x]=ar[l+x];
    }

    // for(x=0;x<s2;x++)
    for(x=0;x<s2-1;x++)
    {
        ar2[x]=ar[mid+1+x];
    }

    ar1[s1-1] = ar2[s2-1] = ar1[s1-2] + ar2[s2-2];
    // printf("\n");
    // display(ar1,s1);
    // printf("\n");
    // display(ar2,s2);
    // printf("\n");
    if(ar1[s1-2] == 0 || ar2[s2-2] == 0)
    {
        ar1[s1-1] = ar2[s2-1] = ar1[s1-2] + ar2[s2-2] + 1;
    }
    x=y=0;
    z=l;
    // printf("\nPass : %d\n",p++);
    while (z<r+1)
    // while(x<s1 && y<s2)
    {
        val = ar1[x]<ar2[y];
        if (val)
        {
            ar[z]=ar1[x++];
        }
        else //if(ar1[x]>ar2[y])
        {
            ar[z]=ar2[y++];
        }
        z++;
    }
    
    // while (x<s1)
    // {
    //     ar[z++]=ar1[x++];
    // }

    // while (y<s2)
    // {
    //     ar[z++]=ar2[y++];
    // }
    // display(ar,7);
}