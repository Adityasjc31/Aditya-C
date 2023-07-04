#include<stdio.h>
void main() {
  int sum=0,s,n,i,t,c1[10],a[10],b[10],bt[10],w[10],index=0;
  float avgwt=0.0,avgtt=0.0;
  printf("\nEnter the no of process=");
  scanf("%d",&n);
  printf("\nEnter the Arrival time and Burst time of processes=");
  for(i=0;i<n;i++)
  { scanf("%d",&a[i]);
   scanf("%d",&b[i]);bt[i]=b[i];sum=sum+b[i];
c1[i]=0;       }
 

printf("Gantt Chart->");
s=32000;
  for(t=0;t<sum;t++)
  {   for(i=0;i<n;i++)
  {   if(b[i]<s && b[i]>0 && a[i]<=t)
  { s=b[i];index=i;   }}
  printf("%d",index);
  b[index]=b[index]-1;
  c1[index]=c1[index]+1;
  s=b[index];
    if (b[index]==0)
    { s=32000;
    b[index]=s;
    w[index]=(t)-(c1[index]-1)-a[index]; avgwt+=w[index];
    }     }
  printf("\nWaiting time and Turnaround time of processes=\n");
    for(i=0;i<n;i++){ 
        int temp=(w[i]+bt[i]);
        avgtt+=temp;
        printf("P[%d] = %d\t\%d\n",i,w[i],temp);}
printf("\nAng Wt = %f\tAvg Tt = %f",avgwt/n,avgtt/n);
      }
