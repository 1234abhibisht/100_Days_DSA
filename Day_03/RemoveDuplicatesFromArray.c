// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array : ");
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    // algorithm
    int i = 0;
    int j = i + 1;
    while (j <= n - 1)
    {
        if (arr[i] == arr[j])
        {
            j++;
        }
        else
        {
            arr[i + 1] = arr[j];
            i++;
            j++;
        }
    }

    // output
    for (int x = 0; x <= i; x++)
    {
        printf("%d ", arr[x]);
    }
    return 0;
}
