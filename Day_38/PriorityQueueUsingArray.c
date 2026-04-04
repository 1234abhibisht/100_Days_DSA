#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int pq[MAX];
int size = -1;

// Insert element based on priority
void insert(int value)
{
    if (size == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    int i = size;

    // shift elements to maintain priority order (descending)
    while (i >= 0 && pq[i] < value)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

// Delete highest priority element
int delete()
{
    if (size == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return pq[size--];   // last element (highest priority)
}

// Display queue
void display()
{
    if (size == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(30);
    insert(20);
    insert(5);

    display();

    printf("Deleted: %d\n", delete());
    display();

    return 0;
}
