// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>
#include <stdbool.h>
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

    int k;
    printf("Enter element to find : ");
    scanf("%d", &k);

    int compare = 0, foundIdx = 0;
    bool check = false;

    for (int i = 0; i <= n - 1; i++)
    {
        compare++;
        if (arr[i] == k)
        {
            check = true;
            foundIdx = i;
        }
    }

    if (check == true)
    {
        printf("Found in index : %d", foundIdx);
    }
    else
    {
        printf("Not found");
    }
    return 0;
}
