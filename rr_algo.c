#include <stdlib.h>
#include <stdio.h>
int *wt, *tt, quanta;
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

        temp1 = rest1[index];
        rest1[index] = rest1[x];
        rest1[x] = temp1;

        temp = rest2[index];
        rest2[index] = rest2[x];
        rest2[x] = temp;
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

void rr(char *pid, int *at, int *bt, int process)
{
    int x = 0, y, pointer = 0, time = 0;
    int *bt_duplicate = (int *)malloc(process * sizeof(int));
    int front = 0, rear = -1;
    char *queue = (char *)malloc(process * sizeof(char));
    int sum = 0;
    for (x = 0; x < process; x++)
    {
        bt_duplicate[x] = bt[x];
        sum += bt[x];
        queue[x] = '\000';
    }
    printf("Gantt chart : \n");
    x = 0;
    while (time < sum)
    {
        if (rear == (process - 1))
        {
            queue = (char *)realloc(queue, rear + 1);
        }
        

        if(x<process)
            queue[++rear] = pid[x++];
        if (bt[queue[front] - 65]<quanta && bt[queue[front] - 65]>0)
        {
            time+=bt[queue[front] - 65];
        }
        else
        {
            time += quanta;
        }

        printf("%c:%d->", queue[front], time);
        bt[queue[front] - 65] = bt[queue[front] - 65] - quanta;
        while (time >= at[x] && x < process)
        {
            queue[++rear] = pid[x++];
        }
        if (bt[queue[front] - 65] != 0)
        {
            queue[++rear] = queue[front];
        }
        else
        {
            tt[queue[front] - 65] = time - at[queue[front] - 65];
        }
        front++;

        // printf("PIDS : ");
        // printArrayChar(pid, process);
        // printf("Arrival array : ");
        // printArray(at, process);
        // printf("Burst array : ");
        // printArray(bt, process);
        // printf("Queue : ");
        // printArrayChar(queue, rear);
    }
    tt[queue[front] - 65] = time - at[queue[front] - 65];
    for (x = 0; x < process; x++)
    {
        bt[x] = bt_duplicate[x];
    }

    for (x = 0; x < process; x++)
    {
        wt[x] = tt[x]-bt[x];
    }

    printf("\n");
}

void main()
{
    int process = 4, *at, *bt;
    float avgwt = 0.0, avgtt = 0.0;
    quanta =1;
    char *pid;
    int x;

    printf("Enter number of process : ");
    scanf("%d",&process);
    printf("Enter quantum : ");
    scanf("%d",&quanta);

    pid = (char *)malloc(process * sizeof(char));
    at = (int *)malloc(process * sizeof(int));
    bt = (int *)malloc(process * sizeof(int));
    wt = (int *)malloc(process * sizeof(int));
    tt = (int *)malloc(process * sizeof(int));

    // pid[0] = 'A';
    // pid[1] = 'B';
    // pid[2] = 'C';
    // pid[3] = 'D';

    // bt[0] = 4;
    // bt[1] = 7;
    // bt[2] = 2;
    // bt[3] = 2;

    // at[0] = 0;
    // at[1] = 2;
    // at[2] = 3;
    // at[3] = 3;
    // printf("Enter pids : ");
    for (x = 0;x < process;x++)
    {
        scanf("%c",&pid[x]);
        scanf("%c",&pid[x]);
    }

    for(x = 0 ;x<process;x++)
    {
        printf("Enter arrival time of process id %c : ",pid[x]);
        scanf("%d",&at[x]);
    }

    for(x = 0 ;x<process;x++)
    {
        printf("Enter burst time of process id %c : ",pid[x]);
        scanf("%d",&bt[x]);
    }

    sort(at, pid, bt, process);
    rr(pid, at, bt, process);

    for (x = 0; x < process; x++)
    {
        avgwt += wt[x];
        avgtt += tt[x];
    }

    printf("Process Id\tArrival Time\tBurst Time\tWaiting time\tTurnaround time\n");
    for (x = 0; x < process; x++)
    {
        printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[x], at[x], bt[x], wt[x], tt[x]);
    }

    avgwt = avgwt / process;
    avgtt = avgtt / process;

    printf("Average waiting time : %.2f ", avgwt);
    printf("Average turnaround time : %.2f ", avgtt);
}