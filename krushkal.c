#include<stdio.h>
#include<stdlib.h>
void kruskal(int **adj,int size)
{
    
}

void main()
{
     int size;
    int *visited, **adj, i, j;
    printf("Enter size : ");
    scanf("%d", &size);
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
}