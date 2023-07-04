#include <stdio.h>
#include <stdlib.h>

void DFS(int **adj, int *visited, int size, int start)
{
    int *stack = (int *)malloc(sizeof(int) * size);
    int top = -1;
    int x;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        start = stack[top--];

        printf("%c \t", start + 65);
        for (x = 0; x < size; x++)
        {
            if (adj[start][x] == 1 && visited[x] == 0)
            {
                stack[++top] = x;
                visited[x] = 1;
            }
        }

        // HELPER FOR UNDERSTANDING WORKING
        // printf("\nStack : ");
        // for (size_t i = 0; i < size; i++)
        // {
        //     printf("%d,", stack[i]);
        // }
        // printf("top = %d \n", top);
        // printf("Visited : ");
        // for (size_t i = 0; i < size; i++)
        // {
        //     printf("%d,", visited[i]);
        // }
        // printf("\n");
    }
}

void main()
{
    int size, start;
    int *visited, **adj, i, j;
    printf("Enter size : ");
    scanf("%d", &size);
    printf("Enter starting vertex : ");
    scanf("%d", &start);
    printf("Enter adjancey Matrix : \n");
    adj = (int **)malloc(sizeof(int *) * size);
    visited = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        adj[i] = (int *)malloc(sizeof(int) * size);
        for (j = 0; j < size; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    DFS(adj, visited, size, (start - 1));
}