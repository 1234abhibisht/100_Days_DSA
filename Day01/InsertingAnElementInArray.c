// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>
int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter a sorted array : ");
    for(int i = 0; i <= n - 1; i++) {
        scanf("%d",&arr[i]);
    }
    int ele;
    printf("Enter element to insert : ");
    scanf("%d",&ele);
    
    for(int i = n - 1; i >= 0; i--) {
        if(ele < arr[i]) {
            arr[i + 1] = arr[i];
        }
        else if(ele > arr[i]) {
            arr[i + 1] = ele;
            break;
        }
    } 

    if(arr[0] == arr[1]) {  // to insert element at first position
        arr[0] = ele;
    }

    for(int i = 0; i <= n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
