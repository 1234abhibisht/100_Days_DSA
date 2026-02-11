// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    // input
    char str1[100];
    printf("Enter string : ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    int idx = 0;
    int sizeStr1 = 0;
    while (str1[idx] != '\0')
    {
        sizeStr1++;
        idx++;
    }

    // copying string to another to check later
    int checkStr[100];
    for (int i = 0; i <= sizeStr1 - 1; i++)
    {
        checkStr[i] = str1[i];
    }

    // checking pallindrome
    int i = 0;
    int j = sizeStr1 - 1;
    while (i < j)
    {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
        i++;
        j--;
    }
    bool flag = true;
    for (int i = 0; i <= sizeStr1 - 1; i++)
    {
        if (str1[i] != checkStr[i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        printf("Pallindrome");
    }
    else
    {
        printf("Not Pallindrome");
    }
    return 0;
}
