#include <stdio.h>
#include <stdlib.h>

void BFS(int **adj, int *visited, int size, int start)
{
    int *queue = (int *)malloc(sizeof(int) * size);
    int rear = -1, front = -1;
    int x;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[++front];
        
        printf("%c \t", start + 65);
        
        for (x = 0; x < size; x++)
        {
            if (adj[start][x] == 1 && visited[x] == 0)
            {
                queue[++rear] = x;
                visited[x] = 1;
            }
        }
        //HELPER FOR UNDERSTANDING WORKING
        // printf("\nQueue : ");
        // for (size_t i = 0; i < size; i++)
        // {
        //     printf("%d,",queue[i]);
        // }
        // printf("  front = %d & rear = %d\n",front,rear);
        // printf("Visited : ");
        // for (size_t i = 0; i < size; i++)
        // {
        //     printf("%d,",visited[i]);
        // }
        // printf("\n");
    }
}

void main()
{
    int size,start;
    int *visited, **adj,i,j;
    printf("Enter size : ");
    scanf("%d", &size);
    printf("Enter starting vertex : ");
    scanf("%d",&start);
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

    BFS(adj, visited, size, (start-1));
}