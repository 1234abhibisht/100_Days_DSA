//Problem: Write a program to perform addition of two matrices having the same dimensions. 
// The sum of two matrices is obtained by adding corresponding elements of the matrices.

#include <stdio.h>
void addTwoMatrices(int n, int arr1[n][n], int arr2[n][n])
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            arr1[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("Sum of two matrices is : \n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    return;
}
int main()
{
    int n;
    printf("Enter row / column of your first and second matrix : ");
    scanf("%d", &n);
    int arr1[n][n];
    printf("Enter your first matrix : \n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    int arr2[n][n];
    printf("Enter your second matrix : \n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    addTwoMatrices(n, arr1, arr2);
    return 0;
}
