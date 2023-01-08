#include <stdio.h>
void main()
{
int a[5],b[5],aUb[10],x,y,z,flag=1;

        printf("Enter value for set A\n");
        for(x=0;x<5;x++)
        {
                scanf("%d",&a[x]);
        }
       
        printf("Enter value for set B\n");
        for(x=0;x<5;x++)
        {
                scanf("%d",&b[x]);
        }
       
for(z=0;z<5;z++)
{
       aUb[z] = a[z];
}

for(x=0;x<5;x++)
{
       flag=1;
       for(y=0;y<5;y++)
       {
               if(b[x] == a[y])
               {
                       flag=0;
                       break;
               }
       }
       if(flag==1)
       {
               aUb[z++] = b[x];
       }
}
printf("A = {");
for(x=0;x<5;x++)
{
       printf("%d ",a[x]);
}
printf("}\nB={");
for(x=0;x<5;x++)
{
       printf("%d ",b[x]);
}
printf("}\nC={");
for(x=0;x<z;x++)
{
       printf("%d ",aUb[x]);
}
printf("}\n");
}