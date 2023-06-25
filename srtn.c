#include <stdio.h>
#include <stdlib.h>
int *wt, *tt;
void sortIndex(int *sort_ar, int start, int end, char *rest1, int *rest2)
{
    int x, y, index, temp;
    char temp1;

    for (x = start; x < end; x++)
    {
        index = x;
        for (y = x + 1; y < end; y++)
        {
            if (sort_ar[y] < sort_ar[index])
            {
                index = y;
            }
        }
        temp = sort_ar[index];
        sort_ar[index] = sort_ar[x];
        sort_ar[x] = temp;

        if (rest1 != NULL)
        {
            temp1 = rest1[index];
            rest1[index] = rest1[x];
            rest1[x] = temp1;
        }

        if (rest2 != NULL)
        {
            temp = rest2[index];
            rest2[index] = rest2[x];
            rest2[x] = temp;
        }
    }
}

void sort(int *sort_ar, char *rest1, int *rest2, int sort_size)
{
    sortIndex(sort_ar, 0, sort_size, rest1, rest2);
}

void printArray(int *ar, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%d ", ar[x]);
    }
    printf("\n");
}

void printArrayChar(char *ar, int size)
{
    int x;
    for (x = 0; x < size; x++)
    {
        printf("%c ", ar[x]);
    }
    printf("\n");
}

void srtn(char *pid, int *at, int *bt, int process)
{
    int x, time = 0;
    char lastpid = '\000';
    int *bt_duplicate = (int *)malloc(process * sizeof(int));
    for (x = 0; x < process; x++)
    {
        bt_duplicate[x] = bt[x];
    }
    printf("\n");
    printf("Gantt chart : \n");
    for (x = 0; x < process;)
    {
        if(bt_duplicate[x]==0)
            x++;
        lastpid = pid[x];
        time += 1;
        bt_duplicate[x]--;
        
        
        sortIndex(bt_duplicate, (x-1)<0 ? 0  : x-1, time>process ? process : time, pid, at);


        if (pid[x] == lastpid && bt_duplicate[x]!=0)
        {
            continue;
        }
        printf("%c:%d->\n", lastpid,time);

    }

    // wt[0] = 0;
    // for (x = 1; x < process; x++)
    // {
    //     burst += bt[x - 1];
    //     wt[x] = burst - at[x];
    //     tt[x - 1] = bt[x - 1] + wt[x - 1];
    // }
    // tt[x - 1] = bt[x - 1] + wt[x - 1];

    printf("\n");
}

void main()
{
    int process, *at, *bt;
    float avgwt = 0.0, avgtt = 0.0;
    char *pid;
    int x;
    process = 5;
    // printf("Enter number of process : ");
    // scanf("%d", &process);

    pid = (char *)malloc(process * sizeof(char));
    at = (int *)malloc(process * sizeof(int));
    bt = (int *)malloc(process * sizeof(int));
    wt = (int *)malloc(process * sizeof(int));
    tt = (int *)malloc(process * sizeof(int));

    pid[0] = 'A';
    pid[1] = 'B';
    pid[2] = 'C';
    pid[3] = 'D';
    pid[4] = 'E';

    bt[0] = 6;
    bt[1] = 2;
    bt[2] = 8;
    bt[3] = 3;
    bt[4] = 4;

    at[0] = 2;
    at[1] = 5;
    at[2] = 1;
    at[3] = 0;
    at[4] = 4;

    // printf("Enter pids : ");
    // for (x = 0; x < process; x++)
    // {
    //     scanf("%c", &pid[x]);
    //     scanf("%c", &pid[x]);
    // }

    // for (x = 0; x < process; x++)
    // {
    //     printf("Enter arrival time of process id %c : ", pid[x]);
    //     scanf("%d", &at[x]);
    // }

    // for (x = 0; x < process; x++)
    // {
    //     printf("Enter burst time of process id %c : ", pid[x]);
    //     scanf("%d", &bt[x]);
    // }

    sort(at, pid, bt, process);
    printf("PIDS : ");
    printArrayChar(pid, process);
    printf("Arrival array : ");
    printArray(at, process);
    printf("Burst array : ");
    printArray(bt, process);
    srtn(pid, at, bt, process);

    // for (x = 0;x < process;x++)
    // {
    //     avgwt += wt[x];
    //     avgtt += tt[x];
    // }

    // printf("Process Id\tArrival Time\tBurst Time\tWaiting time\tTurnaround time\n");
    // for (x = 0;x < process;x++)
    // {
    //     printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[x],at[x],bt[x],wt[x],tt[x]);
    // }

    // avgwt = avgwt/process;
    // avgtt = avgtt/process;

    // printf("Average waiting time : %.2f ",avgwt);
    // printf("Average turnaround time : %.2f ",avgtt);
}