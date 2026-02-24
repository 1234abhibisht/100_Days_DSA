#include <stdio.h>
int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter array : ");
    int arr[n];
    for(int i = 0; i <= n - 1; i++) {
        scanf("%d",&arr[i]);
    }

    // algorithm
    
    // find maximum element in arr
    int max = arr[0];
    for(int i = 1; i <= n - 1; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // create a new array
    int ans[max + 1];
    for(int i = 0; i <= max; i++) {
        ans[i] = 0;
    }
    for(int i = 0; i <= n - 1; i++) {
        ans[arr[i]]++;
    }

    // output
    for(int i = 0; i <= n - 1; i++) {
        // int check = 0;
        printf("%d : %d, ",arr[i],ans[arr[i]]);
    }
    return 0;
}
