#include <stdio.h>
int key, i, ht[10], val;
void insert()
{
    int added = 0;
    printf("enter tha value =");
    scanf("%d", &val);
    key = (val % 10) - 1;
    if (ht[key] == -1)
    {
        ht[key] = val;
    }
    else
    {
        if (key < 9)
        {
            for (i = key + 1; i < 10; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = val;
                    added = 1;
                    break;
                }
            }
        }
        if (!added)
        {
            for (i = 0; i < key; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = val;
                    break;
                }
            }
        }
    }
}
void display()
{
    printf("hash table=");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", ht[i]);
    }
}

int main()
{
    int choice;
    printf("\nENTER SENTINAL VALUE IN HASH TABLE\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &ht[i]);
    }
    do
    {
        printf("\nMENU:1.INSERT 2.DISPLAY 3.EXIT");
        printf("enter your choice=");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (size_t i = 0; i < 10; i++)
            {
                insert();
            }

            break;
        case 2:
            display();
            break;
        case 3:
            break;
        }
    } while (choice != 3);
}