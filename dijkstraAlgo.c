#include <stdio.h>
#include <stdlib.h>
int INFINITY = 1;
void printMatrix(int **ar, int size);
void dijkstra(int **cost, int nodes);
int minElementIndex(int *ar, int size, int ignore);
void main()
{
    int x, y;
    int **graph = NULL;
    int nodes = 0;

    printf("Enter nodes : ");
    scanf("%d", &nodes);

    graph = (int **)malloc(sizeof(int *) * nodes);

    printf("Enter adjancency Matrix : \n");
    for (x = 0; x < nodes; x++)
    {
        graph[x] = (int *)malloc(sizeof(int) * nodes);
        for (y = 0; y < nodes; y++)
        {
            scanf("%d", &graph[x][y]);
            INFINITY += graph[x][y];
        }
    }

    for (x = 0; x < nodes; x++)
    {
        for (y = 0; y < nodes; y++)
        {
            if (graph[x][y] == 0)
            {
                graph[x][y] = INFINITY;
            }
        }
    }
    dijkstra(graph, nodes);
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

void dijkstra(int **graph,int nodes)
{
    
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