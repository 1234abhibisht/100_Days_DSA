#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of integers : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    // algorithm
    int count = 0, i = 0, j = 0, sum = arr[0];
    while (j <= n - 1)
    {
        while (sum > 0 && i < j)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == 0)
        {
            count++;
        }
        j++;
        if (j <= n - 1)
        {
            sum += arr[j];
        }
    }
    printf("%d", count);
    return 0;
}
