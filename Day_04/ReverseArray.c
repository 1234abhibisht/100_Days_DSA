// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>
void reverseArray(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
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
    reverseArray(arr, n);
    for(int i = 0; i <= n - 1; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
