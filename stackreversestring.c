#include<stdio.h>
char str[100];
void main()
{
    int top=0,i;
    char new_str[100];
    printf("Enter string : ");
    gets(str);
    char ch = ' ';
    while (ch!='\0')
    {
        ch=str[top++];
    }
    int size=--top;
    for ( i = 0; i < size; i++)
    {
        new_str[i] = str[--top];
    }
    new_str[size] = '\0';
    puts(new_str);
}