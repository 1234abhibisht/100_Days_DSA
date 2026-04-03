#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue (create queue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;

    // First node
    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;   // circular link
    } 
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;      // maintain circular property
    }
}
