#include <stdio.h>
#include <stdlib.h>
struct Hash
{
    int data;
    struct Hash *next;
};
struct Hash *ar = NULL;
void Nullify(struct Hash *ar, int def, int size);
void displayLink(struct Hash *ptr);
void display(struct Hash *ar,int def, int size);
void place(struct Hash *ar, int def,int size, int elem);
void insert(struct Hash *hash, int elem);
void main()
{
    int size, x, temp;
    printf("Enter size of array : ");
    scanf("%d", &size);
    ar = (struct Hash *)malloc(sizeof(struct Hash) * size);
    int def = -1;
    Nullify(ar,def, size);
    printf("Enter elements in Hash Table\n(-1) - Exit \n");
    do
    {
        scanf("%d", &temp);
        if (temp % 10 < size && temp>-1)
        {
            place(ar,def, size, temp);
        }
    } while (temp != -1);
    printf("Hash Table : \n");
    display(ar, def,size);
}

void place(struct Hash *hash, int def,int size, int elem)
{
    int place = elem % 10;

    if (hash[place].data == def)
    {
        hash[place].data = elem;
    }
    else
    {
        insert(&hash[place], elem);
    }
}

void insert(struct Hash *hash, int elem)
{
    struct Hash *new = (struct Hash *)malloc(sizeof(struct Hash));
    if (hash->next == NULL)
    {
        new->data = elem;
        new->next = NULL;
        hash->next = new;
    }
    else
    {
        insert(hash->next, elem);
    }
}

void Nullify(struct Hash *ar,int def, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        ar[x].data = def;
        ar[x].next = NULL;
    }
}

void display(struct Hash *ar,int def, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        if (ar[x].data != def)
        {
            printf("%d ", ar[x].data);
            displayLink(ar[x].next);
        }
    }
    printf("\n");
}

void displayLink(struct Hash *ptr)
{
    if (ptr != NULL)
    {
        printf("->");
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}