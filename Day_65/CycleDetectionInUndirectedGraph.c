#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS cycle detection
int dfsCycle(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];

    while (temp) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (dfsCycle(graph, adj, v))
                return 1;
        }
        else if (adj != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// Check entire graph
int hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (dfsCycle(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
