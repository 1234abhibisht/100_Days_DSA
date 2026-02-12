/* a matrix is symmetric if it is equal to its transpose
   but to check symmetric matrix we have to check if each arr[i][j] = arr[j][i], if one of
    arr[i][j] != arr[j][i], then matrix is not symmetric */

#include <stdio.h>
#include <stdbool.h>
void symmetricCheck(int n, int arr[n][n])
{
    bool flag = true;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag == false)
    {
        printf("Matrix is not symmetric\n");
    }
    else
    {
        printf("Matrix is symmetric\n");
    }
}
int main()
{
    int n;
    printf("Enter row/column of your square matrix : ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter your matrix : \n");
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    symmetricCheck(n, arr);
    return 0;
}
