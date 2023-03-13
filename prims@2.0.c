// Prim's Algorithm in C

#include <stdio.h>
#include <stdbool.h>

#define INF 9999999

// number of vertices in graph
#define V 6

// create a 2d array of size 5x5
// for adjacency matrix to represent graph
int G[V][V] = {
    {0, 3, 8, 12, 0, 0},
    {3, 0, 4, 0, 2, 6},
    {8, 4, 0, 0, 0, 9},
    {12, 0, 0, 0, 5, 5},
    {0, 0, 0, 5, 0, 3},
    {0, 6, 9, 5, 3, 0}};

int main()
{
    int no_edge; // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    // graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    // print for edge and weight
    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {
        // For every vertex in the set S, find the all adjacent vertices
        //  , calculate the distance from the vertex selected at step 1.
        //  if the vertex is already in the set S, discard it otherwise
        // choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int getMin(int *ar, int *visited, int size);
// int isNotInQueue(int *queue,int,int size);
// void prims(int **adj, int *visited, int start, int size)
// {
//     int row, column, minimum;
//     int mincost = 0, fringevertices = size - 1;
//     int *queue = (int *)malloc(sizeof(int) * size);
//     int rear = -1, front = -1;
//     minimum = getMin(adj[start], visited, size);
//     queue[++rear] = start;
//     visited[start] = 1;
//     while (front != rear)
//     {
//         if (visited[queue[front+1]] > 0 && front >=  0)
//         {
//             front++;
//             continue;
//         }

//         minimum = getMin(adj[queue[++front]], visited, size);
//         printf("%c ---- ", (65 + queue[front]));

//         for (column = 0; column < size; column++)
//         {
//             if (adj[start][column] != INT_MAX && visited[column] == 0)
//             {
//                 if (isNotInQueue(queue,column,size))
//                 {
//                     queue[++rear] = column;
//                 }
//             }

//         }

//         for (row = front; row < rear; row++)
//         {
//             for (column = front; column < rear; column++)
//             {

//                 if (adj[queue[row]][queue[column]] > adj[queue[row]][queue[column + 1]] && adj[queue[row]][queue[column]] != INT_MAX)
//                 {
//                     int temp = queue[column];
//                     queue[column] = queue[column + 1];
//                     queue[column + 1] = temp;
//                 }
//             }
//         }

//         // printf("\nQueue Before sorting : ");
//         // for (size_t i = 0; i < size; i++)
//         // {
//         //     printf("%d,", queue[i]);
//         // }

//         printf("%c", (65 + minimum));
//         printf("\nPath costed : %d", adj[queue[front]][minimum]);

//         mincost += adj[queue[front]][minimum];
//         visited[queue[front]] += 1;

//         start = queue[front+1];

//         // HELPER FOR UNDERSTANDING WORKING
//         printf("\nMatrix : \n");
//         for (size_t i = 0; i < size; i++)
//         {
//             for (size_t j = 0; j < size; j++)
//             {
//                 if (adj[i][j] == INT_MAX)
//                 {
//                     printf("0 ");
//                 }
//                 else
//                 {
//                     printf("%d ", adj[i][j]);
//                 }
//             }
//             printf("\n");
//         }
//         printf("Visited : ");
//         for (size_t i = 0; i < size; i++)
//         {
//             printf("%d,", visited[i]);
//         }
//         printf("\nQueue : ");
//         for (size_t i = 0; i < size; i++)
//         {
//             printf("%d,", queue[i]);
//         }
//         printf("\nFront = %d,Rear = %d\n", front, rear);
//     }
//     printf("Minimum Cost Spanning Tree : %d", mincost);
// }
// int getMin(int *ar, int *visited, int size)
// {
//     int x;
//     int min = 0;

//     for (x = 0; x < size; x++)
//     {
//         if (ar[min] > ar[x] && visited[x] == 0)
//         {
//             min = x;
//         }
//         else if (visited[min] > 1)
//         {
//             min++;
//         }
//     }
//     return min;
// }

// int isNotInQueue(int *queue,int val, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (queue[i] == val)
//         {
//             return 0;
//         }

//     }
//     return 1;
// }

// void main()
// {
//     int size, start;
//     int *visited, **adj, i, j;
//     printf("Enter size : ");
//     scanf("%d", &size);
//     start = 1;
//     // printf("Enter starting vertex : ");
//     // scanf("%d",&start);
//     printf("Enter adjancey Matrix : \n");
//     adj = (int **)malloc(sizeof(int *) * size);
//     visited = (int *)malloc(sizeof(int) * size);
//     for (i = 0; i < size; i++)
//     {
//         adj[i] = (int *)malloc(sizeof(int) * size);
//         for (j = 0; j < size; j++)
//         {
//             scanf("%d", &adj[i][j]);
//             if (adj[i][j] == 0)
//             {
//                 adj[i][j] = INT_MAX;
//             }
//         }
//         visited[i] = 0;
//     }
//     prims(adj, visited, (start - 1), size);
// }

// /* for (column = 0; column < size; column++)
//         {
//             if (adj[row][column] < adj[row][minimum] && visited[column] == 0)
//             {
//                 minimum = column;
//             }
//         }
//         visited[minimum] = 1;
//         mincost += adj[minimum][row];
//         row = minimum;
//         // To-->
//         printf("%c ---- ", (65 + row));
//         fringevertices--; */