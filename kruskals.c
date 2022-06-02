// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int src;
    int dest;
    int wt;
} ed;




void sort(ed *input, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (input[j].wt > input[j + 1].wt)
            {
                ed *temp = (ed *)malloc(sizeof(ed));
                temp->src = input[j].src;
                temp->dest = input[j].dest;
                temp->wt = input[j].wt;

                input[j].src = input[j + 1].src;
                input[j].dest = input[j + 1].dest;
                input[j].wt = input[j + 1].wt;

                input[j + 1].src = temp->src;
                input[j + 1].dest = temp->dest;
                input[j + 1].wt = temp->wt;
            }
        }
    }


}




int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}





void kruskals(ed *input, int v, int x)
{

    sort(input, x); //call sort func to sort array in ascending order

    ed *output = (ed *)malloc((x - 1) * sizeof(ed));
    int *parent = (int *)malloc(v * sizeof(int));

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0, i = 0;

    while (count != v - 1)
    {
        ed *currentEdge = (ed *)malloc(sizeof(ed));
        currentEdge->src = input[i].src;
        currentEdge->dest = input[i].dest;
        currentEdge->wt = input[i].wt;

        // Check if current edge can be added to MST or not.
        int sourceParent = findParent(currentEdge->src, parent);
        int destinationParent = findParent(currentEdge->dest, parent);

        if (sourceParent != destinationParent)
        {
            output[count] = *currentEdge;
            parent[sourceParent] = destinationParent;
            count++;
        }
        i++;

        free(currentEdge);
    }

    //print MST

    for(int i=0; i< v-1; i++)
    {
        if(output[i].src < output[i].dest)
        {
            printf("%d\t%d\t%d\n", output[i].src, output[i].dest, output[i].wt);
        }

        else
        {
            printf("%d\t%d\t%d\n", output[i].dest, output[i].src, output[i].wt);
        }
    }

}





int main()
{

    int i, j, v, e, x = 0;

    printf("Enter the number of vertices:-\n");
    scanf("%d", &v);

    printf("Enter the number of edges:-\n");
    scanf("%d", &e);

    ed *input = (ed *)malloc(e * sizeof(ed));

    int **cost = (int **)malloc(v * sizeof(int *));

    for (i = 0; i < v; i++)
        cost[i] = (int *)malloc(v * sizeof(int));

    printf("Enter the cost matrix:-\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (i != j && cost[i][j] != 0)
            {
                input[x].src = i;
                input[x].dest = j;
                input[x].wt = cost[i][j];
                x++;
            }
        }
    }

    kruskals(input, v, x);

    return 0;
}