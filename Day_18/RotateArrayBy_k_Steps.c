// rotate array by k steps

#include <stdio.h>
void rotateArray(int arr[], int i, int j)
{
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
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
    int k;
    printf("Enter how many times you want to rotate array : ");
    scanf("%d", &k);
    /* rotate whole array */
    rotateArray(arr, 0, n - 1);
    /* rotate first k elements only */
    rotateArray(arr, 0, k - 1);
    /* rotate remaining elements */
    rotateArray(arr, k, n - 1);
    printf("Array after rotating by %d steps is : ", k);
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
