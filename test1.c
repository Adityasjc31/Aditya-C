#include <stdio.h>
void display(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int *A, int p, int q, int r)
{
    int s1 = q - p + 1;
    int s2 = r - q;
    int l[s1], rr[s2];
    int i, j;

    for (i = 0; i < s1; i++)
    {
        l[i] = A[p + i];
    }

    for (i = 0; i < s2; i++)
    {
        rr[i] = A[i + q + 1];
    }

    int k = p;
    i = 0, j = 0;

    while (i < s1 && j < s2)
    {
        if (l[i] < rr[j])
        {
            A[k++] = l[i++];
        }
        else
        {
            A[k++] = rr[j++];
        }
    }
    while (i < s1)
    {
        A[k++] = l[i++];
    }

    while (j < s2)
    {
        A[k++] = rr[j++];
    }
    display(A,8);
}

void mergesort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void main()
{
    int A[] = {5, 7, 8, 2, 3, 6, 1, 9};
    mergesort(A, 0, 7);
    int i;

    for (i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}