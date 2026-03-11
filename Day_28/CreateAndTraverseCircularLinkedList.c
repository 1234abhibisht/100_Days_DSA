#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // making the list circular
    temp->next = head;

    // traversal
    struct node *ptr = head;

    printf("Circular Linked List:\n");

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    while(ptr != head);

    return 0;
}
