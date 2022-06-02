#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int x=0;


void TSP(int **graph, int n, int start)
{
    int *visited = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
        visited[i] = INT_MAX;

    visited[start] = 0;

    while(x!=4)
    {
        int nextNode = findNextNode(visited);
        visited[nextNode] = graph[start][nextNode];
        start = nextNode;
        x++;
    }
}



int main()
{
    int n, start;

    printf("Enter no of vertices\n");
    scanf("%d", &n);

    int **graph = (int**)malloc(n*sizeof(int*));


    for(int i=0; i<n; i++)
        graph[i] = (int*)malloc(n*sizeof(int));


    printf("Enter Cost matrix\n");
    for (int i = 0; i < n; i++)
    {

        for (int k = 0; k < n; k++)
            scanf("%d", &graph[i][k]);
        
    }

    printf("Enter starting vertex\n");
    scanf("%d", &start);
    
    TSP(graph, n, start);

    return 0;
}