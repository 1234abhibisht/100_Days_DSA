#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* node;
    int hd;
} QueueNode;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level-order heap-style array
Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    int vertical[MAX][MAX];
    int count[MAX] = {0};

    int offset = MAX / 2;   // To handle negative HD safely
    int minHD = offset, maxHD = offset;

    QueueNode queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = (QueueNode){root, offset};

    while (front < rear) {
        QueueNode curr = queue[front++];

        vertical[curr.hd][count[curr.hd]++] = curr.node->data;

        if (curr.hd < minHD) minHD = curr.hd;
        if (curr.hd > maxHD) maxHD = curr.hd;

        if (curr.node->left)
            queue[rear++] = (QueueNode){curr.node->left, curr.hd - 1};

        if (curr.node->right)
            queue[rear++] = (QueueNode){curr.node->right, curr.hd + 1};
    }

    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", vertical[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}
