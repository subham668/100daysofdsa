#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = newNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

void dfs(int v, int visited[], int stack[], int *top, struct Graph* graph) {
    visited[v] = 1;
    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, visited, stack, top, graph);
        temp = temp->next;
    }
    stack[++(*top)] = v;
}

void topoSort(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = -1;

    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            dfs(i, visited, stack, &top, graph);

    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topoSort(graph);

    return 0;
}