#include<stdio.h>  // Round Robin Scheduling
void main()
{
  int sum=0,s,n,i,t,c1[10],a[10],b[10],w[10],index=0,c2=0,q;
  float avgwt=0.0;
  printf("\nEnter the no of process and quantum_size=");
  scanf("%d%d",&n,&q);
  printf("\nEnter the Arrival time and Burst time of processes=");
  for(i=0;i<n;i++)
  { scanf("%d",&a[i]);
   scanf("%d",&b[i]);sum=sum+b[i];
c1[i]=0;
      }
  for(t=0;t<sum;t++)
  {
  for(i=0;i<n;i++)
  {
  if(b[i]>0 && a[i]<=c2)
  { if (b[i]>=q){b[i]=b[i]-q;c1[i]=c1[i]+q;c2=c2+q;}
    else {b[i]=b[i]-1;c1[i]=c1[i]+1;c2=c2+1;} }
    if (b[i]==0 && c1[i]>0)
    { w[i]=c2-c1[i]-a[i]; printf("P[%d] = %d\n",i,w[i]);avgwt+=w[i];
      c1[i]=0; 
    }
    }}
  printf("\nWaiting time of processes=\n");
    for(i=0;i<n;i++){ printf("P[%d] = %d\n",i,w[i]);}
printf("\nWt = %f\n",avgwt/n);
      }
