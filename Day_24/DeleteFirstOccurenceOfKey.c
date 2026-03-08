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

    for (int i = 0; i < n; i++)
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

struct Node *deleteFirstOccurrence(struct Node *head, int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == key)
        {

            if (prev == NULL)
            { // deleting head node
                head = temp->next;
            }
            else
            { // deleting middle or last node
                prev->next = temp->next;
            }

            free(temp);
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found\n");
    return head;
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
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createList(n);

    printf("Linked List: ");
    display(head);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printf("Updated List: ");
    display(head);

    return 0;
}
