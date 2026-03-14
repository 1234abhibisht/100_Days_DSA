#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node* createPolynomial(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++)
    {
        newNode = malloc(sizeof(struct node));

        printf("Enter coefficient: ");
        scanf("%d", &newNode->coef);

        printf("Enter exponent: ");
        scanf("%d", &newNode->exp);

        newNode->next = NULL;

        if(head == NULL)
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

void display(struct node *head)
{
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf("%dx^%d", ptr->coef, ptr->exp);

        if(ptr->next != NULL)
            printf(" + ");

        ptr = ptr->next;
    }
}

int main()
{
    int n;

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    struct node *poly = createPolynomial(n);

    printf("Polynomial:\n");
    display(poly);

    return 0;
}
