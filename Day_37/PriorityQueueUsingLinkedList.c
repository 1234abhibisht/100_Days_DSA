#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Insert (enqueue with priority)
void enqueue(int value, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // Insert at beginning
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } 
    else {
        struct Node* temp = front;

        // find position
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Inserted: %d (priority %d)\n", value, priority);
}
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    while (temp != NULL) {
        printf("[Data:%d Priority:%d] ", temp->data, temp->priority);
        temp = temp->next;
    }

    printf("\n");
}
int main() {
    int value, priority;  
    printf("Enter value and priority: ");
    scanf("%d %d", &value, &priority);            
    enqueue(value, priority);
    display();
}
