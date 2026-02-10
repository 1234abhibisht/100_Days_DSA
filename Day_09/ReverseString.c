// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>
int main()
{

    // input
    char str[100];
    printf("Enter string : ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int size = 0;
    int idx = 0;
    while (idx != '\0')
    {
        size++;
        idx++;
    }

    // algorithm
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    // output
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}
