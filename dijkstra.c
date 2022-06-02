#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


int selectMinVertex(int *edgeCost, bool *processed, int n)
{
    int minimum = INT_MAX;
	int vertex;
	for(int i=0; i<n; ++i)
	{
		if(processed[i]==false && edgeCost[i]<minimum)
		{
			vertex = i;
			minimum = edgeCost[i];
		}
	}
	return vertex;
}


void dijkstra(int **graph, int n)
{
    int *parent = (int*)malloc(n*sizeof(int));
    int *edgeCost = (int*)malloc(n*sizeof(int));
    bool *processed = (bool*)malloc(n*sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        edgeCost[i] = INT_MAX;
        processed[i] = false;
    }

    parent[0] = -1;
    edgeCost[0] = 0;

    for(int i= 0; i< n-1; i++)
    {

        int U = selectMinVertex(edgeCost, processed, n);
        processed[U] = true;
            

        for (int j = 0; j < n; j++)
        {
            if(graph[U][j]!=INT_MAX && processed[j]==false && edgeCost[U]!=INT_MAX && (edgeCost[U]+graph[U][j] < edgeCost[j]))
            {
				edgeCost[j] = edgeCost[U] + graph[U][j];
				parent[j] = U;
			}
        }
        
    }

    for(int i=1; i<n; ++i)
    {
        printf("%d\t%d\t%d\n",parent[i], i, graph[parent[i]][i]);
    }

    
}



int main(void)
{
        int n, i, j;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);
     
    int **cost = (int**)malloc(n*sizeof(int*));
     
    for(i=0; i<n; i++)
    cost[i] = (int*)malloc(n*sizeof(int));
    
    printf("Enter the cost matrix:-\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j] = INT_MAX;
        }
    }
    
    
    dijkstra(cost, n);
    
    return 0;
}