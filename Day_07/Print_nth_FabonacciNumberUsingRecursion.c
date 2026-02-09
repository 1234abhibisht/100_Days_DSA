// Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

#include <stdio.h>
int recursiveFabonacci(int n) {
    if(n == 1 || n == 2) {  // base case
        return 1;
    }
    return recursiveFabonacci(n - 1) + recursiveFabonacci(n - 2);
}
int main() {
    int n;
    printf("Enter value of n : ");
    scanf("%d",&n);
    int ans = recursiveFabonacci(n);
    printf("%d",ans);
    return 0;
}
