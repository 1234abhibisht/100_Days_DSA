#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int countOccurrence(struct Node *head, int key)
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    int n, i, key;
    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    int result = countOccurrence(head, key);

    printf("Occurrence of %d = %d\n", key, result);

    return 0;
}
