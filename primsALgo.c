#include <stdio.h>
#include <stdlib.h>
int INFINITY = 1;
void printMatrix(int **ar, int size);
void prims(int **cost, int nodes);
int minElementIndex(int *ar, int size, int ignore);
void main()
{
    int x, y;
    int **cost = NULL;
    int nodes = 0;

    printf("Enter nodes : ");
    scanf("%d", &nodes);

    cost = (int **)malloc(sizeof(int *) * nodes);

    printf("Enter adjancency Matrix : \n");
    for (x = 0; x < nodes; x++)
    {
        cost[x] = (int *)malloc(sizeof(int) * nodes);
        for (y = 0; y < nodes; y++)
        {
            scanf("%d", &cost[x][y]);
            INFINITY += cost[x][y];
        }
    }

    for (x = 0; x < nodes; x++)
    {
        for (y = 0; y < nodes; y++)
        {
            if (cost[x][y] == 0)
            {
                cost[x][y] = INFINITY;
            }
        }
    }
    prims(cost, nodes);
}

void printMatrix(int **ar, int size)
{
    int x, y;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("%d ", ar[x][y]);
        }
        printf("\n");
    }
}

void prims(int **cost, int nodes)
{
    int x, y;
    int *visited = (int *)malloc(nodes * sizeof(int));
    int mincost = 0;
    for (x = 0; x < nodes; x++)
    {
        visited[x] = 0;
    }
    printf("Edge\tWeight\n");
    x = 0;
    int NUMBEROFPRINTS = 1;
    visited[0] = cost[0][(minElementIndex(cost[0], nodes, -1))];
    while (NUMBEROFPRINTS < nodes)
    {
        size_t index = minElementIndex(cost[x], nodes, -1);

        if (visited[index] != 0)
        {
            index = minElementIndex(cost[x], nodes, index);
            if (visited[index]!=0)
            {
                x--;
                if (x < 0)
                {
                    x = nodes - 1;
                }
                continue;
            }
        }

        size_t betterIndex = minElementIndex(cost[index], nodes, -1);
        if (cost[index][betterIndex] < cost[x][index] && visited[betterIndex] != 0)
        {
            x = betterIndex;
        }

        printf("%d<->%d\t%d\n", (x + 1), (index + 1), cost[x][index]);

        mincost += cost[x][index];

        visited[index] = cost[x][index];

        cost[x][index] = cost[index][x] = INFINITY;

        x = index;

        NUMBEROFPRINTS++;
    }
    printf("Minimum cost of spanning tree : %d", mincost);
}

int minElementIndex(int *ar, int size, int ignore)
{
    int x;
    int min = 0;
    if (ignore == min)
    {
        min += 1;
    }

    for (x = 0; x < size; x++)
    {
        if (ar[min] > ar[x] && ignore != x)
        {
            min = x;
        }
    }
    return min;
}