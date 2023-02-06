#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct bucket
{
    int data;
    struct bucket *next;
} Bucket;
void NullifyBucket(Bucket *buckets);
void bucketLink(Bucket *bucket, int elem);
void display(int *ar, int size);
int digitsCount(int elem);
void main()
{
    int x, y, size, *ar;
    Bucket buckets[10];
    printf("Enter size of array : ");
    scanf("%d", &size);
    ar = (int *)malloc(sizeof(int) * size);
    printf("Enter elements of the array : ");
    for (x = 0; x < size; x++)
    {
        scanf("%d", &ar[x]);
    }

    size_t maxElement = 0;
    for (x = 0; x < size; x++)
    {
        if (ar[maxElement] < ar[x])
        {
            maxElement = x;
        }
    }

    size_t numberOfdigits = digitsCount(ar[maxElement]);

    size_t divisionfactor = 1;
    for (x = 1; x <= numberOfdigits; x++)
    {
        NullifyBucket(buckets);
        // divisionfactor = 10 * divisionfactor;
        for (size_t y = 0; y < size; y++)
        {
            size_t index, dividecount = 1;
            for (size_t divide = ar[y]; dividecount <= x; divide = divide / 10)
            {
                index = divide % 10;
                dividecount++;
            }

            if (buckets[index].data == INT_MAX)
            {
                buckets[index].data = ar[y];
            }
            else
            {
                bucketLink(&buckets[index], ar[y]);
            }
        }

        size_t update = 0;
        for (size_t z = 0; z < size; z++)
        {
            if (buckets[z].data != INT_MAX)
            {
                ar[update] = buckets[z].data;
                update++;
                while (buckets[z].next != NULL)
                {
                    ar[update] = buckets[z].next->data;
                    buckets[z].next = buckets[z].next->next;
                    update++;
                }
            }
        }
        printf("Pass %d : \n", x);
        display(ar, size);
    }
}
int digitsCount(int elem)
{
    int x, c = 0;
    for (x = elem; x != 0; x = x / 10)
    {
        c++;
    }
    return c;
}
void NullifyBucket(Bucket *buckets)
{
    int x;
    for (x = 0; x < 10; x++)
    {
        buckets[x].data = INT_MAX;
        buckets[x].next = NULL;
    }
}

void bucketLink(Bucket *bucket, int elem)
{
    Bucket *newbucket = (Bucket *)malloc(sizeof(Bucket));
    if (bucket->next == NULL)
    {
        newbucket->data = elem;
        newbucket->next = NULL;
        bucket->next = newbucket;
    }
    else
    {
        bucketLink(bucket->next, elem);
    }
}

void display(int *ar, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
    printf("\n");
}
// void display(Bucket *ar, int size)
// {
//     int x;
//     for (x = 0; x < size; x++)
//     {
//         if (ar[x].data != INT_MAX)
//         {
//             printf("%d ", ar[x].data);
//             displayLink(ar[x].next);
//         }
//     }
//     printf("\n");
// }

// void displayLink(Bucket *ptr)
// {
//     if (ptr != NULL)
//     {
//         printf("->");
//         while (ptr != NULL)
//         {
//             printf("%d->", ptr->data);
//             ptr = ptr->next;
//         }
//     }
//     printf("\n");
// }