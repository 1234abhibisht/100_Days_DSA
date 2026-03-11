#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int getLength(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node* findIntersection(struct node *head1, struct node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    if (len1 > len2)
    {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    }
    else
    {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    /* example intersection creation */

    struct node *common = malloc(sizeof(struct node));
    common->data = 30;
    common->next = malloc(sizeof(struct node));
    common->next->data = 40;
    common->next->next = NULL;

    head1 = malloc(sizeof(struct node));
    head1->data = 10;
    head1->next = malloc(sizeof(struct node));
    head1->next->data = 20;
    head1->next->next = common;

    head2 = malloc(sizeof(struct node));
    head2->data = 15;
    head2->next = common;

    struct node *result = findIntersection(head1, head2);

    if (result)
        printf("Intersection at node with data %d", result->data);
    else
        printf("No intersection");

    return 0;
}
