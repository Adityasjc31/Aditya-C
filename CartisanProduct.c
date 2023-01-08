#include <stdio.h> 

void main()
{
    int x,y,size=3,a[size],b[size]; 
    
    printf("Enter %d elements for set A\n",size);
    for(x=0; x<size; x++) {
        scanf("%d",&a[x]);
    }

    printf("Enter %d elements for set B\n",size);

    for (x=0; x<size; x++) {
        scanf("%d", &b [x]);
    }

    printf("Cartisan Product : \n("); 
    for(x=0; x<size; x++)
    {
        for (y=0;y<size; y++) 
        {
            printf("(");
            printf("%d", a[x]); 
            printf(",%d",b[y]);
            printf(")");
        }
        if(x!=(size-1))
        {
            printf(",");
        }
    }
    printf("}\n");
}