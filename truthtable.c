#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int setAND = 0;
int setOR = 0;
int setNOT = 0;
int bit = 0;
int times;
void printTable(int n);
void main()
{
    int vars, x, vals = 0;
    int ch = 1;
    printf("Enter number of variables : ");
    scanf("%d", &vars);

    printf("Menu\n1 - To perform And Operation\n2 - To perform OR operation\n3 - To perform NOT operation\nEnter your choice:\n");
    scanf("%d", &ch);
    for (x = 1; x <= vars; x++)
    {
        printf("%c\t", (64 + x));
        if (ch == 3)
        {
            printf("!%c\t", (64 + x));
        }
    }

    switch (ch)
    {
    case 1:
        setAND = 1;
        printf("\tAND");
        break;
    case 2:
        setOR = 1;
        printf("\tOR");
        break;
    case 3:
        setNOT = 1;
        break;
    }

    vals = pow(2, vars);

    for (x = 0; x < vals; x++)
    {
        bit = x % 2;
        times = vars;
        printTable(x);
        if (!setNOT)
        {
            printf("\t%d", bit);
        }

        bit = 0;
    }
    printf("\n");
}

void printTable(int n)
{
    if (n == 0 && times <= 0)
    {
        printf("\n");
    }
    else
    {
        times--;
        printTable(n / 2);
        if (setAND)
        {
            bit = bit && n % 2;
        }
        else if (setOR)
        {
            bit = bit || n % 2;
        }
        else if (setNOT)
        {
            printf("%d\t", n % 2);
            printf("%d\t", !(n % 2));
        }

        if (setNOT == 0)
        {
            printf("%d\t", n % 2);
        }
    }
}