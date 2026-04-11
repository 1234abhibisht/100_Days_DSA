#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for Level Order Traversal
struct Node* queue[MAX];
int front = -1, rear = -1;

// Create New Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    
    if (front == -1) front = 0;
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;

    return queue[front++];
}

// Check if Queue is Empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* current = dequeue();
        printf("%d ", current->data);

        if (current->left)
            enqueue(current->left);

        if (current->right)
            enqueue(current->right);
    }
}

// Driver Code
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
