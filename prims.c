// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int selectMinVertex(int *value, bool *setMST, int v)
{
    int minimum = INT_MAX;
    int vertex;
    
    for(int i=0; i<v; i++)
    {
        if(setMST[i]==false && value[i]<minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void findMST(int **graph, int n)
{
    int i,j;
    
    int *parent = (int*)malloc(n*sizeof(int));
    int *value = (int*)malloc(n*sizeof(int));
    bool *setMST = (bool*)malloc(n*sizeof(bool));
    
    for(i=0; i<n; i++)
    {
        parent[i]=0;
        value[i]=INT_MAX;
        setMST[i]=false;
    }
    
    parent[0]=-1;
    value[0]=0;
    
    for(i=0; i<n-1;i++)
    {
        int U = selectMinVertex(value, setMST, n);
        setMST[U]=true;
        
        for(j=0; j<n; j++)
        {
            if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
            {
                value[j]=graph[U][j];
                parent[j]=U;
            }
        }
    }
    
    //print MST

    for(i=0; i<n; i++)
    {
        printf("U->V: %d -> %d\t%d\n",parent[i] ,i ,graph[i][parent[i]]);
    }
    for(i=0; i<n; i++)
    printf("%d ",parent[i]);
}

int main() {
    // Write C code here
        int n, i, j;
    scanf("%d", &n); //accepting number of vertices
     
    int **graph = (int**)malloc(n*sizeof(int*)); //create 2D array to store adjacency matrix
     
    for(i=0; i<n; i++)
    graph[i] = (int*)malloc(n*sizeof(int));
        
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
            
        }
    }
    
    findMST(graph, n);
    return 0;
}