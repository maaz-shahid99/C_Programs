//N-QUEEN ALGORITHM

#include <stdio.h>
#include <stdlib.h>

int *x; //array to store column position of each queen in each row

//utility function to check whether the kth queen can be placed at ith column without conflicting with the previous j queens
int isValid(int k, int i)
{
    int j;

    for(j=1; j<k; j++)
    {
        if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
            return 0;
    }

    return 1;
}

//utility function to print all the possible solutions to place N queens
void printSolution(int n)
{
    int i;
    for(i=1; i<=n; i++)
        printf("%d ", x[i]); //displays the x[i]th column where the ith queen is placed
    printf("\n");
}

//utility function to solve N-Queen problem using backtracking
void nQueen(int k, int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        if(isValid(k, i))
        {
            x[k] = i;
            if(k==n)
                printSolution(n);

            else 
                nQueen(k+1, n);
        }
        
    }
}

//driver code
int main(void)
{
    int n;
    scanf("%d", &n);

    x = (int*)malloc(n*sizeof(int));

    nQueen(1, n);
    return 0;
}