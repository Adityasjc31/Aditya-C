#include <stdio.h>
#include <stdlib.h>
void display(int **ar, int nodes,int different);
void createGraph(int **ar, int nodes);
int spanningTree(int src, int **tree,int nodes);
void displaySD(int *ar, int nodes);
void main()
{
    int **tree = NULL;
    int nodes = 0, x, y, val;
    char ch;

    printf("Enter number of nodes : ");
    scanf("%d", &nodes);
    tree = (int **)malloc(sizeof(int *) * (nodes));
    for (x = 0; x < (nodes); x++)
    {
        tree[x] = (int *)malloc(sizeof(int) * (nodes));
    }
    // printf("Weighted : \n");
    // display(weight,nodes);
    // printf("Visited : \n");
    // display(visited,nodes);
    createGraph(tree, nodes);
    printf("Matrix : \n");
    display(tree, nodes , nodes);

    printf("Enter source element : ");
    scanf("%c", &ch);
    scanf("%c", &ch);

    spanningTree(65 - ch, tree, nodes);

    printf("Matrix : \n");
    display(tree, nodes,nodes+1);
}

int spanningTree(int src, int **tree, int nodes)
{
    int x;
    int **visited =(int **) malloc(sizeof(int*) * (nodes));
    int different = 1;
    for (x = 0; x <=nodes; x++)
    {
        visited[x] = (int *)malloc(sizeof(int) * (nodes + 1));
    }
}

void displaySD(int *ar, int nodes)
{
    int x, y;
    for (x = 0; x < (nodes); x++)
    {
        
        printf("%d\t", ar[x]);
    }
    printf("\n");
}

void display(int **ar, int row,int col)
{
    int x, y;
    for (x = 0; x < row; x++)
    {
        for (y = 0; y < col; y++)
        {
            printf("%d\t", ar[x][y]);
        }
        printf("\n");
    }
}
void createGraph(int **ar, int nodes)
{
    int x, y, val;
    printf("Enter connections : \n");
    for (x = 0; x < (nodes); x++)
    {
        printf("%c : \n", (x + 65));
        printf("Enter the connections of %d in 1-D Array : ");
        for (y = 0; y < nodes; y++)
        {
            scanf("%d", &val);
            ar[x][y] = val;
        }
    }
}