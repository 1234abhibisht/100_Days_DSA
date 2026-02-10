// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>
int aPowb(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    int x;
    if (power % 2 == 0)
    {
        x = aPowb(base, power / 2) * aPowb(base, power / 2);
    }
    else
    {
        x = base * aPowb(base, power / 2) * aPowb(base, power / 2);
    }
    return x;
}
int main()
{
    int base;
    printf("Enter base : ");
    scanf("%d", &base);
    int power;
    printf("Enter power : ");
    scanf("%d", &power);
    printf("%d", aPowb(base, power));
    return 0;
}
