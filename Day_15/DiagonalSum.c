// Problem: Given a matrix, calculate the sum of its primary diagonal elements.
// The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>
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

    // algorithm
    int sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            if (i == j)
            {
                sum = sum + arr[i][i];
            }
        }
    }
    printf("%d", sum);
    return 0;
}
