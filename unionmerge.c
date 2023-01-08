#include <stdio.h>
#include <stdlib.h>
void merge(int *A, int lb, int ub, int mid);
void divide(int *A, int lb, int ub);
void sort(int *ar, int limit);
void display(int *ar, int size);
void main()
{
    int *A = NULL, *B = NULL, *AuB = NULL;
    int x, sizeA, sizeB, y, z = 0, flag = 1;
    printf("Enter size of set A : ");
    scanf("%d", &sizeA);
    A = (int *)malloc(sizeA * sizeof(int));
    printf("Enter elements for the set A : \n");
    for (x = 0; x < sizeA; x++)
    {
        printf("Enter element at index %d : ", x);
        scanf("%d", &A[x]);
    }

    printf("Enter size of set B : ");
    scanf("%d", &sizeB);
    B = (int *)malloc(sizeB * sizeof(int));
    AuB = (int *)malloc((sizeB + sizeA) * sizeof(int));
    printf("Enter elements for the set B : \n");
    for (x = 0; x < sizeB; x++)
    {
        printf("Enter element at index %d : ", x);
        scanf("%d", &B[x]);
    }

    for (x = 0; x < sizeA; x++)
    {
        AuB[z++] = A[x];
    }

    for (x = 0; x < sizeB; x++)
    {
        AuB[z++] = B[x];
    }

    /*for(x=0;x<sizeB;x++)
    {
    flag=1;
    for(y=0;y<sizeA;y++)
    {
    if(B[x] == A[y])
    {
    flag=0;
    break;
    }

    }
    if(flag == 1)
    {
    AuB[z++] = B[x];
    }
    }*/

    sort(AuB, z);
    printf("A : ");
    display(A, sizeA);
    printf("B : ");
    display(B, sizeB);
    printf("A u B  : ");
    display(AuB, z);
}

void divide(int *a, int lb, int ub)
{
    int mid = (lb + ub) / 2;
    divide(a, lb, mid);
    divide(a, mid + 1, ub);
    merge(a, lb, ub, mid);
}

void merge(int *ar, int l, int u, int mid)
{
    int s1 = mid-l+1;
    int s2 = u-mid;

    int ar1[s1];
    int ar2[s2];

    int x,y,z;

    for(x=0;x<s1;x++)
    {
        ar1[x]=ar[l+x];
    }

    for(x=0;x<s2;x++)
    {
        ar2[x]=ar[mid+1+x];
    }

    x=y=0;
    z=l;
    while (x<s1 && y<s2)
    {
        if (ar1[x]<ar2[y])
        {
            ar[z++]=ar1[x++];
        }
        else
        {
            ar[z++]=ar2[y++];
        }
    }
    
    while (x<s1)
    {
        if(ar[z]!=ar1[x])
        {
            ar[z++]=ar1[x++];
        }
    }

    while (y<s2)
    {
        if(ar[z]!=ar1[y])
        {
            ar[z++]=ar2[y++];
        }
    }
}

void sort(int *ar, int limit)
{
    int x, y, temp, i;
    for (x = 0; x < limit; x++)
    {
        i = x;
        for (y = x + 1; y < limit; y++)
        {
            if (ar[x] > ar[y])
            {
                i = y;
            }
        }

        temp = ar[x];
        ar[x] = ar[i];
        ar[i] = temp;
    }
}

void display(int *ar, int size)
{
    int x = 0;
    printf("\n{");
    for (; x < size; x++)
    {
        printf("%d", ar[x]);
        if (x < (size - 1))
        {
            printf(",");
        }
    }
    printf("}\n");
}