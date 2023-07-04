#include<stdio.h>

void main()
{
    int num,sum=0;
    printf("Enter a number : ");
    scanf("%d",&num);
    while(num)
    {
        int d = num%10;
        sum += d;
        num = num/10;
    }
    printf("Sum of digits : %d",sum);
}