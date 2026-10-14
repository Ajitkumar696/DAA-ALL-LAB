#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node1 {
    int dest;
    struct Node1* next;
} Node1;

typedef struct {
    int V;
    Node1** adj;
    int* color;
} Graph1;

Graph1* createGraph1(int V) {
    Graph1* g = (Graph1*)malloc(sizeof(Graph1));
    g->V = V;
    g->adj = (Node1**)calloc(V, sizeof(Node1*));
    g->color = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) g->color[i] = -1;
    return g;
}

void addEdge1(Graph1* g, int u, int v) {
    Node1* node = (Node1*)malloc(sizeof(Node1));
    node->dest = v;
    node->next = g->adj[u];
    g->adj[u] = node;
}

bool isBipartite1(Graph1* g) {
    for (int i = 0; i < g->V; i++) g->color[i] = -1;
    int* queue = (int*)malloc(g->V * sizeof(int));
    
    for (int i = 0; i < g->V; i++) {
        if (g->color[i] == -1) {
            int front = 0, rear = 0;
            queue[rear++] = i;
            g->color[i] = 0;
            while (front < rear) {
                int curr = queue[front++];
                Node1* temp = g->adj[curr];
                while (temp != NULL) {
                    int neighbor = temp->dest;
                    if (g->color[neighbor] == -1) {
                        g->color[neighbor] = 1 - g->color[curr];
                        queue[rear++] = neighbor;
                    } else if (g->color[neighbor] == g->color[curr]) {
                        free(queue);
                        return false;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    free(queue);
    return true;
}

int main() {
    int V = 4;
    Graph1* g = createGraph1(V);
    addEdge1(g, 0, 1);
    addEdge1(g, 1, 0);
    addEdge1(g, 1, 2);
    addEdge1(g, 2, 1);
    
    if (isBipartite1(g)) {
        printf("Graph is bipartite.\n");
    } else {
        printf("Graph is not bipartite.\n");
    }
    return 0;
}