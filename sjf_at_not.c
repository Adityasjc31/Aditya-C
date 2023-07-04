#include<stdlib.h>
#include<stdio.h>
int *wt,*tt;
void sortIndex(int *sort_ar,int start,int end,char *rest1,int *rest2)
{
    int x,y,index,temp;
    char temp1;

    for (x = start;x < end;x++)
    {
        index = x;
        for (y = x+1;y < end;y++)
        {
            if (sort_ar[y] < sort_ar[index])
            {
                index = y;
            }
        }
        temp = sort_ar[index];
        sort_ar[index] = sort_ar[x];
        sort_ar[x] = temp;

        temp1 = rest1[index];
        rest1[index] = rest1[x];
        rest1[x] = temp1;

        temp = rest2[index];
        rest2[index] = rest2[x];
        rest2[x] = temp;
    }   
}

void sortChar(char *sort_ar,int *rest1,int *rest2,int *rest3,int *rest4,int size)
{
    int x,y,index,temp;
    char temp1;

    for (x = 0;x < size;x++)
    {
        index = x;
        for (y = x+1;y < size;y++)
        {
            if (sort_ar[y] < sort_ar[index])
            {
                index = y;
            }
        }
        temp = sort_ar[index];
        sort_ar[index] = sort_ar[x];
        sort_ar[x] = temp;

        temp1 = rest1[index];
        rest1[index] = rest1[x];
        rest1[x] = temp1;

        temp = rest2[index];
        rest2[index] = rest2[x];
        rest2[x] = temp;

        temp = rest3[index];
        rest3[index] = rest3[x];
        rest3[x] = temp;

        temp = rest4[index];
        rest4[index] = rest4[x];
        rest4[x] = temp;
    }   
}

void sort(int *sort_ar,char *rest1,int *rest2,int sort_size)
{
    sortIndex(sort_ar,0,sort_size,rest1,rest2);
}

void sjf(char *pid,int *at,int *bt,int process)
{
    int x,y,burst=0;
    printf("Gantt chart : ");
    for (x = 0;x < process;x++)
    {
        printf("%c",pid[x],bt[x]);
        if (x<process-1)
        {
            printf("->");
        }
        sortIndex(bt,x+1,bt[x] >= process ? (process) : bt[x],pid,at);
    }
    
    wt[0] = 0;
    for (x = 1;x < process;x++)
    {
        burst += bt[x-1];
        wt[x] = burst - at[x];
        tt[x-1] = bt[x-1] + wt[x-1];
    }
    tt[x-1] = bt[x-1] + wt[x-1];

    printf("\n");
}

void main()
{
    int process,*at,*bt;
    float avgwt=0.0,avgtt=0.0;
    char *pid;
    int x;
    printf("Enter number of process : ");
    scanf("%d",&process);

    pid = (char *)malloc(process * sizeof(char));
    at = (int *)malloc(process * sizeof(int));
    bt = (int *)malloc(process * sizeof(int));
    wt = (int *)malloc(process * sizeof(int));
    tt = (int *)malloc(process * sizeof(int));

    printf("Enter pids : ");
    for (x = 0;x < process;x++)
    {
        scanf("%c",&pid[x]);
        scanf("%c",&pid[x]);
    }

    for(x = 0 ;x<process;x++)
    {
        at[x]=0;
    }
    
    for(x = 0 ;x<process;x++)
    {
        printf("Enter burst time of process id %c : ",pid[x]);
        scanf("%d",&bt[x]);
    }

    sort(bt,pid,at,process);
    sjf(pid,at,bt,process);

    for (x = 0;x < process;x++)
    {
        avgwt += wt[x];
        avgtt += tt[x];
    }

    sortChar(pid,at,bt,wt,tt,process);
    printf("Process Id\tArrival Time\tBurst Time\tWaiting time\tTurnaround time\n");
    for (x = 0;x < process;x++)
    {
        printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[x],at[x],bt[x],wt[x],tt[x]);
    }
    
    avgwt = avgwt/process;
    avgtt = avgtt/process;

    printf("Average waiting time : %.2f ",avgwt);
    printf("Average turnaround time : %.2f ",avgtt);
}