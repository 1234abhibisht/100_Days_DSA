// Problem: A system receives two separate logs of user arrival times from two different servers. 
//Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>
int main()
{
    int log1;
    printf("Enter number of entries in log1 : ");
    scanf("%d", &log1);
    int arrLog1[log1];
    printf("Enter entries for log1 in sorted order : ");
    for (int i = 0; i <= log1 - 1; i++)
    {
        scanf("%d", &arrLog1[i]);
    }
    int log2;
    printf("Enter number of entries in log2 : ");
    scanf("%d", &log2);
    int arrLog2[log2];
    printf("Enter entries for log2 in sorted order : ");
    for (int i = 0; i <= log2 - 1; i++)
    {
        scanf("%d", &arrLog2[i]);
    }

    // algorithm

    int arrResult[log1 + log2];
    int idx = 0;
    int i = 0;
    int j = 0;
    while (i <= log1 - 1 && j <= log2 - 1)
    {
        if (arrLog1[i] < arrLog2[j])
        {
            arrResult[idx] = arrLog1[i];
            i++;
            idx++;
        }
        else
        {
            arrResult[idx] = arrLog2[j];
            j++;
            idx++;
        }
    }
    while (i <= log1 - 1)
    {
        arrResult[idx] = arrLog1[i];
        i++;
        idx++;
    }
    while (j <= log2 - 1)
    {
        arrResult[idx] = arrLog2[j];
        j++;
        idx++;
    }

    // output
    for (int i = 0; i <= idx - 1; i++)
    {
        printf("%d ", arrResult[i]);
    }
    return 0;
}
