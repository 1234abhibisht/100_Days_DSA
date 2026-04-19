#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;

    int leftToRight = 1;

    while (f < r) {
        int size = r - f;

        int level[100];

        // store current level
        for (int i = 0; i < size; i++) {
            struct Node* temp = q[f++];
            level[i] = temp->data;

            if (temp->left) q[r++] = temp->left;
            if (temp->right) q[r++] = temp->right;
        }

        // print based on direction
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
