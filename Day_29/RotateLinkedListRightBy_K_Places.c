#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* rotateRight(struct node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node *temp = head;
    int length = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;
    struct node *newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct node *newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, x, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &x);

        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL)
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

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated list: ");
    display(head);

    return 0;
}
