#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



//utility function for optimal parenthization
void opt_parens(int **s, int i, int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        opt_parens(s, i, s[i][j]);
        opt_parens(s, s[i][j]+1, j);
        printf(")");
    }
}





void matrixChainOrder(int *p, int n)
{
    int i, j, k, l, cost;

    int **m = (int **)malloc(n * sizeof(int *)); // Matrix m contains minimum number of scaler multiplication steps needed.
    int **s = (int **)malloc(n * sizeof(int *)); // Matrix s contains the indexes of K which acheived optimal solution on computing m[i][j].

    for (i = 0; i <= n; i++)
    {
        m[i] = (int *)malloc(n * sizeof(int));
        s[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int d = 1; d < n - 1; d++)
    {

        for (int i = 1; i < n - d; i++)
        {

            j = i + d;
            int min = INT_MAX;

            for (int k = 1; k < j - 1; k++)
            {

                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j + 1];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }


	
    
    //display cost matrix
    printf("\n");
    for(i=1; i<n; i++)
    {
        for(j=i; j<n; j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    printf("\n");

	//display matrix order table
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<n; j++)
            printf("%d ",s[i][j]);
        printf("\n");
    }

    opt_parens(s, 1, n-1);	//optimal parenthization
    printf("\n\n");
    printf("%d\n", m[1][n-1]); //optimal cost



}




int main(void)
{
    int i, n;

    scanf("%d", &n);
    n++;

    int *arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    matrixChainOrder(arr, n);

    return 0;
}
