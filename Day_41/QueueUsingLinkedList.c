#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Create empty queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue (Insert at rear)
void enqueue(struct Queue* q, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }

    // Link new node at the end
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue (Remove from front)
int dequeue(struct Queue* q)
{
    if (q->front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    // If queue becomes empty
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Display queue
void display(struct Queue* q)
{
    struct Node* temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main()
{
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue:\n");
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    printf("Queue after dequeue:\n");
    display(q);

    return 0;
}
