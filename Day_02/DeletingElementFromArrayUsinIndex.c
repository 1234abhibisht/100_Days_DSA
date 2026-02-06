// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

#include <stdio.h>
void deleteElement(int arr[], int n, int idx)
{
    for (int i = idx + 1; i <= n - 1; i++)
    {
        arr[i - 1] = arr[i];
    }

    return;
}
int main()
{
    int n;
    printf("Enter how many elements you want to enter : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array : ");
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int idx;
    printf("Enter the index from which you want to delete the element : ");
    scanf("%d", &idx);
    deleteElement(arr, n, idx);
    printf("Updated array is : ");
    for (int i = 0; i <= n - 2; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
