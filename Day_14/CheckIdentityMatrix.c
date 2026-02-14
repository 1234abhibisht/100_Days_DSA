// Problem: Write a program to check whether a given square matrix is an Identity Matrix.
// An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    printf("Enter row of your matrix : ");
    scanf("%d", &n);
    int m;
    printf("Enter column of your matrix : ");
    scanf("%d", &m);
    int arr[n][m];
    printf("Enter your matrix : \n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // algoritm
    if (n != m)
    {
        printf("Matrix is not square matrix");
    }
    bool flag = true;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            if (arr[i][i] != 1)
            {
                flag = false;
            }
            if (i != j)
            {
                if (arr[i][j] != 0)
                {
                    flag = false;
                }
            }
        }
    }
    if (flag == false)
    {
        printf("Not identity");
    }
    else
    {
        printf("Identity");
    }
    return 0;
}
