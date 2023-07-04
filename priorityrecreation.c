#include <stdio.h>
#include <stdlib.h>
int *wt, *tt;
void sortIndex(int *sort_ar, int start, int end, char *rest1, int *rest2, int *rest3)
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

        if (rest3 != NULL)
        {
            temp = rest3[index];
            rest3[index] = rest3[x];
            rest3[x] = temp;
        }
    }
}

void sort(int *sort_ar, char *rest1, int *rest2, int *rest3, int sort_size)
{
    sortIndex(sort_ar, 0, sort_size, rest1, rest2, rest3);
}

void sortChar(char *sort_ar, int *rest1, int *rest2, int size)
{
    int x, y, index, temp;
    char temp1;

    for (x = 0; x < size; x++)
    {
        index = x;
        for (y = x + 1; y < size; y++)
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

void priority(char *pid, int *at, int *bt, int *pr, int process)
{
    int x,y, time = 0;
    char lastpid = '\000';
    int *bt_duplicate = (int *)malloc(process * sizeof(int));
    for (x = 0; x < process; x++)
    {
        bt_duplicate[x] = bt[x];
    }
    sort(at, pid, bt_duplicate, pr, process);

    printf("Gantt chart : \n");
    time +=1;
    printf("%c:%d",pid[x],time);
    bt[x]--;
    
    

    for (x = 0; x < process; x++)
    {
        bt[x] = bt_duplicate[x];
    }
    // printf("Process array : ");
    // printArrayChar(pid, process);
    // printf("Arrival array : ");
    // printArray(at, process);
    // printf("Duplicate Burst array : ");
    // printArray(bt_duplicate, process);
    // printf("Priority array : ");
    // printArray(pr, process);

    // sortChar(pid, at, pr, process);
    // for (x = 0; x < process; x++)
    // {
    //     wt[x] = tt[x] - bt[x];
    // }

    printf("\n");
}
void main()
{
    int process, *at, *bt, *pr;
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
    pr = (int *)malloc(process * sizeof(int));

    pid[0] = 'A';
    pid[1] = 'B';
    pid[2] = 'C';
    pid[3] = 'D';
    pid[4] = 'E';

    bt[0] = 4;
    bt[1] = 3;
    bt[2] = 1;
    bt[3] = 5;
    bt[4] = 2;

    at[0] = 0;
    at[1] = 1;
    at[2] = 2;
    at[3] = 3;
    at[4] = 4;

    pr[0] = 4;
    pr[1] = 3;
    pr[2] = 2;
    pr[3] = 1;
    pr[4] = 1;

    printf("PIDS : ");
    printArrayChar(pid, process);
    printf("Arrival array : ");
    printArray(at, process);
    printf("Burst array : ");
    printArray(bt, process);

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

    // for (x = 0; x < process; x++)
    // {
    //     printf("Enter priorty of process id %c : ", pid[x]);
    //     scanf("%d", &pr[x]);
    // }

    // priority(pid, at, bt, pr, process);

    // for (x = 0; x < process; x++)
    // {
    //     avgwt += wt[x];
    //     avgtt += tt[x];
    // }

    printf("Process Id\tArrival Time\tBurst Time\tPriority\tWaiting time\tTurnaround time\n");
    for (x = 0; x < process; x++)
    {
        printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[x], at[x], bt[x], pr[x], wt[x], tt[x]);
    }

    avgwt = avgwt / process;
    avgtt = avgtt / process;

    printf("Average waiting time : %.2f\n", avgwt);
    printf("Average turnaround time : %.2f ", avgtt);
}
v