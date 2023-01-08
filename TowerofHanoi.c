#include<stdio.h>
void towerOfHanoi(int,int ,int ,int);
void main(){
    
}

//pseudo code
void towerOfHanoi(int n, int A, int B, int C)
{
    if (n>0)
    {
        towerOfHanoi(n-1,A,C,B);
        printf("");
        towerOfHanoi(n-1,B,A,C);
    }
}
