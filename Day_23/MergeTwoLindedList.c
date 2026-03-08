#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
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

    return head;
}

struct Node *mergeLists(struct Node *head1, struct Node *head2)
{
    struct Node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n1, n2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    struct Node *head1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    struct Node *head2 = createList(n2);

    struct Node *merged = mergeLists(head1, head2);

    printf("Merged Linked List:\n");
    display(merged);

    return 0;
}
