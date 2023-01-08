#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char *str,int);
char *revExtraSpace(char *);
void main()
{
    char str[5], *str1;
    printf("Enter a sentence : ");
    gets(str);
    str1 = revExtraSpace(str);
    print(str1,str1[-1]);
}

char *revExtraSpace(char *str)
{
    int x, y = 0, flag = 0, len = strlen(str), index, firstcounter = 0;
    char ch;
    char spaceRemove[len],*rev = NULL;
    for (x = 0; x < len; x++)
    {
        ch = str[x];
        if (ch != ' ')
        {
            // printf("%c",ch);
            spaceRemove[y++] = ch;
            flag = 0;
            firstcounter = 1;
        }
        else if (!flag && firstcounter)
        {
            // printf(" ");
            spaceRemove[y++] = ' ';
            flag = 1;
        }
    }
    len = x;
    rev = (char *)malloc(sizeof(char) * len);
    for (x = len-1;x >= 0;x--)
    {
        index = len - 1 - x;
        rev[index] = spaceRemove[x];
    }
    rev[-1] = len;
    return rev;
}

void print(char *str, int len)
{
    for (int x = 0; x < len; x++)
    {
        printf("%c", str[x]);
    }
}